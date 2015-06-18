/* Author: Sahil Narula
Date: 19 June 2015 (Friday)
Time: 04:45
Description: Quick sort
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

int partition(int *array, int l, int r){
	int val = array[r];

	int i, temp;
	int pIndex = l;
	printf("%d\n", r);
	for (i = pIndex; i<r; i++)
	{
		if(array[i] <= array[r]){
			temp = array[i];
			array[i] = array[pIndex];
			array[pIndex] = temp;
			pIndex++;
		}
		pr(array, 10);
		printf("pindex %d\n", pIndex);

	}
	temp = array[pIndex];
	array[pIndex] = array[r];
	array[r] = temp;
	pr(array, 10);
	return pIndex;
}

int quickSort(int *array, int l, int r){
	if(l<r){
		int pivot = partition(array, l, r);
		quickSort(array, l, pivot-1);
		quickSort(array, pivot+1, r);
	}
}

int main()
{
	int stack[10], range;
	stack[0] = 1;
	stack[1] = 4;
	stack[2] = 3;
	stack[3] = 2;
	stack[4] = 5;
	stack[5] = 9;
	stack[6] = 10;
	stack[7] = 8;
	stack[8] = 6;
	stack[9] = 7;
    int size = sizeof(stack) / sizeof(stack[0]);

	quickSort(stack, 0, 9);
	pr(stack, 10);
	printf("Hello, World!\n");	
    printf("Hello, World!\n");
    return 0;
}