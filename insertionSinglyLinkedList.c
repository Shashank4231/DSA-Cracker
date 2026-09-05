// Insertion at the beginning of a singly linked list

// #include <stdio.h>
// #include <stdlib.h>

// struct node
// {
//     int data;
//     struct node *next;
// };

// void printlist(struct node *head)
// {
//     while (head != NULL)
//     {
//         printf("%d\n", head->data);
//         head = head->next;
//     }
//     printf("\n");
// }

// struct node *createnode(int data)
// {
//     struct node *newnode = (struct node *)malloc(sizeof(struct node));
//     newnode->data = data;
//     newnode->next = NULL;
//     return newnode;
// }

// struct node *insertionAtBeginning(int data, struct node *head)
// {
//     struct node *newnode = createnode(data);
//     newnode->next = head;
//     return newnode;
// }
// int main()
// {
//     struct node *head = createnode(2);
//     struct node *second = createnode(7);
//     struct node *third = createnode(9);
//     struct node *fourth = createnode(6);
//     head->next = second;
//     second->next = third;
//     third->next = fourth;
//     fourth->next = NULL;
//     printlist(head);
//     int data = 8;
//     head = insertionAtBeginning(data,head);
//     printlist(head);
//     return 0;
// }

// Insertion at the end of a singly linked list
// #include <stdio.h>
// #include <stdlib.h>

// struct node
// {
//     int data;
//     struct node *next;
// };

// void printlist(struct node *head)
// {
//     while (head != NULL)
//     {
//         printf("%d\n", head->data);
//         head = head->next;
//     }
//     printf("\n");
// }

// struct node *createnode(int data)
// {
//     struct node *newnode = (struct node *)malloc(sizeof(struct node));
//     newnode->data = data;
//     newnode->next = NULL;
//     return newnode;
// }

// struct node *insertAtLast(int data, struct node *head)
// {
//     struct node *newnode = createnode(data);
//     if(head == NULL){
//         return newnode;
//     }
//     struct node* last = head;
//     while(last->next!=NULL){
//         last = last->next;
//     }
//     last->next = newnode;
//     return head;
// }
// int main()
// {
//     struct node *head = createnode(5);
//     struct node *second = createnode(7);
//     struct node *third = createnode(11);
//     struct node *fourth = createnode(9);
//     head->next = second;
//     second->next = third;
//     third->next = fourth;
//     fourth->next = NULL;
//     printlist(head);
//     int data = 2;
//     head = insertAtLast(data, head);
//     printlist(head);
//     return 0;
// }
