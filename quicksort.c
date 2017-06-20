/*#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define max 333

void swap(int *arr1, int* arr2);
void random_quick_sort(int* arr, int start, int end);
int random_partition(int* arr, int start, int end);
void merge();

int arr1[max],arr2[max],arr3[max];
int list3in1[max*3];
int tmp1[max*3],tmp2[max*3];
FILE *wp1,*wp2,*wp3;
int pass=0;
/*This program implements quicksorting algorithm. Using rand(),
random number(1~10000) saves in arr1,arr2 and arr3 and the 3 arrays are merged in list3in1.
And using quick sorting algorithm, sort the list3in1 array.
And after pass 3 and pass 7's output and final result save in any text files.

void main()
{	
	int a=0;
	int i;
	wp1=fopen("pass3.txt","w");
	wp2=fopen("pass7.txt","w");
	wp3=fopen("Final result.txt","w");

	if(wp1==NULL||wp2==NULL||wp3==NULL)
	{
		printf("ERROR");
		exit(0);
	}
	srand(time(NULL));
	for(i=0;i<max;i++)
	{
		a=rand()%10000+1;
		arr1[i]=a;
		arr2[i]=a;
		arr3[i]=a;
	}
	merge();

	for(i=0;i<50;i++)
	{
	printf("%d ",list3in1[i]);
	}

	random_quick_sort(list3in1,0,max*3-1);

	for(i=0;i<max*3;i++)
	{
		fprintf(wp1,"%d ",tmp1[i]);
		fprintf(wp2,"%d ",tmp2[i]);
		fprintf(wp3,"%d ",list3in1[i]);
	}

	fclose(wp1);
	fclose(wp2);
	fclose(wp3);
}
/*array 1, array2, and array3 are merged in list3in1
input : no input
output: no output

void merge() 
{ 
	int i;
	for(i=0;i<max;i++)
	{
		list3in1[i]=arr1[i];
		list3in1[i+max]=arr2[i];
		list3in1[i+max+max]=arr3[i];
	}
} 
/*Using rand(), the random number(0~998) is pivot
And pivot compares each array element and if pivotItem<element, go left nor go right.
And until each pass's pivot, save in tmp1(pass3), tmp2(pass7)
So it changes continuely until pass3 or pass7.
input :(list3in1,0,998)
output : random number pivot

int random_partition(int* arr, int start, int end)
{
	int pivotIdx;
	int pivot;
	int j=0,k=0;
	int i;

	srand(time(NULL));
	pivotIdx=start + rand() % (end-start+1);
	pivot = arr[pivotIdx];
	swap(&arr[pivotIdx],&arr[end]); 
	pivotIdx = end;
	i = start -1;

	for(j=start; j<=end-1; j++)
	{
		if(arr[j] <= pivot)
		{
			i = i+1;
			swap(&arr[i],&arr[j]);
		}
	}
	swap(&arr[i+1], &arr[pivotIdx]);

	if(pass<8){
		if(pass<4){
			for(k=start; k<=end; k++)
				tmp1[k] = arr[k];
		}
		for(k=start; k<=end; k++)
			tmp2[k] = arr[k];
	}

	return i+1;
}
/*This function is to swap from A to B
input : (array's element's address, other element's address)
output : none

void swap(int *arr1, int* arr2) 
{
	int temp;
	temp = *arr1;
	*arr1 = *arr2;
	*arr2 = temp;
}
/*This function is quicksorting function.
Using recursive algorithm, if(start<end) -> sorting, nor finish and next step.
And if go left array, pass++, and If go right array, pass--
So we can take each pass's pivot's index values.
input  : (list3in1,0,998)
output : none 

void random_quick_sort(int* arr, int start, int end)
{
	if(start < end) {
		int mid = random_partition(arr, start, end);
		pass++;
		random_quick_sort(arr, start, mid-1);
		random_quick_sort(arr, mid+1, end);
		pass--;
	}

}*/
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void swap(int* a, int* b);
int random_partition(int* arr, int start, int end);
void random_quick_sort(int* arr, int start, int end);

int count=0;

void main()
{
   int A[999], list1[3], list2[3], list3[3], i, j;
   
   for(i=0;i<999;i+9){
      for(j=0;j<3;j++){
         srand(time(NULL));
         //using a random number generator, create 333random integers(from 1 to 10000)
         list1[j]=list2[j]=list3[j]=rand()%10000+1;
         //Insert each integer into three separate lists(list1, list2, list3)
      }
      for(j=0;j<3;j++){
      //merge the 3 lists into a single list list3in1 of 999elements
         A[i]=list1[i];
         A[i+3]=list2[i];
         A[i+6]=list3[i];
      }
   }

   for(i=0;i<50;i++)//print the first 50 numbers of list3in1
      printf("%d number:%d \n",i,A[i]);
   random_quick_sort(A,0,998);
}

void swap(int* a, int* b)
{
   int temp;
   temp=*a;
   *a=*b;
   *b=temp;
}

int random_partition(int* arr, int start, int end)
{
   srand(time(NULL));
   int pivotIdx=start+rand()%(end-start+1);
   int pivot=arr[pivotIdx];
   swap(&arr[pivotIdx], &arr[end]);//move pivot element to the end
   pivotIdx=end;
   int i=start-1, j=0;

   for(int j=start;j<=end-1;j++){
      if(arr[j]<=pivot){
         i=i+1;
         swap(&arr[i], &arr[j]);
      }
   }
   swap(&arr[i+1], &arr[pivotIdx]);
   return i+1;
}

void random_quick_sort(int* arr, int start, int end)
{
   FILE *pass3, *pass7, *finalResult;
   int i;
   finalResult=fopen("finalResult.txt","w");

   if(start<end){
      int mid = random_partition(arr,start,end);
      random_quick_sort(arr, start, mid-1);
      random_quick_sort(arr,mid+1,end);
      count++;
      random_quick_sort(arr, start, end);
   }
   else{
      for(i=0;i<999;i++){
         fprintf(finalResult,"Final result\n");
         fprintf(finalResult,"%d ",arr[i]);
   }
   
   pass3=fopen("pass3.txt","w");
   pass7=fopen("pass7.txt","w");
   if(count==3){
      fprintf(pass3,"pass3:");
      for(i=0;i<999;i++)
         fprintf(pass3,"%d ",arr[i]);
   }
   if(count==7){
      fprintf(pass3,"pass7:");
      for(i=0;i<999;i++)
         fprintf(pass7,"%d ",arr[i]);
   }

   fclose(finalResult);
   fclose(pass3);
   fclose(pass7);
}

