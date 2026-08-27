#include <stdio.h>

int main(void)
{
	//variable declarations
	char ch;
	char* ptr = NULL; //Declaration Method 2 :- 'ptr' is variable of type 'char*'

	//code
	ch = 'A';

	printf("\n\n");

	printf(" ****** BEFORE ptr = &ch ******\n\n");
	printf("Value Of 'ch'             = %f\n\n", ch);
	printf("Address Of 'ch'           = %p\n\n", &ch);
	printf("Value At Address Of 'ch'  = %f\n\n", (&ch));

	//Assigning address of variable 'ch' to pointer variable 'ptr'
	//'ptr' now contains address of 'ch'...hence, 'ptr' is SAME as '&ch'
	ptr = &ch;

	printf("\n\n");

	printf(" ****** AFTER ptr = &ch ******\n\n");
	printf("Value Of 'ch'             = %f\n\n", ch);
	printf("Address Of 'ch'           = %p\n\n", ptr);
	printf("Value At Address Of 'ch'  = %f\n\n", *ptr);

	return(0);
}