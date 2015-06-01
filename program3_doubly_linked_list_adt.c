/* Author: Sahil Narula
Date: 01 June 2015 (Monday)
Time: 15:58
Description: Doubly linked list operations implementation
*/
  
#include<stdio.h>
#include<stdlib.h>

struct DLLNode{
	int data;
	struct DLLNode *next;
	struct DLLNode *prev;
} *head;

int countElements(){
	int count = 0;
	struct DLLNode *current = head;
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
	struct DLLNode *newnode, *p, *q, *tmp;
	int k=1;
	newnode = (struct DLLNode *) malloc( sizeof(struct DLLNode) );
	newnode->data = data;
	if(head == NULL){
		head = newnode;
		head->prev = NULL;
		head->next = NULL;
	}
	else
	if(position == 1){
		newnode->next = head;
		newnode->prev = NULL;
		head->prev = newnode;
		head = newnode;
	}
	else{
		p = head;

		while(k<position && p!=NULL){
			k++;
			p = p->next;
		}
		newnode->next = p->next;
		p->next->prev = newnode;
		p->next = newnode;
		newnode->prev = p;
	}
}

int deleteElement(int position){
	struct DLLNode *tmp, *q, *p;
	int k=1;
	p = head;
	if(position == 1){
		tmp = head;
		head = head->next;
		head->prev = NULL;
		tmp->next = NULL;
		free(tmp);
	}
	else{
		while(k<position && p!=NULL){
			k++;
			p=p->next;
		}
		p->prev->next = p->next;
		p->next->prev = p->prev;
		p->next = NULL;
		p->prev = NULL;
		free(p);
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
	deleteElement(1);
	deleteElement(3);
	printf("count is %d\n", countElements(head));
    return 0;
    printf("Hello, World!\n");
    return 0;
}