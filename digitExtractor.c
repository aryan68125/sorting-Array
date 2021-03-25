//Enter the number and it will extract the digits from the diven number
//using for loop 
#include <stdio.h>
#include <stdlib.h>

int digit,i,k=1;

//caluationg digits of the input number
void calculateDigits(int number)
{
   // formula for extracting digits from the given number the maximum supported number is a 4 digit number by this algorithm;
	for(i=number;i>0;i=i/10)
	{
           digit = (int)i%10;
           printf("%d's digit = %d\n",k,digit);
            k=k*10;
	}

}//function calculateNumber closed
int main()
{
	int number;
	printf("enter the number who's digits you want to extract\n");
	printf("number should be between 0 to 9999 range\n");
	scanf("%d",&number);
		calculateDigits(number);
}
