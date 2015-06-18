/* Author: Sahil Narula
Date: 18 June 2015 (Thursday)
Time: 05:02
Description: Stack with constant time operation
*/
  
#include<stdio.h>
#include<stdlib.h>

int stack[10], i = 0, j=0;
int minStack[10];

void push(int data){
	stack[i++] = data;
	if(minStack[0] == -1){
		minStack[0] = data;
	}
	else{
		if(data<minStack[j]){
			minStack[++j] = data;
		}
	}
}

int pop(){
	return stack[--i];
}

int min(){
	return minStack[j--];
}

int main()
{
minStack[0] = -1;
	int c;
	do
	{
		scanf("%d", &c);
		if(c != 0){
			push(c);
		}
	} while (c != 0);
	printf("%d", pop());
	printf("%d", min());
    printf("Hello, World!\n");
    return 0;
}