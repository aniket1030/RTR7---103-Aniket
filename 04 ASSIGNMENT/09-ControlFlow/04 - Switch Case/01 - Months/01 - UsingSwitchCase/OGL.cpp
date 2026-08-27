#include <stdio.h>
int main(void)
{
	//variable declarations
	int num_month;

	//code
	printf("\n\n");

	printf("Enter Number Of Month (1 to 12) : ");
	scanf("%d", &num_month);

	printf("\n\n");

	switch (num_month)
	{
	case 1: //like 'if'
		printf("Month Number %d Is JANUARY !!!\n\n", num_month);
		break;

	case 2: //like 'if'
		printf("Month Number %d Is FEBRUARY !!!\n\n", num_month);
		break;

	case 3: //like 'if'
		printf("Month Number %d Is MARCH !!!\n\n", num_month);
		break;

	case 4: //like 'if'
		printf("Month Number %d Is APRIL !!!\n\n", num_month);
		break;

	case 5: //like 'if'
		printf("Month Number %d Is MAY !!!\n\n", num_month);
		break;

	case 6: //like 'if'
		printf("Month Number %d Is JUNE !!!\n\n", num_month);
		break;

	case 7: //like 'if'
		printf("Month Number %d Is JULY !!!\n\n", num_month);
		break;

	case 8: //like 'if'
		printf("Month Number %d Is AUGUST !!!\n\n", num_month);
		break;

	case 9: //like 'if'
		printf("Month Number %d Is SEPTEMBER !!!\n\n", num_month);
		break;

	case 10: //like 'if'
		printf("Month Number %d Is OCTOMBER !!!\n\n", num_month);
		break;

	case 11: //like 'if'
		printf("Month Number %d Is NOVEMBER !!!\n\n", num_month);
		break;

	case 12: //like 'if'
		printf("Month Number %d Is DECEMBER !!!\n\n", num_month);
		break;

	default: //like ending OPTIONAL 'else'...just like terminating 'else' is optional in if-else ladder, so is the 'default' case optional in switch-case
		printf("Invalid month Number %d Entered !!! Please Tyr Again...\n\n", num_month);
		break;
	}

	printf("Switch Case Block Complet !!!\n");

	return(0);
}