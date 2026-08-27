#include <stdio.h>

int main(void)
{
    //function declaration
    void SwapNumbers(int, int);

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

    SwapNumbers(m, n); // ****** ARGUMENTS PASSED 'BY VALUE' ... ******

    printf("\n\n");
    printf("****** AFTER SWAPPING ******\n\n");
    printf("Value Of 'M' = %d\n\n", m);
    printf("Value Of 'N' = %d\n\n", n);

    return(0);
}

void SwapNumbers(int x, int y) // Value of 'm' is copied into 'x' and value of 'n' is copied into 'y' .... swapping takes place between 'x' and 'y' .... not between 'm' and 'n'
{
    //variable declarations
    int temp;

    //code
    printf("\n\n");
    printf("****** BEFORE SWAPPING ******\n\n");
    printf("Value Of 'X' = %d\n\n", x);
    printf("Value Of 'Y' = %d\n\n", y);

    temp = x;
    x = y;
    y = temp;

    printf("\n\n");
    printf("****** AFTER SWAPPING ******\n\n");
    printf("Value Of 'X' = %d\n\n", x);
    printf("Value Of 'Y' = %d\n\n", y);

}


