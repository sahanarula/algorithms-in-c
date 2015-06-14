/* Author: Sahil Narula
Date: 15 June 2015 (Monday)
Time: 00:30
Description: Check if two trees are identical
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

int identicalTree(struct node *root1, struct node *root2){
	if(root1 == NULL && root2 == NULL){
		return 1;
	}
	if(root1 != NULL && root2 != NULL){
		return (
				root1->data == root2->data &&
				identicalTree(root1->left, root2->left) &&
				identicalTree(root1->right, root2->right) 
			);
	}

	return 0;
}

int main()
{
	struct node* root1 = newNode(1);
	struct node* root2 = newNode(1);
	root1->left = newNode(2);
	root2->left = newNode(2);
	root1->right = newNode(3);
	root2->right = newNode(3);
	root1->right->left = newNode(3);
	root2->right->left = newNode(3);
	root1->right->left->right = newNode(3);
	root2->right->left->right = newNode(3);
	root1->left->left = newNode(4);
	root2->left->left = newNode(4);
	root1->left->right = newNode(5);
	root2->left->right = newNode(5);
	printf("trees are %s\n", identicalTree(root1, root2)?"identical":"not identical");
    return 0;
}
