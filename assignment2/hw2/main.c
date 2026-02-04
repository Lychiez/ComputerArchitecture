#include "functions.h"

int main()
{
    float float1, float2, hardware, emulated,
        float_32, float_1, float_2, hardware_32, emulated_32;
    int valid = 1;

    // Boilerplate text
    printf("Please enter two positive floating point values each with:\n");
    printf("    - no more than 6 significant digits\n");
    printf("    - a value between   +   10**37 and 1-**-37\n");

    printf("Enter Float 1:  ");
    valid = scanf("%f", &float1);

    printf("Enter Float 2:  ");
    valid = scanf("%f", &float2);

    printf("\n");

    printf("Original pattern of Float 1:    ");
    // Function output
    // XX

    printf("Original pattern of Float 2:    ");
    // Function output

    // Do Bit pattern of result function
    printf("Bit pattern of result:  ");
    // Bit pattern of result

    // Emulated float result from printf float value 
    printf("EMULATED FLOATING RESULT FROM PRINTF ==>>> \n");
    printf("HARDWARE FLOATING RESULT FROM PRINTF ==>>> \n");

    // Hardware Floating Result from printf

    return 0;
}