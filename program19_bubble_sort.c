/* Author: Sahil Narula
Date: 19 June 2015 (Friday)
Time: 00:49
Description: Bubble Sort
*/
  
#include<stdio.h>
#include<stdlib.h>


void pr(int *stack, int size){
	int i;
	for(i=0; i<size; i++){
		printf("%d\n", stack[i]);
	}
}

void bubbleSort(int *stack, int size){
	int temp, i, j;
	for (i = 0; i < size; i++)
	{
		for (j = 0; j < size-i-1; j++)
		{
			if(stack[j] > stack[j+1]){
				temp = stack[j];
				stack[j] = stack[j+1];
				stack[j+1] = temp;
			}
		}
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

	bubbleSort(&stack[0], size);
	pr(stack, size);
    return 0;
}