// WAP to create BST for given set of data.
// WAP to insert an element(a node) in a BST.
// WAP to delete a node/element from BST.

#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
};

struct Node *createNode(int data)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

struct Node *insert(struct Node *root, int data)
{
    if (root == NULL)
    {
        return createNode(data);
    }
    if (data < root->data || data == root->data)
    {
        root->left = insert(root->left, data);
    }
    else if (data > root->data)
    {
        root->right = insert(root->right, data);
    }
    return root;
}

void inOrderTraversal(struct Node *root)
{
    if (root != NULL)
    {
        inOrderTraversal(root->left);
        printf("%d ", root->data);
        inOrderTraversal(root->right);
    }
}
struct Node *getSuccessor(struct Node *curr)
{
    curr = curr->right;
    while (curr != NULL && curr->left != NULL)
        curr = curr->left;
    return curr;
}

struct Node *delNode(struct Node *root, int x)
{

    if (root == NULL)
        return root;

    if (root->data > x)
        root->left = delNode(root->left, x);
    else if (root->data < x)
        root->right = delNode(root->right, x);
    else
    {

        if (root->left == NULL)
        {
            struct Node *temp = root->right;
            free(root);
            return temp;
        }

        if (root->right == NULL)
        {
            struct Node *temp = root->left;
            free(root);
            return temp;
        }

        struct Node *succ = getSuccessor(root);
        root->data = succ->data;
        delNode(root->right, succ->data);
    }
    return root;
}
int main()
{
    struct Node *root = NULL;
    root = createNode(5);
    insert(root, 4);
    insert(root, 3);
    insert(root, 6);
    insert(root, 8);
    insert(root, 7);
    insert(root, 7);

    inOrderTraversal(root);
    printf("\n");
    delNode(root, 4);
    inOrderTraversal(root);
    return 0;
}
