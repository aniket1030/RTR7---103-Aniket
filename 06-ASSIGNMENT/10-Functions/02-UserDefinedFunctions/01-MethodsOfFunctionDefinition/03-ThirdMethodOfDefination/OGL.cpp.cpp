#include <stdio.h> //'stdio.h' contains declaration of 'printf()'

// Entry-Point Function => main() => Valild Return Type (int) and 3 Parameters (int argc, char *argv[], char *envp[])
int main(int argc, char* argv[], char* envp[])
{
	//function prototype / declarations / signatur
	void MyAddition(int, int);

	//variable declarations : local variables to main()
	int a, b;

	//code
	printf("\n\n");
	printf("Enter Integer Value For 'A' : ");
	scanf("%d", &a);

	printf("\n\n");
	printf("Enter Integer Value For 'B' : ");
	scanf("%d", &b);

	MyAddition(a, b); //function call

	return(0);
}

// ****** USER DEFINED FUNCTION : METHOD OF DEFINITION 3 ******
// ****** NO RETURN VALUE, VALID PARAMETERS (int, int) ******

void MyAdditions(int a, int b) //funtion defination
{
	//variable declarations : local variable to MyAdditon()
	int sum;

	//code
	sum = a + b;
	printf("\n\n");
	printf("Sum Of %d And %d = %d\n\n", a, b, sum);
}


