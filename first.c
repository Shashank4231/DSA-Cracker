// #include<stdio.h>
// int sum(int a, int b){
//     int c;
//     c=a+b;
//     return c;
// }
// int main(){
//     int x,y,z;
//     printf("enter the value of x and y");
//     scanf("%d%d",&x,&y);
//     z=sum(x,y);
//     printf("The sum of x and y is %8d", z);

// }
// #include<stdio.h>

// int fact(int n){
//  if(n==0){
//            return 1;
//     }
//         else{
//          return(n*fact(n-1));
//        }
// }
// int main(){
//     int a,c;
//     printf("enter the number");
//     scanf("%d",&a);
//    c=fact(a);
//    printf("The factorial of the given number is %d",c);
// }

// //Swapping of two numbers
// #include<stdio.h>
// void swap(int *x, int *y){
//   int temp;
//   temp = *x;
//   *x = *y;
//   *y = temp;
// }
// int main(){
//   int a,b;
//   printf("enter the value of a and b");
//   scanf("%d%d",&a,&b);
//   printf("Before swapping a=%d,b=%d",a,b);
//   swap(&a,&b);
//   printf("After swapping a=%d,b=%d",a,b);
//   return 0;
// }

#include <stdio.h>
#include <stdlib.h>

// Define the structure for a node in the linked list
typedef struct Node {
    int data;
    struct Node* next;
} Node;

// Function to create a new node
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (!newNode) {
        printf("Memory error\n");
        return NULL;
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to insert a new node at the beginning of the linked list
void insertAtBeginning(Node** head, int data) {
    Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
    } else {
        newNode->next = *head;
        *head = newNode;
    }
}

// Function to insert a new node at the end of the linked list
void insertAtEnd(Node** head, int data) {
    Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
    } else {
        Node* temp = *head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

// Function to delete a node from the linked list
void deleteNode(Node** head, int key) {
    if (*head == NULL) return;

    // If the node to be deleted is the head node
    if ((*head)->data == key) {
        Node* temp = *head;
        *head = (*head)->next;
        free(temp);
        return;
    }

    Node* temp = *head;
    while (temp->next != NULL) {
        if (temp->next->data == key) {
            Node* nodeToDelete = temp->next;
            temp->next = temp->next->next;
            free(nodeToDelete);
            return;
        }
        temp = temp->next;
    }
}

// Function to print the linked list
void printList(Node* head) {
    while (head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

int main() {
    Node* head = NULL;

    // Insert elements into the linked list
    insertAtEnd(&head, 10);
    insertAtEnd(&head, 20);
    insertAtEnd(&head, 30);
    insertAtEnd(&head, 40);
    insertAtEnd(&head, 50);

    printf("Linked List: ");
    printList(head);

    // Delete a node from the linked list
    deleteNode(&head, 30);

    printf("Linked List after deletion: ");
    printList(head);

    return 0;
}
