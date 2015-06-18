/* Author: Sahil Narula
Date: 18 June 2015 (Thursday)
Time: 18:33
Description: Selection sort algo
*/
  
#include<stdio.h>
#include<stdlib.h>


void pr(int *stack, int size){
	int i;
	for(i=0; i<size; i++){
		printf("%d\n", stack[i]);
	}
}

int selectionSort(int *stack, int size){
	int temp, i, j;
	for (i = 0; i < size; i++)
	{
		for (j = i+1; j < size; j++)
		{
			if(stack[i] > stack[j]){
				temp = stack[i];
				stack[i] = stack[j];
				stack[j] = temp;
			}
		}
	}
	pr(stack, size);
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
	selectionSort(stack, size);
    return 0;
}