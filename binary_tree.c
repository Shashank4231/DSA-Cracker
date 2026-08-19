// write a program to create a binary tree and  insert the data.

#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node* left;
    struct Node* right;
};

void inorderTraversal(struct Node* root){
    if(root==NULL){
        return;
    }
    inorderTraversal(root->left);
    printf("%d-",root->data);
    inorderTraversal(root->right);
}

struct Node* createNode(int data){
    struct Node* newnode = (struct Node*)malloc(sizeof(struct Node));
    newnode->data = data;
    newnode->left = NULL;
    newnode->right = NULL;
    return newnode;
}

int main(){
    struct Node* root = NULL;
    root = createNode(5);
    root->left = createNode(9);
    root->right = createNode(17);
    root->left->left = createNode(12);
    root->left->right = createNode(3);

    inorderTraversal(root);
    printf("\n");
   
}
