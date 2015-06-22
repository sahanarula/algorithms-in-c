/* Author: Sahil Narula
Date: 20 June 2015 (Saturday)
Time: 01:26
Description: Merge sort for linked list
*/
  
#include<stdio.h>
#include<stdlib.h>

struct node{
	int data;
	struct node * next;
};

struct node* newNode(int data){
	struct node* node = (struct node*) malloc( sizeof(struct node) );
	node->next = NULL;
	node->data = data;
	// printf("%d\n", node->data);
	return node;
}

void merge(struct node *head, int min, int mid, int max){
	struct node *curr = head;
	struct node *lhead,*fhead, *rhead, *lcurr, *rcurr, *fcurr;
	int n1 = mid-min+1;
	int n2 = max-mid;
	int i, j, k;
	lhead = head;
	rhead = head;
	lcurr = lhead;
	rcurr = rhead;
	fcurr = head;
	i=min;
	int larr[10], rarr[10];
	while(i >= 0){
		lcurr = lcurr->next;
		i--;
	}
	i=mid+1;
	while(i >= 0){
		rcurr = rcurr->next;
		i--;
	}
	i=max;
	while(i >= 0){
		fcurr = fcurr->next;
		i--;
	}
	lhead = lcurr;
	rhead = rcurr;
	fhead = fcurr;
	j=0;
	k=0;
	while(lcurr < rcurr){
		larr[j++] = lcurr->data;
		lcurr = lcurr->next;
	}
	while(rcurr < fcurr){
		rarr[k++] = rcurr->data;
		rcurr = rcurr->next;
	}
	i = 0;
	j = 0;
	while(i<n1 && j<n2){
		n1--;
	}
	// for (i= 0; i < n1; i++)
	// {
	// 	if(lhead == NULL){
	// 		lhead = newNode()
	// 	}
	// }
}

void mergeSort(struct node *head, int min, int max){
	if(min<max){
		int mid = (min+max)/2;
		mergeSort(head, min, mid);
		mergeSort(head, mid+1, max);
		merge(head, min, mid, max);
	}
}

int main()
{
	int data[] = {0, 1, 15, 25, 6, 7, 30, 40, 50};
	struct node *head, *curr;
	int i=0;
	head = NULL;
	curr = head;
	for(i=0; i<8; i++){
		if(head == NULL){
			head = newNode(data[i]);
			curr = head;
		}
		else{
			curr->next = newNode(data[i]);
			curr = curr->next;
		}
	}
	// curr = head;
	mergeSort(head, 0, 7);
    printf("Hello, World!\n");
    return 0;
}