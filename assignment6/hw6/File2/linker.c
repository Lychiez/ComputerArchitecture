/**** This is the Mic-1 linker ****/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/time.h>

#define HEADERS         1
#define NO_HEADERS      0

typedef struct nament{
        char   name[26];
        int    addr;
        struct nament *next;
}SYMTABENTRY;


void  add_symbol(char * symbol, int line_number);
int   get_sym_val(char *symbol);
void  generate_code(int linum);
void  print_first_pass(int headers);
void  append_table(void);
void  dump_table(void);


SYMTABENTRY *symtab = NULL;
FILE  *p1, *p2;
char  cstr_12[13];

int main(int argc, char *argv[])
{
	int  i, start, pc_offset=0, pc=0;
	int  linum=0, object_file=0, dump_tab=0;
        int  line_number, new_pc;
        struct timeval randtime;
	char instruction[18];
	char symbol[26], temp_file[20];

// check if cmd includes option arg -o or -s
// if option arg, begin filenames at argv[2], else argv[1]

        if(argc > 1 && (strcmp(argv[1], "-s") == 0)) dump_tab = linum = 1;
        else if(argc > 1 && (strcmp(argv[1], "-o") == 0)) object_file = 1;

	if(dump_tab == 1 | object_file == 1)start=2;
	else start = 1; 

// get timeval, use usec for random seed, create file in /tmp
// with filename /tmp/ally<rand_num_value>, such as /tmp/ally3789

        gettimeofday (&randtime, (struct timezone *)0);
        srandom((unsigned int)randtime.tv_usec);
        sprintf(temp_file, "/tmp/ally%d", (unsigned int)random()%10000);

// immediately remove filename in /tmp, have open file descriptor for access

        p1 = fopen(temp_file, "w+");
        unlink(temp_file);

// begin reading object files, read for argc files

	for(i=start; i<argc; ++i){
		if((p2 = fopen(argv[i], "r")) == NULL){
		  printf("ERROR: cannot open file %s\n", argv[i]);
		  exit(6);
		}

// all lines in object file has at least 2 fields, pc and instruction

		while(fscanf(p2,"%d %s", &pc, instruction) != EOF){

// if the pc field is 4096, this is the end of instructions
// so break from this for loop

		  if(pc == 4096)break;

// this is a valid pc and instruction value, check for "un-cooked"

		  new_pc = pc + pc_offset;
		  symbol[0] = '\0';

// if un-cooked instruction, scan third field, the label dependency

		  if(instruction[0] == 'U'){
            	    fscanf(p2, "%s", symbol);
		  }

// write the updated pc and the instruction with r without symbol to tmp file

		  fprintf(p1, "  %d  %s  %s\n", new_pc, instruction, symbol);
		}

// if here, ready to begin symbol table processing
// take symbol, increment its location value by pc_offset link to symbol table

		while(fscanf(p2,"%s %d",symbol, &line_number) != EOF){
		  add_symbol(symbol, line_number+pc_offset);
		}

// update pc_offset, close current object file, continue to next object file

		pc_offset = new_pc + 1;
		fclose(p2);
	}

// done with object files, all in big tmp file
// check if we want to write an object output or an executable output

// if object file output, print content of big tmp file
// append the big symbol table and linking is complete

	if(object_file){
     		print_first_pass(NO_HEADERS);
     		append_table();
     		return 0;
   	}
   	if(linum){
     		print_first_pass(HEADERS);
   	}

// if an executable output, generate code from big tmp file
// produce executable file and linking is complete  

   	generate_code(linum);
   	if(dump_tab)dump_table();

   	return 0;
}

void  add_symbol(char * symbol, int line_number)
{
    SYMTABENTRY *newSymbol;

    newSymbol = (SYMTABENTRY *) malloc (sizeof (SYMTABENTRY));

    /* Have symtab point to the newest symbol */
    if(symtab == NULL){
        symtab = newSymbol;
        newSymbol -> next = NULL;
    } 
    else {
        newSymbol -> next = symtab;
        symtab = newSymbol;
    }

    strcpy(newSymbol -> name, symbol);
    newSymbol -> addr = line_number;

    return; 
}

int   get_sym_val(char *symbol)
{
    int cmp;
    SYMTABENTRY *list = symtab;

    while(list != NULL) {
        cmp = strcmp(list -> name, symbol);
        if(cmp == 0){
            return list -> addr;
        } 
        else {
            list = list -> next;
        }
    }
    return -1;
}
void  generate_code(int linum)
{
    	char linbuf[10];
	char instruction[18];
	int  line_number;
	int  pc, mask, sym_val,i, j, old_pc, diff;
	char symbol[26];

	line_number = old_pc = 0;
	rewind(p1);

	sprintf(linbuf,"%5d:  ", line_number);

	while(fscanf(p1,"%d %s", &pc, instruction) != EOF){
	if((diff = pc - old_pc ) > 1){
	  for(j=1; j<diff; j++){
		sprintf(linbuf,"%5d:  ", line_number++);
		printf("%s1111111111111111\n",(linum ? linbuf: "\0"));
	  }
	}
	sprintf(linbuf,"%5d:  ", line_number++);
	old_pc = pc;

	 if(instruction[0] == 'U'){
	   fscanf(p1, "%s", symbol);
	   if((sym_val = get_sym_val(symbol)) == -1){
		fprintf(stderr, "no symbol in symbol table: %s\n", symbol);
		exit(27);
	   }
	   	
           for(i=0; i<12; i++){
	     cstr_12[i] = '0';
	   }
	   cstr_12[12] = '\0';
         
	   mask = 2048;
           for(i=0; i<12; i++){
	      if(sym_val & mask)
		  cstr_12[i] = '1';
	      mask >>= 1;
	   }
	   for(i=0; i<12; i++){
		instruction[i+5] = cstr_12[i];
	   }
	   printf("%s%s\n",(linum ? linbuf: "\0"),&instruction[1]);
	 }else
	   printf("%s%s\n",(linum ? linbuf: "\0"),instruction);
	}
	fclose(p1);
}
void  print_first_pass(int headers)
{
    char inbuf[81];

    if(headers == HEADERS){
        printf("\n  FIRST PASS \n");
        rewind(p1);
        while(fgets(inbuf, 80, p1) != NULL){
            printf("   %s", inbuf);
        }
        printf("\n  SECOND PASS \n");
    }else{
        rewind(p1);
        while(fgets(inbuf, 80, p1) != NULL){
            printf("   %s", inbuf);
        }
    }
}
void  append_table(void)
{
    struct nament *list;

    printf("  %d %s\n", 4096, "x");
    for(list = symtab; list != NULL; list = list->next){
        printf("    %-25s %4d\n",list->name, list->addr);
    }
}
void  dump_table(void)
{
 	FILE *fd;
	struct nament *list;
	fd = popen("sort +0 -1 -f", "w");
	printf("***********************************************\n");
        for(list = symtab; list != (struct nament *)0; list = list->next){
		fprintf(fd,"%-25s %4d\n",list->name, list->addr);
	}
	fclose(fd);
	wait(NULL);
	printf("***********************************************\n");   
}