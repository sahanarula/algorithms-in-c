/* Author: Sahil Narula
Date: 18 June 2015 (Thursday)
Time: 18:23
Description: Binary search algo
*/
  
#include<stdio.h>
#include<stdlib.h>

int binarySearch(int data, int stack[], int min, int max){
	int mid;
	mid = (min+max)/2;
	// printf("%d\n", mid);
	if(stack[mid] == data){
		printf("found data");
		return mid;
	}
	else
	if(data < stack[mid]){
		printf("inside min data");
		binarySearch(data, stack, min, mid);
	}
	else
	if(data > stack[mid]){
		printf("inside max data");
		binarySearch(data, stack, mid+1, max);
	}
	
}

int main()
{
	int stack[10], range;
	stack[0] = 1;
	stack[1] = 2;
	stack[2] = 3;
	stack[3] = 4;
	stack[4] = 5;
	stack[5] = 6;
	stack[6] = 7;
	stack[7] = 8;
	stack[8] = 9;
	stack[9] = 10;
	range = binarySearch(7, stack, 0, 9);
    printf("\n%d is at %d location\n", stack[range], range+1);
    return 0;
}