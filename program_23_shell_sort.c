/* Author: Sahil Narula
Date: 19 June 2015 (Friday)
Time: 05:21
Description: Shell sort
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

void shellSort(int *array, int size){
	int i, j, curr, k, temp = -1;
				pr(array, size);
	for(i=size/2; i>0; i/=2){
		for (j = 0; j < size; j+=i)
		{
			curr = array[j];
			printf("curr element %d\n", curr);
			k=j-i;
			while(k>=0 && array[k] >= curr){
				array[k+i] = array[k];
				k -= i;
				temp = 1;
			}
			if(temp = 1){
				array[k+i] = curr;
			}
			pr(array, size);
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

	shellSort(stack, size);
	printf("Hello, World!\n");
	return 0;
}