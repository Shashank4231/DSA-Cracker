// #include <stdio.h>  
// #include <stdlib.h>  
// #define SIZE 4  
// int top = -1, inp_array[SIZE];  
// void push();  
// void pop();  
// void show();  
// int main()  
// {  
//     int choice;  
//     while (1)  
//     {  
//         printf("\nPerform operations on the stack:");  
//         printf("\n1.Push the element\n2.Pop the element\n3.Show\n4.End");  
//         printf("\n\nEnter the choice: ");  
//         scanf("%d", &choice);  
//         switch (choice)  
//         {  
//         case 1:  
//             push();  
//             break;  
//         case 2:  
//             pop();  
//             break;  
//         case 3:  
//             show();  
//             break;  
//         case 4:  
//             exit(0);  
//         // default:  
//         //     printf("\nInvalid choice!!");  
//         }  
//     }  
// }  
// void push()  
// {  
//     int x;  
//     if (top == SIZE - 1)  
//     {  
//         printf("\nOverflow!!");  
//     }  
//     else  
//     {  
//         printf("\nEnter the element to be added onto the stack: ");  
//         scanf("%d", &x);  
//         top = top + 1;  
//         inp_array[top] = x;  
//     }  
// }  
// void pop()  
// {  
//     if (top == -1)  
//     {  
//         printf("\nUnderflow!!");  
//     }  
//     else  
//     {  
//         printf("\nPopped element: %d", inp_array[top]);  
//         top = top - 1;  
//     }  
// }  
// void show()  
// {  
//     if (top == -1)  
//     {  
//         printf("\nUnderflow!!");  
//     }  
//     else  
//     {  
//         printf("\nElements present in the stack: \n");  
//         for (int i = top; i >= 0; --i)  
//             printf("%d\n", inp_array[i]);  
//     }  
// } 
#define SIZE 5
#include<stdio.h>
int queue[SIZE];  
int front = -1;  
int rear = -1;  
  
void enqueue(int element) {  
    if (rear == SIZE - 1) {  
        printf("Queue is full");  
        return;  
    }  
    if (front == -1) {  
        front = 0;  
    }  
    rear++;  
    queue[rear] = element;  
}  
  
int dequeue() {  
    if (front == -1 || front > rear) {  
        printf("Queue is empty");   
        return -1;  
    }  
    int element = queue[front];  
    front++;  
    return element;  
}  
  
int main() {  
    enqueue(10);  
    enqueue(20);  
    enqueue(30);  
    enqueue(40);
    enqueue(50);
    
    printf("%d\n ", dequeue());  
    printf("%d\n ", dequeue());  
    printf("%d\n ", dequeue());  
    printf("%d\n", dequeue());  
    printf("%d\n", dequeue());  
    printf("%d\n", dequeue());  
      
    return 0;  
} 
 
// #include<stdio.h>
// #include<stdlib.h>
// typedef struct Node{
//     int data;
//     struct Node*next;
// }Node;
// Node* createNode(int data) {
//     Node* newNode = (Node*)malloc(sizeof(Node));
//      if (!newNode) {
//         printf("Memory error\n");
//         return NULL;
//     }
//     newNode->data = data;
//     newNode->next = NULL;
//     return newNode;
// }
// void insertAtBeginning(Node**head, int data){
//     Node*newNode = createNode(data);
//     if(*head == NULL){
//         *head = newNode;
//     }
//     else{
//         newNode->next = *head;
//         *head = newNode;
//     }
// }
// void insertAtEnd(Node** head, int data) {
//     Node* newNode = createNode(data);
//     if (*head == NULL) {
//         *head = newNode;
//     } else {
//         Node* temp = *head;
//         while (temp->next != NULL) {
//             temp = temp->next;
//         }
//         temp->next = newNode;
//     }
// }
// void deleteNode(Node** head, int key) {
//     if (*head == NULL) return;

//     // the node to be deleted is the head node
//     if ((*head)->data == key) {
//         Node* temp = *head;
//         *head = (*head)->next;
//         free(temp);
//         return;
//     }

//     Node* temp = *head;
//     while (temp->next != NULL) {
//         if (temp->next->data == key) {
//             Node* nodeToDelete = temp->next;
//             temp->next = temp->next->next;
//             free(nodeToDelete);
//             return;
//         }
//         temp = temp->next;
//     }
// }

// // print the linked list
// void printList(Node* head) {
//     while (head != NULL) {
//         printf("%d ", head->data);
//         head = head->next;
//     }
//     printf("\n");
// }

// int main() {
//     Node* head = NULL;

//     // Insert elements into the linked list
//     insertAtEnd(&head, 10);
//     insertAtEnd(&head, 20);
//     insertAtEnd(&head, 30);
//     insertAtEnd(&head, 40);
//     insertAtEnd(&head, 50);

//     printf("Linked List: ");
//     printList(head);

//     // Delete a node from the linked list
//     deleteNode(&head, 30);

//     printf("Linked List after deletion: ");
//     printList(head);

//     return 0;
// }

