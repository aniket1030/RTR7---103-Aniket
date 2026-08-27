#include <stdio.h>

int main(void)
{
	//DEfINING STRUCT
	struct MyData
	{
		int i;
		float f;
		double d;
		char c;
	} data = { 5, 9.1f, 3.78623, 'N' };

	//Displaying values Of The Data Members Of 'struct MyData'
	printf("\n\n");
	printf("i = %d\n", data.i);
	printf("f = %f\n", data.f);
	printf("d = %1f\n", data.d);
	printf("c = %c\n\n", data.c);
	return(0);
}

