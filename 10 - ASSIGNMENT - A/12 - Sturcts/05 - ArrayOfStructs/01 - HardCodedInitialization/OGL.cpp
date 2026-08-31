#include <stdio.h>
#include <string.h>

#define NAME_LENGTH 100
#define MARITAL_STATUS 10

struct Employee
{
	char name[NAME_LENGTH];
	int age;
	float salary;
	char sex;
	char marital_status[MARITAL_STATUS];
};

int main(void)
{
	// variable declarations
	struct Employee EmployeeRecord[5]; // An array of 5 struct - Each beig type 'struct Employee'

	char employee_saniya[] = "Saniye";
	char employee_aniket[] = "Aniket";
	char employee_janvi[] = "Janvi";
	char employee_sanjivani[] = "Sanjivani";
	char employee_khushi[] = "Khushi";

	int i;

	// code
	// ****** HARD-CODED INITIALIZATION OF ARRAY OF 'struct Employee' ******

	// ****** EMPLOYEE 1 ******
	strcpy(EmployeeRecord[0].name, employee_saniya);
	EmployeeRecord[0].age = 14;
	EmployeeRecord[0].sex = 'F';
	EmployeeRecord[0].salary = 800000.0f;
	strcpy(EmployeeRecord[0].marital_status, "Unmarried");

	// ****** EMPLOYEE 2 ******
	strcpy(EmployeeRecord[0].name, employee_aniket);
	EmployeeRecord[1].age = 22;
	EmployeeRecord[1].sex = 'F';
	EmployeeRecord[1].salary = 700000.0f;
	strcpy(EmployeeRecord[1].marital_status, "Unmarried");

	// ****** EMPLOYEE 3 ******
	strcpy(EmployeeRecord[0].name, employee_janvi);
	EmployeeRecord[2].age = 14;
	EmployeeRecord[2].sex = 'F';
	EmployeeRecord[3].salary = 1000000.0f;
	strcpy(EmployeeRecord[2].marital_status, "Unmarried");

	// ****** EMPLOYEE 4 ******
	strcpy(EmployeeRecord[0].name, employee_sanjivani);
	EmployeeRecord[3].age = 14;
	EmployeeRecord[3].sex = 'F';
	EmployeeRecord[3].salary = 900000.0f;
	strcpy(EmployeeRecord[3].marital_status, "Unmarried");

	// ****** EMPLOYEE 5 ******
	strcpy(EmployeeRecord[0].name, employee_khushi);
	EmployeeRecord[4].age = 15;
	EmployeeRecord[4].sex = 'F';
	EmployeeRecord[4].salary = 600000.0f;
	strcpy(EmployeeRecord[4].marital_status, "Unmarried");

	// *** DISPLAY ***
	printf("\n\n");
	printf("****** DISPLAYING EMPLOYEE RECORDS ******\n\n");
	for (i = 0; i < 5; i++)
	{
		printf("****** EMPLOYEE NUMBER %d ******\n\n", (i + 1));
		printf("Name              : %s\n", EmployeeRecord[i].name);
		printf("Age               : %d years\n", EmployeeRecord[i].age);

		if (EmployeeRecord[i].sex == 'M' || EmployeeRecord[i].sex == 'm')
			printf("Sex             : Male\n");
		else
			printf("sex             : Female\n");

		printf("Sallary             : Rs. %f\n", EmployeeRecord[i].salary);
		printf("Marital Status      : %s\n", EmployeeRecord[i].marital_status);

		printf("\n\n");
	}

	return(0);
}

