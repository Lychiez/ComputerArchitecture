#include "functions.h"

int main() {

  int input = 1;
  char bit_string[43];  // Will contain the binary "bit string"

  for(int i = 0; i < 42; i++) {
      bit_string[i] = ' ';      // Set bit string to empty.
  }

  bit_string[42] = '\0';        // Null terminated C style string.

  // Get input until input stops. scanf will return 1 if it gets a valid input,
  // 0 if it gets invalid input and -1 on EOF.
  while (input == 1) {
      printf("Please enter a floating point number and new-line: ");
      input = scanf("%g", &float_32.floating_value_in_32_bits);

      // Make sure the user didn't enter invalid input.
      // scanf will return 0 if it gets invalid input and -1 on EOF.
      if (input == 0 || input == -1) {
          break;
      }

      // Output values to the screen.
      print_output(bit_string);
  }

  return 0;
}
