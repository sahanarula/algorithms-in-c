/* Author: Sahil Narula
Date: 15 June 2015 (Monday)
Time: 23:03
Description: Mirror image of a tree
*/		
  
#include<stdio.h>
#include<stdlib.h>

struct node{
	int data;
	struct node *left;
	struct node *right;
};

struct node* newNode(int data){
	struct node *node = (struct node*) malloc( sizeof(struct node) );
	node->data = data;
	node->left = NULL;
	node->right = NULL;
	return node;
}

int mirror(struct node* root){
	if(root == NULL)
		return;
	
	mirror(root->left);
	mirror(root->right);

	struct node* temp;
	temp = root->left;
	root->left = root->right;
	root->right = temp;
}

int inOrder(struct node* root){
	if(root == NULL)
		return;
	inOrder(root->left);
	printf("%d\t", root->data);
	inOrder(root->right);
}

int main()
{
	struct node* root = newNode(1);
	root->left = newNode(3);	
	root->right = newNode(2);	
	root->right->left = newNode(5);	
	root->right->right = newNode(4);	
	printf("before mirror\n");
	inOrder(root);
	printf("after mirror\n");
	mirror(root);
	inOrder(root);

    printf("Hello, World!\n");
    return 0;
}