#include <stdio.h>

int main(void)
{
	//variable declartions
	int num;
	int* ptr = NULL; // Declaration Method 1 :- '*ptr' is a variable of type 'int'

	//code
	num = 10;

	printf("\n\n");

	printf(" ****** BEFORE ptr = &num ******\n\n");
	printf("Value Of 'num'             = %d\n\n", num);
	printf("Address Of 'num'           = %p\n\n", &num);
	printf("Value At Address Of 'num'  = %d\n\n", *(&num));

	//Assigning address of variable 'num' to pointer variable 'ptr'
	//'ptr' now contains address of 'num'...Hence, 'ptr' is SAME as '&num'
	ptr = &num;

	printf("\n\n");

	printf(" ****** After ptr = &num ******\n\n");
	printf("Value Of 'num'            = %d\n\n", num);
	printf("Address Of 'num'          = %p\n\n", ptr);
	printf("Value At Address Of 'num' = %d\n\n", *ptr);

	return(0);
}