
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};


struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}


struct Node* insert(struct Node* root, int data) {
    if (root == NULL) {
        return createNode(data);
    }
    if (data < root->data) {
        root->left = insert(root->left, data);
    } else {
        root->right = insert(root->right, data);
    }
    return root;
}


struct Node* search(struct Node* root, int key) {
    
    if (root == NULL || root->data == key) {
        return root;
    }

    
    if (key > root->data) {
        return search(root->right, key);
    }

    
    return search(root->left, key);
}


int main() {
    struct Node* root = NULL;

   
    root = insert(root, 50);
    insert(root, 30);
    insert(root, 20);
    insert(root, 40);
    insert(root, 70);
    insert(root, 60);
    insert(root, 80);

    int key;
    printf("Enter the element to search: ");
    scanf("%d", &key);

    struct Node* result = search(root, key);
    if (result != NULL) {
        printf("Element %d found in the binary search tree.\n", key);
    } else {
        printf("Element %d not found in the binary search tree.\n", key);
    }

    return 0;
}