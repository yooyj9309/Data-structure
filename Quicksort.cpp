#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define index 333

void merge();
void swap(int *arr1, int* arr2);
int random_partition(int* arr, int start, int end);
void random_quick_sort(int* arr, int start, int end);
int arr1[index], arr2[index], arr3[index], list3in1[index * 3];
int pass = 1;
int pass3Tmp[index * 3], pass7Tmp[index * 3];
/* This program merges three list3 to one list.(Each list has random interger numbers)
And using quick sort function, list becomes orderly. And make output file for pass 3 , pass 7 and final pass. */
void main()
{
	int a = 0;
	int i;
	FILE *wp, *wp1, *wp2;
	wp = fopen("pass3.txt", "w");
	wp1 = fopen("pass7.txt", "w");
	wp2 = fopen("finalresult.txt", "w");
	srand(time(NULL));
	for (i = 0; i<index; i++)
	{
		a = rand() % 10000 + 1;
		arr1[i] = a;
		arr2[i] = a;
		arr3[i] = a;
	}
	merge();
	for (i = 0; i<50; i++)
		printf("%d ", list3in1[i]);

	random_quick_sort(list3in1, 0, index * 3 - 1);

	for (i = 0; i<index * 3; i++)
	{
		fprintf(wp, "%d ", pass3Tmp[i]);
		fprintf(wp1, "%d ", pass7Tmp[i]);
		fprintf(wp2, "%d ", list3in1[i]);
	}
	fclose(wp);
	fclose(wp1);
	fclose(wp2);
}
/* This merge function is that make 3 lists into 1 list.
Input: NONE, Output: NONE. */
void merge()
{
	int i, j, k;
	for (i = 0; i<index; i++)
	{
		list3in1[i] = arr1[i];
		list3in1[i + index] = arr2[i];
		list3in1[i + index + index] = arr3[i];
	}
}
/*This radom_partion function is that choose a random pivot in list. Each pass, pivot change randomly.
And find list of pass3 and pass7
Input: array of list3in1, first and end index of sub list.  Output: index of pivot*/
int random_partition(int* arr, int start, int end)
{
	int pivotIdx;
	int pivot;
	int j = 0;
	int i;
	int num;
	srand(time(NULL));
	pivotIdx = start + rand() % (end - start + 1);
	pivot = arr[pivotIdx];
	swap(&arr[pivotIdx], &arr[end]);
	pivotIdx = end;
	i = start - 1;
	for (j = start; j <= end - 1; j++)
	{
		if (arr[j] <= pivot)
		{
			i = i + 1;
			swap(&arr[i], &arr[j]);
		}
	}
	swap(&arr[i + 1], &arr[pivotIdx]);

	if (pass<8) {
		if (pass<4) {
			for (num = start; num <= end; num++)
				pass3Tmp[num] = arr[num];
		}
		for (num = start; num <= end; num++)
			pass7Tmp[num] = arr[num];
	}
	return i + 1;
}
/* This random_quick_sort function is that using random_partion function, choose pivot  and make list sorting.
Input: array of list3in1, first index of sub list, end index of sub list. Output: NONE */
void random_quick_sort(int* arr, int start, int end)
{
	int i;

	if (start < end) {
		int mid = random_partition(arr, start, end);
		pass++;
		random_quick_sort(arr, start, mid - 1);
		random_quick_sort(arr, mid + 1, end);
		pass--;
	}
}
/*This swap function is that change positon of two elements for sorting.
Input: address of two list3in1 elememts. Output: NONE */
void swap(int *arr1, int* arr2)
{
	int temp;
	temp = *arr1;
	*arr1 = *arr2;
	*arr2 = temp;
}