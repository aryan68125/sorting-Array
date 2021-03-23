#include<stdio.h>
#include<stdlib.h>

//input array
int *A;
int sizeA;//array A capacity
int LengthA;//number of elements that you want to store in array A

//Output Array
int *B;  //size and length will be equal to the input array
// size or the capacity of array b is = sizeA;
// length or number of elements in array B = LengthA;

//array to count the occurances of the digits
int *C;
int sizeC=9; //because the number of digits in the number system is 0 to 9 digits that forms the rest of the numbers in the number system

void createArray()
{
	printf("Enter the size of the input Array\n");
	scanf("%d",&sizeA);   //full capacity of array A
	printf("Enter the number of elements that you want to insert in the input array\n");
	scanf("%d",&LengthA); //number of elements that user want to enter in the array

	//memory allocation in RAM for all the participating arrays
	A=(int*)malloc(sizeA*sizeof(int)); //allocating memory to array A dynamically (INPUT ARRAY)
	B=(int*)malloc(sizeA*sizeof(int)); //allocating memory to array B dynamically (OUTPUT ARRAY)
	C=(int*)malloc(sizeC*sizeof(int)); //allocating memory to array C dynamically (the counter array)
    
    //now we will enter the elements in the input array one by one
    printf("Enter the elements in the input Array\n");
    for(int i=0;i<LengthA;i++)
    {
       scanf("%d",&A[i]);
    }

    //initializing counter array with zero
    for(int i=0;i<=9;i++)
    {
    	C[i]=0;
    }
}//create function closed

//........................................................................................................
void Display()
{
	printf("Printing the input Array\n");
	for(int i=0;i<LengthA;i++)
	{
		printf("%d ",A[i]);
	}
	printf("\n");

	printf("Printing the output Array\n");
	for(int i=0;i<LengthA;i++)
	{
		printf("%d ",B[i]);
	}
	printf("\n");

    //printing the count array for testing and debugging purposes its temporary
    for(int i=0;i<=9;i++)
    {
    	printf("%d ", C[i]);
    }
}//Display function closed

//...........................................................................................................

//RAdix Sort calculation
void radixSort()
{
	int j=10; //j and k is used to extract the digits from the number
	int k=1;  //formula used digit = (number%j)/k; where [update j by j= j*10 and k= k*10];
	int number; //this will isolate the number from the array
   int digit = 0;
   for(int m=o;m<LengthA;m++) //this loop will give us numbers from input array
   {

       number = A[m];
       for(int i=10000;i>0;i=i/10) //this for loop will decide how many times digit extraction will take place from the number 
   {
       digit = (number%j)/k; //formula to calculate digit
       j=j*10;
       k=k*10;
       for(int L=0;L<=digit;L++) //loop for counter array
       {
          C[L]=C[L]+1;
       }
   }

   }

}//radixSort function is closed

int main()
{
	int k=0; //menue loop limiter or terminator
	int choice; //menue loop choice variable

	do{
        printf("Press 1 to create Array that holds the elements that you want to sort\n");
        printf("Press 2 to Display the created array\n");
        printf("Press 3 to Terminate Program\n");
        scanf("%d",&choice); //entering the choice for selecting the menue items
        switch(choice)
        {

         case 1:
                 createArray();
         break;
         case 2:
                 Display();
         break;
         case 3:
                 k=7000;
                 printf("Program Terminated by the user\n");
         break;
         default: 
                  printf("Wrong Choice\n");
                  break;

        }//switch block ends here
	}while(k<5000); //do while loop closed
} //main function is closed












