/* Author: Sahil Narula
Date: 16 June 2015 (Tuesday)
Time: 01:21
Description: Number of leaves in a tree
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

int num = 0;
void getLeaves(struct node *node){
	if(node == NULL){
		return;
	}
	if(node->left == NULL && node->right == NULL)
		num++;
	getLeaves(node->left);
	getLeaves(node->right);
}

int main()
{
	struct node* root = newNode(1);
	root->left = newNode(2);	
	root->right = newNode(3);	
	root->left->left = newNode(4);	
	root->left->right = newNode(5);
    getLeaves(root);
    printf("%d\n", num);
    return 0;
}