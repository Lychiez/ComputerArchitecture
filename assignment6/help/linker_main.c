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
void  generate_code(int);
void  print_first_pass(int);
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
// with filename /tmp/bill<rand_num_value>, such as /tmp/bill3789

        gettimeofday (&randtime, (struct timezone *)0);
        srandom((unsigned int)randtime.tv_usec);
        sprintf(temp_file, "/tmp/bill%d", (unsigned int)random()%10000);

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

