// File to hold all definitions of functions
#include "functions.h"

void print_binary(float_32 output)
{
    char bit_string[43];

    for (int i = 0; i < 42; i++) {
        bit_string[i] = ' ';
    }

    bit_string[42] = '\0';

    // Sign bit printed out first
    bit_string[0] = output.bit.b31 ? '1' : '0';

    // Every 4 bits are represented and spaced out to add clarity
    // Beginning of Exponent
    bit_string[2] = output.bit.b30 ? '1' : '0';
    bit_string[3] = output.bit.b29 ? '1' : '0';
    bit_string[4] = output.bit.b28 ? '1' : '0';
    bit_string[5] = output.bit.b27 ? '1' : '0';

    bit_string[7] = output.bit.b26 ? '1' : '0';
    bit_string[8] = output.bit.b25 ? '1' : '0';
    bit_string[9] = output.bit.b24 ? '1' : '0';
    bit_string[10] = output.bit.b23 ? '1' : '0';

    // Beginning of Mantissa
    bit_string[12] = output.bit.b22 ? '1' : '0';
    bit_string[13] = output.bit.b21 ? '1' : '0';
    bit_string[14] = output.bit.b20 ? '1' : '0';

    bit_string[16] = output.bit.b19 ? '1' : '0';
    bit_string[17] = output.bit.b18 ? '1' : '0';
    bit_string[18] = output.bit.b17 ? '1' : '0';
    bit_string[19] = output.bit.b16 ? '1' : '0';

    bit_string[21] = output.bit.b15 ? '1' : '0';
    bit_string[22] = output.bit.b14 ? '1' : '0';
    bit_string[23] = output.bit.b13 ? '1' : '0';
    bit_string[24] = output.bit.b12 ? '1' : '0';

    bit_string[26] = output.bit.b11 ? '1' : '0';
    bit_string[27] = output.bit.b10 ? '1' : '0';
    bit_string[28] = output.bit.b9 ? '1' : '0';
    bit_string[29] = output.bit.b8 ? '1' : '0';

    bit_string[31] = output.bit.b7 ? '1' : '0';
    bit_string[32] = output.bit.b6 ? '1' : '0';
    bit_string[33] = output.bit.b5 ? '1' : '0';
    bit_string[34] = output.bit.b4 ? '1' : '0';

    bit_string[36] = output.bit.b3 ? '1' : '0';
    bit_string[37] = output.bit.b2 ? '1' : '0';
    bit_string[38] = output.bit.b1 ? '1' : '0';
    bit_string[39] = output.bit.b0 ? '1' : '0';

    printf("%s\n", bit_string); // Print out the bit string.
}