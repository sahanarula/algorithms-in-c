/* Author: Sahil Narula
Date: 15 June 2015 (Monday)
Time: 00:42
Description: Maximum depth of a tree
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

int data = 0;
int maxDepth(struct node* root){
	if(root == NULL){
		return 0;
	}
	else{
		int lDepth = maxDepth(root->left);
		int rDepth = maxDepth(root->right);

		if(lDepth > rDepth){
			return ++lDepth;
		}
		else
			return ++rDepth;
	}
}

int main()
{
	struct node *root = newNode(1);
	root->left = newNode(2);	
	root->right = newNode(3);	
	root->left->left = newNode(4);	
	root->left->right = newNode(5);
	printf("%d\n", maxDepth(root));	
    return 0;
}