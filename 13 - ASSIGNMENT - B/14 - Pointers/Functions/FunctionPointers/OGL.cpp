#include <stdio.h>

int main(void)
{
    //function declarations
    int AddIntegers(int, int);
    int SubtractIntegers(int, int);
    float AddFloats(float, float);

    //variable declaration
    typedef int (*AddIntsFnPtr)(int, int);
    AddIntsFnPtr ptrAddTwoIntegers = NULL;
    AddIntsFnPtr ptrFunc = NULL;

    typedef float (*AddFloatsFnPtr)(float, float);
    AddFloatsFnPtr ptrAddTwoFloats = NULL;

    int iAnswer = 7;
    float fAnswer = 7.0f;

    //code
    ptrAddTwoIntegers = AddIntegers;
    iAnswer = ptrAddTwoIntegers(9, 30);
    printf("\n\n");
    printf("Sum Of Integers = %d\n\n", iAnswer);

    ptrFunc = SubtractIntegers;
    iAnswer = ptrFunc(12, 65);
    printf("\n\n");
    printf("Subtraction Of Integers = %d\n\n", iAnswer);

    ptrAddTwoFloats = AddFloats;
    fAnswer = ptrAddTwoFloats(56.45f, 90.2f);
    printf("\n\n");
    printf("Sum Of Floating-Point Numbers = %f\n\n", fAnswer);

    return(0);
}

int AddIntegers(int m, int n)
{
    //variable declarations
    int o;

    //code
    o = m + n;
    return(o);
}

int SubtractIntegers(int m, int n)
{
    //variable declarations
    int o;

    //code
    if (m > n)
        o = m - n;
    else
        o = n - m;

    return(o);
}

float AddFloats(float f_num1, float f_num2)
{
    //variable declarations
    float ans;

    //code
    ans = f_num1 + f_num2;
    return(ans);
}


