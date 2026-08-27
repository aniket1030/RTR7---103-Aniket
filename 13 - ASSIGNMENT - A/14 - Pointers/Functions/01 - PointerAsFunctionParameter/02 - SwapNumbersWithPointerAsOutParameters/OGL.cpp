#include <stdio.h>

int main(void)
{
    //function declarations
    void SwapNumbers(int*, int*);

    //variable declaration
    int m;
    int n;

    //code
    printf("\n\n");
    printf("Enter Value For 'M' : ");
    scanf("%d", &m);

    printf("\n\n");
    printf("Enter Value For 'N' : ");
    scanf("%d", &n);

    printf("\n\n");
    printf("****** BEFORE SWAPPING ******\n\n");
    printf("Value Of 'M' = %d\n\n", m);
    printf("Value Of 'N' = %d\n\n", n);

    SwapNumbers(&m, &n); // ****** ARGUMENTS PASSED 'BY REFERENCE / ADDRESS' ... ******

    printf("\n\n");
    printf("****** AFTER SWAPPING ******\n\n");
    printf("Value Of 'M' = %d\n\n", m);
    printf("Value Of 'N' = %d\n\n", n);

    return(0);
}

// Address of 'm' is copied into 'x' and Address of 'n' is copied into 'y' ... So, '&m' and 'x' are pointing to ONE and the SAME address and '&n' and 'y' are pointing to ONE and the SAME address ...
// Swapping takes place between value at address of 'x' (value at &a i.e. 'm') and value at address of 'y' (value at &b i.e. 'n') ...
// Hence, swapping in this case takes place between '*x' and '*y' AS WELL AS BETWEEN 'm' and 'n' ...

void SwapNumbers(int* x, int* y)
{
    //variable declarations
    int temp;

    //code
    printf("\n\n");
    printf("****** BEFORE SWAPPING ******\n\n");
    printf("Value Of 'X' = %d\n\n", *x);
    printf("Value Of 'Y' = %d\n\n", *y);

    temp = *x;
    *x = *y;
    *y = temp;

    printf("\n\n");
    printf("****** AFTER SWAPPING ******\n\n");
    printf("Value Of 'X' = %d\n\n", *x);
    printf("Value Of 'Y' = %d\n\n", *y);

}


