#include "functions.h"

union float_32 float_32;

void print_mant(char bit_string[]) {
  for(int a = 12; a < 40; a++) {
    printf("%c", bit_string[a]);
  }
    printf("\n"); 
}

void print_exp(char bit_string[]) {
  for(int a = 2; a < 11; a++) {
    printf("%c", bit_string[a]);
  }

  printf("\n");
}
    // Main output function
void print_output(char bit_string[]) {

  // This should be the "sign"
  bit_string[0] = float_32.bit.b31?'1':'0';

  // The gaps here will be "spaces", that is #1, #6, #11, #15, #20, #25, #30, #35.

  // The Exponent should start here
  bit_string[2] = float_32.bit.b30?'1':'0';
  bit_string[3] = float_32.bit.b29?'1':'0';
  bit_string[4] = float_32.bit.b28?'1':'0';
  bit_string[5] = float_32.bit.b27?'1':'0';

  bit_string[7] = float_32.bit.b26?'1':'0';
  bit_string[8] = float_32.bit.b25?'1':'0';
  bit_string[9] = float_32.bit.b24?'1':'0';
  bit_string[10] = float_32.bit.b23?'1':'0';    // Last bit of the exponent.

  // The Mantissa should start here.
  bit_string[12] = float_32.bit.b22?'1':'0';
  bit_string[13] = float_32.bit.b21?'1':'0';
  bit_string[14] = float_32.bit.b20?'1':'0';

  bit_string[16] = float_32.bit.b19?'1':'0';
  bit_string[17] = float_32.bit.b18?'1':'0';
  bit_string[18] = float_32.bit.b17?'1':'0';
  bit_string[19] = float_32.bit.b16?'1':'0';

  bit_string[21] = float_32.bit.b15?'1':'0';
  bit_string[22] = float_32.bit.b14?'1':'0';
  bit_string[23] = float_32.bit.b13?'1':'0';
  bit_string[24] = float_32.bit.b12?'1':'0';

  bit_string[26] = float_32.bit.b11?'1':'0';
  bit_string[27] = float_32.bit.b10?'1':'0';
  bit_string[28] = float_32.bit.b9?'1':'0';
  bit_string[29] = float_32.bit.b8?'1':'0';

  bit_string[31] = float_32.bit.b7?'1':'0';
  bit_string[32] = float_32.bit.b6?'1':'0';
  bit_string[33] = float_32.bit.b5?'1':'0';
  bit_string[34] = float_32.bit.b4?'1':'0';

  bit_string[36] = float_32.bit.b3?'1':'0';
  bit_string[37] = float_32.bit.b2?'1':'0';
  bit_string[38] = float_32.bit.b1?'1':'0';
  bit_string[39] = float_32.bit.b0?'1':'0';

printf("\nthe floating value for %g is broken out as: \n", float_32.floating_value_in_32_bits);

printf("   mantissa: 0x%-11x or: %12s", float_32.f_bits.mantissa, "");
print_mant(bit_string);

printf("   exponent: 0x%-11x or: %2s", float_32.f_bits.exponent, "");
print_exp(bit_string);

printf("       sign: %-13x or: %x\n", float_32.f_bits.sign, float_32.f_bits.sign);

printf(" in base 10: %-13.6g or: %s\n\n", float_32.floating_value_in_32_bits, bit_string);
}
