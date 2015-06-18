/* Author: Sahil Narula
Date: 19 June 2015 (Friday)
Time: 02:27
Description: Insertion sort
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


void insertionSort(int *array, int size){
	int i, j, temp, curr;
	for (i = 1; i < size; i++)
	{
		curr = array[i];
		j = i-1;
		temp = -1;
			pr(array, size);
		while(array[j] > curr && j >= 0){
			pr(array, size);
			array[j+1] = array[j];
			j--;
			temp = 1;
		}
		if(temp == 1)
			array[j+1] = curr;
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
	insertionSort(&stack[0], size);
	pr(stack, size);

	
    return 0;
}