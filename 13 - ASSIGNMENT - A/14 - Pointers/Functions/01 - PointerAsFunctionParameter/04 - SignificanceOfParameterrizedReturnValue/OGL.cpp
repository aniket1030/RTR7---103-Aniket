#include <stdio.h>

enum
{
    NEGATIVE = -1,
    ZERO,
    POSITIVE
};

int main(void)
{
    //function declarations
    int Difference(int, int, int*);

    //variable declaration
    int m;
    int n;
    int answer, ret;

    //code
    printf("\n\n");
    printf("Enter Value Of 'M' : ");
    scanf("%d", &m);

    printf("\n\n");
    printf("Enter Value Of 'N' : ");
    scanf("%d", &n);

    ret = Difference(n, m, &answer);

    printf("\n\n");
    printf("Difference Of %d And %d = %d\n\n", m, n, answer);

    if (ret == POSITIVE)
        printf("The Difference Of %d And %d Is Positive !!!\n\n", m, n);

    else if (ret == NEGATIVE)
        printf("The Difference Of %d And %d Is Negative !!!\n\n", m, n);

    else
        printf("The Difference Of %d And %d Is Zero !!!\n\n", m, n);

    return(0);
}

// WE WANT OUR FUNCTION Difference() TO PERFORM 2 JOBS
// ONE, IS TO SUBTRACT THE INPUT NUMBERS ('y' FROM 'x') AND THE SECOND, IS TO TELL WHETHER THE DIFFERENCE OF 'x' AND 'y' IS POSITIVE, NEGATIVE OR ZERO.
// BUT ANY FUNCTION CAN ONLY RETURN ONE VALID RETURN VALUE, THEN HOW CAN WE MANAGE TO RETURN TWO VALUES TO THE CALLING FUNCTION?
// THIS IS WHERE PARAMETERIZED RETURN VALUE COMES INTO THE PICTURE.
// WE CAN RETURN THE ACTUAL DIFFERENCE OF 'x' AND 'y', THAT IS, THE ACTUAL ANSWER VALUE, VIA OUT-PARAMETER / PARAMETERIZED RETURN VALUE
// AND WE CAN RETURN THE STATUS OF THE ANSWER (POSITIVE / NEGATIVE / ZERO) VIA THE ACTUAL RETURN VALUE OF THE FUNCTION.

int Difference(int x, int y, int* diff)
{
    //code
    *diff = x - y;

    if (*diff > 0)
        return(POSITIVE);

    else if (*diff < 0)
        return(NEGATIVE);

    else
        return(ZERO);
}


