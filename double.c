#include<stdio.h>
#include<stdlib.h>
struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
};
void addElement(struct Node** head, int data){
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = *head;
    if (*head != NULL) {
        (*head)->prev = newNode;
    }
    *head = newNode;
}
void traverse(struct Node* head){
    while(head != NULL){
        printf("%d",head->data);
        head = head->next;
    }
    printf("\n");
}
int main(){
    struct Node* head = NULL;
    addElement(&head, 1);
    addElement(&head, 2);
    addElement(&head, 3);
    addElement(&head, 4);
    addElement(&head, 5);
     traverse(head);

    return 0;
 }

    
