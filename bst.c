#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *left;
    struct node *right;
};

struct node *createnode(int data)
{
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = data;
    newnode->left = NULL;
    newnode->right = NULL;
    return newnode;
}

struct node* insert(int data, struct node *root)
{
    if (root == NULL)
    {
        return createnode(data);
    }
    if (data < root->data)
    {
    root->left = insert(data, root->left);
    }
    else if(data > root->data)
    {
    root->right = insert(data, root->right);
    }
    return root;
}

void inorder(struct node *root)
{
    if(root != NULL)
    {
        inorder(root->left);
        printf("%d\n", root->data);
        inorder(root->right);
    }
}

int main()
{
    struct node *root = createnode(50);
    insert(30, root);
    insert(20, root);
    insert(70, root);
    insert(60, root);
    insert(40, root);

    inorder(root);
    return 0;
}