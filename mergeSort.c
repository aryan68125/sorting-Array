#include <stdio.h>
#include <stdlib.h>
void merge(int A[],int low,int heigh,int mid)
{
int i,j,k;
i=low;
j=mid+1;
k=low;

int B[100];//temporary array

while(i<=mid && j<=heigh)//actual sorting in ascending order
{
if(A[i]<A[j])
{
B[k++]=A[i++];
}
else
{
B[k++]=A[j++];
}
}

for(;i<=mid;i++) //copying the remaining element if any in the array after comparision is over
{
B[k++]=A[i];
}
for(;j<=heigh;j++)
{
B[k++]=A[j];
}
//copying the element from the temporary array B to original array A 
for(i=low;i<=heigh;i++)
{
A[i]=B[i];
}
} //merge function is complete

void IMerge(int A[],int n)
{
int p; //passes
int low,heigh,mid,i;
for(p=2;p<=n;p=p*2) //this for loop is for number of passes
{
for(i=0;i+p-1<n;i=i+p)
{
low = i;
heigh = i+p-1;
mid = (low+heigh)/2;
//call the merge function
merge(A,low,heigh,mid);

}// ifor loop
}//p for loop
if(p/2<n)
{
merge(A,0,(p/2)-1,n);
}//if block is closed
}//IMerge function ends here

int main()
{
int A[] = {11,13,7,32,123,1,-23,-512,-2};
int n=9;
IMerge(A,n);
for(int i=0;i<n;i++)
printf("%d\n",A[i]);
return 0;
}
