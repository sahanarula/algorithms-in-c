/* Author: Sahil Narula
Date: 14 June 2015 (Sunday)
Time: 23:42
Description: Calculate size of a tree
*/
  
#include<stdio.h>
#include<stdlib.h>

struct node{
	int data;
	struct node *left;
	struct node *right;
};

struct node* newNode(int data){
	struct node* node = (struct node*) malloc( sizeof(struct node) );
	node->left = NULL;
	node->right = NULL;
	node->data = data;
	return node;
}
int data = 0;
int size(struct node* root){
	if(root == NULL){
		return data;
	}
	data++;
	size(root->left);
	size(root->right);
}

int main()
{
	struct node* root = newNode(1);
	root->left = newNode(2);
	root->right = newNode(3);
	root->right->left = newNode(3);
	root->right->left->right = newNode(3);
	root->left->left = newNode(4);
	root->left->right = newNode(5);
	printf("data in root %d\n", size(root));
    return 0;
}