/* Author: Sahil Narula
Date: 16 June 2015 (Tuesday)
Time: 01:41
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

int convertToChildrenSum(struct node *root){
	if(root == NULL)
		return;
	int left_data = 0;
	int right_data = 0;
	if(root->left != NULL)
		left_data = root->left->data;
	if(root->right != NULL)
		right_data = root->right->data;
	if(root->data == left_data + right_data)
		return;
	else
	if(root->left != NULL && root->right != NULL )
		root->data =  left_data + right_data;

	convertToChildrenSum(root->left);
	convertToChildrenSum(root->right);
}

int inorder(struct node* root){
	if(root == NULL)
		return;
	inorder(root->left);
	printf("%d\t", root->data);
	inorder(root->right);
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
    printf("before convert to children sum!\n");
    inorder(root);
    convertToChildrenSum(root);
    printf("after convert to children sum!\n");
    inorder(root);
    return 0;
}