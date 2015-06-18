/* Author: Sahil Narula
Date: 18 June 2015 (Thursday)
Time: 05:13
Description: Linked List palindrome
*/
  
#include<stdio.h>
#include<stdlib.h>

struct node{
	int data;
	struct node* next;
} *head1 = NULL, *head2 = NULL;

int nomatch = 0;
void pr(){
	struct node* curr;
	curr = head2;
	do{
		printf("%d", curr->data);
		curr = curr->next;
	}while(curr != NULL);
		printf("\n");

}
struct node* list(int data){
	struct node* node = (struct node*) malloc( sizeof(struct node) );
	struct node* rnode = (struct node*) malloc( sizeof(struct node) );
	struct node* curr;
	node->data = data;
	rnode->data = data;
	node->next = NULL;
	rnode->next = NULL;
	curr = head1;
	if(head1 == NULL){
		head1 = node;
		head2 = rnode;
	}
	else{
		while(curr->next != NULL){
			curr = curr->next;
		}
		curr->next = node;
		rnode->next = head2;
		head2 = rnode;
		pr();
	}
}


void checkPalindrome(){
	do{
		printf("%d\n", head1->data);
		printf("%d\n", head2->data);
		if(head1->data == head2->data){
			head1 = head1->next;
			head2 = head2->next;
		}
		else{
			nomatch = 1;
		}
	}while(head1 == NULL);
	if(nomatch == 1){
		printf("%s\n", "no palindrome");
	}
	else
		printf("%s\n", "palindrome");
}

int main()
{
	int c;
	do
	{
		scanf("%d", &c);
		if(c != 0){
			list(c);
		}
	} while (c != 0);
	printf("asd");
	checkPalindrome();
	pr();
    printf("Hello, World!\n");
    return 0;
}