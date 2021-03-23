//Enter the number and it will extract the digits from the diven number 
#include <stdio.h>
#include <stdlib.h>

int ones_digit, tens_digit, hundreds_digits, thousands_digits;

//caluationg digits of the input number
void calculateDigits(int number)
{
   // formula for extracting digits from the given number the maximum supported number is a 4 digit number by this algorithm;
   ones_digit = number%10;
   tens_digit = (int)(number%100)/10;
   hundreds_digits = (int)(number%1000)/100;
   thousands_digits = (int)(number%10000)/1000;
   
   //printing the digits one by one after extaction
   printf("Ones digit = %d\n",ones_digit);
   printf("Tens_digit = %d\n", tens_digit);
   printf("hundreds_digits = %d\n", hundreds_digits);
   printf("thousands_digits = %d\n", thousands_digits);

}//function calculateNumber closed
int main()
{
	int number;
	printf("enter the number who's digits you want to extract\n");
	printf("number should be between 0 to 9999 range");
	scanf("%d",&number);
	if (number>9999 || number <-9999)
	{
		printf("the number that you entered is out of the domain\n");
	}
	else
	{
		calculateDigits(number);
	}
}