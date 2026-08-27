#include <stdio.h>

int main(int argc, char* argv[], char* envp[])
{
	//funtion prototypes Or Declarations
	int MyAddition(int, int);

	//variable declarations
	int r;
	int num_01, num_02;

	//code
	num_01 = 10;
	num_02 = 20;

	printf("\n\n");
	printf("%d + %d = %d\n", num_01, num_02, MyAddition(num_01, num_02));
	printf("\n\n");

	return(0);
}


// *** Function Definition Of myAddition() ******
int MyAddition(int a, int b) //function defination
{
	//funtion prototype
	int Add(int, int);

	//code
	return(Add(a, b)); // return value of funtion deinition Add() as return value of funtion MyAddition()
}

int Add(int x, int y)
{
	// code
	return(x + y);
}