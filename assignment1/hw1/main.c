#include "functions.h"

int main() {

    int input = 1;        // Set to 1 enter while loop
    int counter = 0;      // Keeps track of how many floats have been entered by user
    char bit_string[43];  // Declare a binary bit string

    for(int i = 0; i < 42; i++) {     // Initialize bit string with empty values
        bit_string[i] = ' ';      
    }
    bit_string[42] = '\0';            // Null terminate strings for C

    // Get user input for values to convert
    while (input == 1) {
    //    printf("Please enter a floating point number and new-line: ");
        input = scanf("%g", &float_32.floating_value_in_32_bits);

    // Checks for valid input from user (scanf returns 0 for nothing and -1 for EOF)
    if (input == 0 || input == -1) {
        break;
    }

    // Output values to the screen.
    print_output(bit_string);

    counter++;
    
    // Ends program after 10 floats entered by user as specified
    if (counter == 10) {
        break;
    }
    }

    return 0;
}
