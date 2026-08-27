#include <stdio.h>

int main(void)
{
	//code
	printf("\n\n");

	printf("Size of 'int' = %1d bytes\n", sizeof(int));
	printf("size of 'unsigned int' = %1d bytes\n", sizeof(unsigned int));
	printf("size of 'long' = %1d bytes\n", sizeof(long));
	printf("size of 'long long' = %1d bytes\n", sizeof(long long));

	printf("size of 'float' = %1d bytes\n", sizeof(float));
	printf("size of 'double' = %1d bytes\n", sizeof(double));
	printf("size of 'long double' = %1d bytes\n", sizeof(double));

	printf("\n\n");

	return(0);
}