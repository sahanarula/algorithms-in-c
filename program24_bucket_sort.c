/* Author: Sahil Narula
Date: 19 June 2015 (Friday)
Time: 07:16
Description: Bucket Sort
*/
  
#include<stdio.h>
#include<stdlib.h>

void pr(float *stack, int size){
	int i;
	for(i=0; i<size; i++){
		printf("%f ", stack[i]);
	}
	printf("\n");
}

void sort(float *array, int size){
	int i, j, temp = -1;
	float curr;
	for(i=1; i<size; i++){
		curr = array[i];
		j=i-1;
		temp = -1;
		while(j>=0 && array[j]>curr){
			array[j+1] = array[j];
			temp = 1;
			j--;
		}
		if(temp == 1){
			array[j+1] = curr;
		}
	}
}

void bucketSort(float * array, int size){
	float bucket[10][10];
	int i, j, bIndex, innerIndex, counter[10];
	for (i = 0; i < 10; ++i)
	{
		counter[i] = 0;
	}

	for (i = 0; i < size; ++i)
	{
		bIndex = array[i]*size;
		innerIndex = counter[bIndex]++;
		bucket[bIndex][innerIndex] = array[i];
	}
	for (i = 0; i < 10; ++i)
	{
		sort(bucket[i], counter[i]);
	}
	int k =0 ;
	for (i = 0; i < 10; i++)
	{
		if(counter[i] > 0){
			for (j = 0; j < counter[i]; j++)
			{
				array[k++] = bucket[i][j];
			}
		}
	}

}

int main()
{
	float array[] = {0.78, 0.17, 0.39, 0.26, 0.72, 0.94, 0.21, 0.12, 0.23, 0.68};
    int i;
    bucketSort(array, 10);
    pr(array, 10);
    return 0;
}