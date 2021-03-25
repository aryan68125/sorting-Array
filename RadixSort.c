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

	// Counting Sort Array - required for arranging digits [0-9]
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
    printf("printing counter array\n");
    for(int i=0;i<=9;i++)
    {
    	printf("%d ", C[i]);
    }
    printf("\n");
}//Display function closed

//...........................................................................................................

//RAdix Sort calculation
// Function that performs Radix Sort
void radix_sort(int arr[], int n){
 
    // Step 1: Find the maxumum element
    int maximum = arr[0]; //we are sorting this input array in ascending order hence we are taking maximum number here 
                          // if we wanted to sort this array in descending order then we would have taken minimum = arr[0] here
 
    for(int i=1;i<n;i++) //traversing input array from 0 to LengthA
    {
        if(maximum < arr[i])   //here we would have put the condition minimum > arr[i] if we wanted to sort the array in descending order
            maximum = arr[i];
    }
 
    // Step 2: Count the number of digits of the maximum number
    int digits = 0;
 
    while(maximum > 0){
        digits++;
        maximum /= 10;
    }
 
    // Units/Tens/Hundreds - used to determine which digit
    int power = 1;
 
    // Step 3, 4, 5: Arrange the numbers on the basis of digits
    for(int i=0;i<digits;i++){
  
        // Initializing Count Array
        for(int j=0;j<10;j++)
            C[j] = 0;
 
        // Calculating frequency of digits
        for(int j=0;j<n;j++){
 
            // The digit under consideration in this iteration
            int num = (arr[j]/power) % 10;
 
            C[num]++;
        }
 
        // Cumulative frequency of count array
        for(int j=1;j<10;j++){
            C[j] += C[j-1];
        }
 
        // Designating new positions in the updated array
        for(int j=n-1;j>=0;j--){
 
            // The digit under consideration in this iteration
            int num = (arr[j]/power) % 10;
 
            B[C[num]-1] = arr[j];
            C[num]--;
        }
 
        // Updating the original array using New Array
        for(int j=0;j<n;j++)
            arr[j] = B[j];
         
        // Updating the digit to be considered next iteration
        power *= 10;
    }
    printf("Radix sort in ascending order is complete\n");           
}

int main()
{
	int k=0; //menue loop limiter or terminator
	int choice; //menue loop choice variable

	do{
        printf("Press 1 to create Array that holds the elements that you want to sort\n");
        printf("Press 2 to Display the created array\n");
        printf("Press 3 to radix sort the elements of the array\n");
        printf("Press 4 to Terminate Program\n");
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
                radix_sort(A, LengthA);
         break;
         case 4:
                 k=7000;
                 printf("Program Terminated by the user\n");
         break;
         default: 
                  printf("Wrong Choice\n");
                  break;

        }//switch block ends here
	}while(k<5000); //do while loop closed
} //main function is closed












