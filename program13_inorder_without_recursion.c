/* Author: Sahil Narula
Date: 18 June 2015 (Thursday)
Time: 03:17
Description: Converting given tree to children sum
*/
  
#include<stdio.h>
#include<stdlib.h>

struct node{
	int data;
	struct node * left;
	struct node * right;
};

struct node * newNode(int data){
	struct node* node = (struct node*) malloc( sizeof(struct node) );
	node->data = data;
	node->left = NULL;
	node->right = NULL;
	return node;
}

int stack[], i=0;
int push(int data){
	stack[i++] = data;
}
int pop(){
	return stack[--i];
}

int inorder(struct node* root){
	int n = 1;
	struct node *curr;
	struct node *prev;
	do{
		if(root == NULL) return;
		if(root->left != NULL){
			prev = curr;
			curr = root->left;
		}
		else
		if(root->right != NULL){
			prev = curr;
			curr = root->right;
		}
	}while(n);
}

int main()
{
	struct node* root = newNode(50);
	root->left = newNode(7);	
	root->right = newNode(2);	
	root->left->left = newNode(3);	
	root->left->right = newNode(5);
	root->right->left = newNode(1);
	root->right->right = newNode(30);
    printf("Inorder without recursion!\n");
    inorder(root);
    return 0;
}