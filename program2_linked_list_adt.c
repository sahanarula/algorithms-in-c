/* Author: Sahil Narula
Date: 01 June 2015 (Monday)
Time: 13:31
Description: Linked list operations implementation
*/
  
#include<stdio.h>
#include<stdlib.h>

struct LinkedList
{
	int data;
	struct LinkedList *next;
} *head;
int countElements(){
	int count = 0;
	struct LinkedList *current = head;
	// head->data = 1;
	while(current != NULL){
		printf("->%d", current->data);
		count++;
		current = current->next;
	}
	printf("\n");
	return count;
}

int insertElement(int data, int position){
	struct LinkedList *newNode, *p, *q;
	int k = 0;
	newNode = (struct LinkedList *) malloc( sizeof(struct LinkedList) ) ;
	newNode->data = data;
	p=head;
	if(head == NULL){
		head = newNode;
		newNode->next = NULL;
	}
	else
	if(position == 1){
		newNode->next = p;
		head = newNode;
	}
	else{
		while(p!=NULL && k<position){
			k++;
			q=p;
			p=p->next;
		}
		newNode->next = p;
		q->next = newNode;
	}
}

int main()
{	
	int num, d;
	printf("enter number of elements to insert: ");
	scanf("%d", &num);
	while(num > 0){
		printf("Enter Data: ");
		scanf("%d", &d);
		insertElement(d, 1);
		num--;
	}
	printf("count is %d\n", countElements(head));
    return 0;
}