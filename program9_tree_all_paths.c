/* Author: Sahil Narula
Date: 16 June 2015 (Tuesday)
Time: 00:21
Description: All paths from root to leaf
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

void printP(int arr[], int len){
	int i=0;
	for(i = 0; i < len; ++i)
	{
		if(!arr[i] ){
			break;
		}
		else
			printf("%d->", arr[i]);
	}
	printf("\n");
}

void printPaths(struct node *root, int pathArr[], int len){
	if(root == NULL){
		return;
	}
	pathArr[len++] = root->data;
	if(root->left == NULL && root->right == NULL){
		printP(pathArr, len);
	}
	else{
		printPaths(root->left, pathArr, len);
		printPaths(root->right, pathArr, len);
	}
}


int main()
{
	struct node* root = newNode(1);
	root->left = newNode(2);	
	root->right = newNode(3);	
	root->left->left = newNode(4);	
	root->left->right = newNode(5);
	int pathArr[100];
	printPaths(root, pathArr, 0);		
    printf("Hello, World!\n");
    return 0;
}