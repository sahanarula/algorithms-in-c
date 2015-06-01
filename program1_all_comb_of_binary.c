/* Author: Sahil Narula
Date: 01-June-2015
Description: Displays all n combinations of binary digits
*/
  
#include<stdio.h>

int arr[10];

void printn(int n, int k){
    int i;
    if(n<1){
        for(i=0; i<3; i++)
	      printf("%d", arr[i]);
        printf("\n");
    }
        
    else{
       for(i=0; i<k; i++){
       	arr[n-1] = i;
       	printn(n-1, k);
       }
    }
}


int main()
{
    printn(3, 3);
    return 0;
}