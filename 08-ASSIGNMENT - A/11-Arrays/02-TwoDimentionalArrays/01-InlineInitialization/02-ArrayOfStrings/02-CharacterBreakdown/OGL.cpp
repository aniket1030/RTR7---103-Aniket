#include <stdio.h>

#define MAX_STRING_LENGTH 512

int main(void)
{
	//function prototype
	int MyStrlen(char[]);

	//variable declarations

	// *** A 'STRING' IS AN ARRAY OF CHARACTER ... so char[] IS A char ARRAY AND HENCE, char[] IS A 'STRING' ***
	// *** AN ARRAY OF char ARRAY IS AN ARRAY OF STRING !!! ***
	// *** HENCE, char [] IS ONE char ARRAY AND HENCE, IS ONE STRING ***
	// *** HENCE, char [][] IS AN ARRAY OF char ARRAYS AND HENCE, IS AN ARRAY OF STRING ***

	//Here, the string array can allow a maximum number of 10 string (10 rows) and each of these 10 string can have only upto 15 character maximum (15 columns)
	char strArray[10][15] = { "Hello", "Welcome", "To", "Real", "Time", "Rendering", "Batch", "(2020-21)", "Of", "ASTROMEDICOMP." }; //IN-LINE INITIALIZATION
	int iStrLengths[10]; //1D indices in 'strArray[]' e.g: iStrLength[0] will be the length of string at strArray[0], iStrLength[1] will be the length of string at strArray[1]...10 string, 10 length...
	int strArray_size;
	int strArray_num_rows;
	int i, j;

	//code
	strArray_size = sizeof(strArray);
	strArray_num_rows = strArray_size / sizeof(strArray[0]);

	//Storing in lengths of all the strings...
	for (i = 0; i < strArray_num_rows; i++)
		iStrLengths[i] = MyStrlen(strArray[i]);

	printf("\n\n");
	printf("The Entire String Array : \n\n");
	for (i = 0; i < strArray_num_rows; i++)
		printf("%s ", strArray[i]);

	printf("\n\n");
	printf("String In The 2D Array : \n\n");

	//Since, char[][] is an array of string, refering only by the row number (first []) will give the row or the string
	//The column Number (secong []) is the particular character in that string / row
	for (i = 0; i < strArray_num_rows; i++)
	{
		printf("String Number %d => %s\n\n", (i + 1), strArray[i]);
		for (j = 0; j < iStrLengths[i]; j++)
		{
			printf("Character %d = %c\n\n", (j + 1), strArray[i][j]);
		}
		printf("\n\n");
	}
	return(0);
}

int MyStrlen(char str[])
{
	//variable declarations
	int j;
	int string_length = 0;

	//code
	// *** DETERMINING EXACT LENGTH OF THE STRING, BY DETECTION THE FIRST OCCURENCE OF NULL-TERMINATING CHARACTER ( \0 ) ***
	for (j = 0; j < MAX_STRING_LENGTH; j++)
	{
		if (str[j] == '\0')
			break;
		else
			string_length++;
	}
	return(string_length); 
}



