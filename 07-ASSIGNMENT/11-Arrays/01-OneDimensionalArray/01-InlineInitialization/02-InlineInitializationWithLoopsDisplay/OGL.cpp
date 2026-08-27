#include <stdio.h>
int main(void)
{
	//variable declarations
	int iArray[] = { 9, 30, 6, 12, 98, 95, 20, 23, 2, 45 };
	int int_size;
	int iArray_size;
	int iArray_num_elements;

	float fArray[] = { 1.2f, 2.3f, 3.4f, 4.5f, 5.6f, 6.7f, 7.8f, 8.9f };
	int float_size;
	int fArray_size;
	int fArray_num_elements;

	char cArray[] = { 'A', 'S', 'T', 'R', 'O', 'M', 'E', 'D', 'I', 'C', 'O', 'M', 'P' };
	int char_size;
	int cArray_size;
	int cArray_num_elements;

	int i;

	//code
	
	// ****** iArray[] ******
	printf("\n\n");
	printf("In-line Initialization And Loop (for) Display Of Elements of Array 'iArray[]': \n\n");

	int_size = sizeof(int);
	iArray_size = sizeof(iArray);
	iArray_num_elements = iArray_size / int_size;

	for (i = 0; i < iArray_num_elements; i++)
	{
		printf("iArray[%d] (Element %d) = %d\n", i, (i + 1), iArray[i]);
	}

	printf("\n\n");
	printf("Size Of Data type 'int'                                      = %d bytes\n", int_size);
	printf("Number Of Elements In 'int' Array 'iArray[]'                 = %d Elements\n", iArray_num_elements);
	printf("Size Of Array 'iArray[]' (%d Elements * %d Bytes)            = %d Bytes\n\n", iArray_num_elements, int_size, iArray_size);

	// ****** fArray[] ******
	printf("\n\n");
	printf("In-line Initialization And Loop (while) Display Of Elements of Array 'fArray[]': \n\n");

	float_size = sizeof(float);
}