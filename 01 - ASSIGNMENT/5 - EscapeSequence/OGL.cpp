#include <stdio.h>
int main(void)
{
	//code
	printf("\n\n");
	printf("Goint On To Line...Using \\n Esape Sequence\n\n");
	printf("Demonstrating \t Horizontal \t Tab \t Using \t \\t Escape Sequence !!!\n\n");
	printf("\"This Is A Double Quoted Output\" Done Using \\\" \\\" Escape Sequence\n\n");
	printf("\'This Is A Single Quoted Output\' Done Using \\\' \\\' Escape Sequence\n\n");
	printf("BACKSPACE Turned To BACKSPACE\b Using Escape Sequence\n");

	printf("\r Demonstrating Carriage Return Using \\r Escape Sequence\n");
	printf("Demonstrating \r Carriage Return Using \\r Escape Sequence\n");
	printf("Demonstrating Carriage \r Return Using \\r Escape Sequence\n\n");

	printf("Demonstrating \x41 using \\xhh Escape Sequence\n\n"); //0x41 Is The Hexadecimal Code For Letter 'A'. 'xhh' Is The Place-holder For 'x' Followed By 2 Digits (hh), altogether forming a Hexadecimal Number.
	printf("Demonstrating \102 Using \\ooo Escape Sequence\n\n"); //102 Is The Octal Code For 'B'. 'ooo' Is Place-holder for 3 Digits Forming An Octal Number.
	return(0);

}