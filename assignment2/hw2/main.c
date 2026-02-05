#include "functions.h"

int main()
{
    float float1, float2;//, hardware, emulated;
    union float_32 float_1, float_2;//, hardware_32, emulated_32;
    // int valid = 1;

    // Boilerplate text
    printf("Please enter two positive floating point values each with:\n");
    printf("    - no more than 6 significant digits\n");
    printf("    - a value between   +   10**37 and 10**-37\n");

    printf("Enter Float 1:  ");
    // valid = 
    scanf("%f", &float1);

    printf("Enter Float 2:  ");
    // valid = 
    scanf("%f", &float2);

    printf("\n");

    float_1.float_value = float1;
    float_2.float_value = float2;

    printf("Original pattern of Float 1:    ");
    print_binary(float_1);

    printf("Original pattern of Float 2:    ");
    print_binary(float_2);

    // XX
    // Do math to actually had 2 of the bits together

    printf("Bit pattern of result      :    ");
    // Bit pattern of result

    printf("\n");

    printf("EMULATED FLOATING RESULT FROM PRINTF ==>>> \n");
    // Emulated float result from printf

    printf("HARDWARE FLOATING RESULT FROM PRINTF ==>>> \n");
    // Hardware Floating Result from printf

    return 0;
}