/* Author: Sahil Narula
Date: 16 June 2015 (Tuesday)
Time: 00:58
Description: lEVEL ORDER TRAVERSAL IN A TREE
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

void levelOrderTraversal(struct node *root, int level){
	if(root == NULL)
		return;
	if(level == 1){
		printf("%d\t", root->data);
	}
	else{
		levelOrderTraversal(root->left, level-1);
		levelOrderTraversal(root->right, level-1);
	}
}

int main()
{
	struct node* root = newNode(1);
	root->left = newNode(2);	
	root->right = newNode(3);	
	root->left->left = newNode(4);	
	root->left->right = newNode(5);
    levelOrderTraversal(root, 2);
    printf("Hello, World!\n");
    return 0;
}