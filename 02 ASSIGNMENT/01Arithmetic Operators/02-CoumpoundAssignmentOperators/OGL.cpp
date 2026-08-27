#include <stdio.h>

int main(void)
{
	//variable declarations
	int a;
	int b;
	int x;

	//code
	printf("\n\n");
	printf("Enter A Number : ");
	scanf("%d", &a);

	printf("\n\n");
	printf("Enter Another Number : ");
	scanf("%d", &b);

	printf("\n\n");

	//Since, In The Following 5 Cases, The Operand On The Left 'a' Is Getting Repeated Immeiately On The Right (e.g : a = a + b or a = a - b),
	//We Are Using Compound Assignment Operators +=, -=, *=, /=, and %= 

	//Since, 'a' Will Be Assigned The Value Of (a + b) At The Expression (a += b), We Must Save The Original Value Of 'a' TO Another Variable (X)
	x = a;
	a += b; // a = a - b 
	printf("Addition Of A = %d And B = %d Gives %d.\n", x, b, a);

	//Value Of 'a' Altered In The Above Expression Is Used Here...
	//Since, 'a' Will Be Assigned The VAlue Of (a - b) At The Expression (a -= b), We Must Save The Original Value Of 'a' To Another Variable (X)
	x = a;
	a -= b; // a = a - b 
	printf("Subtraction Of A = %d And B = %d Gives %d.\n", x, b, a);

	//Value Of 'a' Altered In The Above Expression Is Used Here...
	//Since, 'a' Will Be Assigned The Value Of (a * b) At The Expression (a *= b), We Must Save The Original Value Of 'a' To Another Variable (X)
	x = a;
	a *= b; // a = a * b
	printf("multiplication Of A = %d And B = %d Gives %d.\n", x, b, a);

	//Value Of 'a' Altered In The Above Expression Is Used  Here...
	//Since, 'a' Will Be Assined The  Value Of (a / b) At The Expression (a /= b), We Must Save The Original Value Of 'a' To Another Variables (X)
	x = a;
	a /= b; // a = a / b
	printf("Divsion Of A = %d And B = %d Gives Quotient %d.\n", x, b, a);

	//Value Of 'a' Alternate In The Above Expression Is Used Here...
	//Since, 'a' Will Be Assigned The Value Of (a % b) At The Expression (a %= b), We Must Save The Original Value Of 'a' To Another Variable (X)
	x = a;
	a %= b; // a = a % b
	printf("Division Of A = %d And B = %d Gives Remainder %d.\n", x, b, a);

	printf("\n\n");

	return(0);
}