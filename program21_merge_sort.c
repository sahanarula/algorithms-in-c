/* Author: Sahil Narula
Date: 19 June 2015 (Friday)
Time: 03:46
Description: Merge sort
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

void merge(int* array, int l, int m, int r){
	int i, j, k;
	int n1 = m-l+1;
	int n2 = r-m;
	int L[n1], R[n2];
	for (i = 0; i < n1; i++)
	{
		L[i] = array[i+l];
	}
	for (j = 0; j < n2; j++)
	{
		R[j] = array[j+m+1];
	}
	i=0; 
	j=0;
	k=l;
	while(i<n1 && j<n2){
		if(L[i] <= R[j]){
			array[k] = L[i];
			i++;
		}
		else{
			array[k] = R[j];
			j++;
		}
		k++;
	}
	while(i<n1){
		array[k] = L[i];
		i++;
		k++;
	}
	while(j<n2){
		array[k] = R[j];
		j++;
		k++;
	}
	pr(array, 10);

}

void mergeSort(int * array, int l, int r){
	if(l<r){
		int mid = (r+l)/2;
		mergeSort(array, l, mid);
		mergeSort(array, mid+1, r);
		merge(array, l, mid, r);
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

	mergeSort(stack, 0, 9);
	printf("Hello, World!\n");
    return 0;
}