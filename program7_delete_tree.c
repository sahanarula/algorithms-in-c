/* Author: Sahil Narula
Date: 15 June 2015 (Monday)
Time: 01:08
Description: Deleting a tree
*/
  
#include<stdio.h>
#include<stdlib.h>

struct node{
	int data;
	struct node* left;
	struct node* right;
};

int deleteNode(struct node *root){
	if(root == NULL) return;
	else{
		deleteNode(root->left);
		deleteNode(root->right);
		free(root);
	}
	printf("%s", "Deleted Node");	
}

struct node* newNode(int data){
	struct node *root = (struct node *) malloc( sizeof(struct node) );
	root->data = data;
	root->left = NULL;	
	root->right = NULL;	
	return root;
}

int main()
{
	struct node *root;
	root = newNode(1);
	root->left = newNode(2);
	root->right = newNode(3);
	root->left->left = newNode(4);
	root->left->right = newNode(5);
	deleteNode(root);
	free(root);
	printf("%d", root->data);	
    return 0;
}