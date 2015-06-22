/* Author: Sahil Narula
Date: 20 June 2015 (Saturday)
Time: 00:47
Description: Find the Minimum length Unsorted Subarray, sorting which makes the complete array sorted
*/
  
#include<stdio.h>
#include<stdlib.h>

void pr(int *stack, int size){
	int i;
	for(i=0; i<size; i++){
		printf("%d ", stack[i]);
	}
	printf("\n");
}

void minUnsorted(int *array, int size){
	int i, minIndex, maxIndex, j;
	int min = -1, max = 999, temp = -1;
	// for (i = 0; i < size; i++)
	// {
	// 	if(array[i] < max){
	// 		max = array[i];
	// 		minIndex = i;
	// 	}
	// 	if(array[i] > min){
	// 		min = array[i];
	// 		maxIndex = i;
	// 	}
	// }
	minIndex = 0;
	maxIndex = size;
	for (i = 0; i < size; i++)
	{
		for (j = i+1; j < size; ++j)
		{
			if(array[i] > array[j]){
				minIndex = i;
				printf("%d\n", i);
				temp = 1;
				break;
			}
		}
		if(temp == 1)
			break;
	}
	temp = -1;
	for (i = size-1; i >= 0; i--)
	{
		for (j = i-1; j >= 0; j--)
		{
			if(array[i] < array[j]){
				maxIndex = i;
				printf("%d\n", i);
				temp = 1;
				break;
			}
		}
		if(temp == 1)
			break;
	}
}

int main()
{
	int array[] = {0, 1, 15, 25, 6, 7, 30, 40, 50};
	int size = sizeof(array)/ sizeof(array[0]);
	minUnsorted(array, size);
	printf("Hello, World!\n");
    return 0;
}