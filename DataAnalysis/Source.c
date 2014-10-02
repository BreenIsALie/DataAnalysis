/*Program to analyse sales numbers
Mathias Jönsson*/

#include <stdio.h>

#define NUMBER_OF_QUARTERS 4
#define NUMBER_OF_SALESMEN 3

int   selection(void);												/*Separate function for selection by number input*/
float ReadArray(int Sel2, float Sales[][NUMBER_OF_SALESMEN]);		/*Function to read the array for selected quarter*/

int main(void)
{	
	int Sel=0;
	float Sum;
	float Sales[NUMBER_OF_QUARTERS][NUMBER_OF_SALESMEN] =
	{ { 3.3, 2.2, 7.1 },
	{ 4.0, 5.5, 3.1 },
	{ 6.9, 0.0, 3.5 },
	{ 2.2, 2.2, 1.2 } };

	while (Sel != 5)
	{

		Sel = selection();			/*Run selection function*/
		
		int Sel2 = Sel - 1;			/*Makes ReadArray change the quarter depending on selection (Since array start at 0)*/

		if (Sel == 5)
		{
			return 0;
		}
		else if (Sel<5 && Sel>0)
		{
			Sum = ReadArray(Sel2, Sales);	 /*Read array function, adds Sel2 to switch between X axis in array*/
			printf("\n%f", Sum);			 /*Print combined amount of first row*/
		}
		else
			printf("\n\nERROR: INVALID CHOICE\n\n");
	}
}

int selection(void)					/*Normal selection function*/
{
	int Sel;
	printf("Select function:\n1: Quarter 1 \n2: Quarter 2 \n3: Quarter 3 \n4: Quarter 4 \n5: Exit \n\nSelect function (1-5)\n");
	scanf_s("%d", &Sel);
	return Sel;
}	 

float ReadArray(int Sel2, float Sales[][NUMBER_OF_SALESMEN])			/*Function to read the length of the array and print result*/
{
	int i;
	float Sum = 0;
	for (i = 0; i <= NUMBER_OF_SALESMEN - 1; i++)	/*Until all salesmen have been acounted for, run loop*/
	{
		Sum = Sum + Sales[Sel2][i];					/*Read array, and run correct part depending on selection (Sel and Sel2)*/
	}
	return Sum;
}
