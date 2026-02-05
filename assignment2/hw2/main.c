#include "functions.h"

int main()
{
    float float1, float2, hardware, emulated;
    union float_32 float_1, float_2, hardware_32, emulated_32;
    int valid = 1;

    printf("************************************************************************\n");
    printf("This program will emulate the addition of two IEEE 754 floating point numbers\n\n");

    while(valid == 1) {

    // Boilerplate text
    printf("Please enter two positive floating point values each with:\n");
    printf("    - no more than 6 significant digits\n");
    printf("    - a value between   +   10**37 and 10**-37\n\n");

    printf("Enter Float 1:  ");
    valid = scanf("%f", &float1);

    printf("Enter Float 2:  ");
    valid = scanf("%f", &float2);

    printf("\n");

    float_1.float_value = float1;
    float_2.float_value = float2;

    printf("Original pattern of Float 1:    ");
    print_binary(float_1);

    printf("Original pattern of Float 2:    ");
    print_binary(float_2);

    emulated = sum_floats(float_1, float_2);
    emulated_32.float_value = emulated;

    printf("Bit pattern of result      :    ");
    print_binary(emulated_32);

    printf("\n");

    printf("EMULATED FLOATING RESULT FROM PRINTF ==>>> %f\n", emulated_32.float_value);     // Emulated float result from printf



    hardware = float1 + float2;
    hardware_32.float_value = hardware;       
    printf("HARDWARE FLOATING RESULT FROM PRINTF ==>>> %f\n", hardware_32.float_value);
    printf("************************************************************************\n\n");

    // returns 0 on invalid input and -1 on EOF
    if (valid == 0 || valid == -1) {
      break;
    }
    }
    return 0;
}