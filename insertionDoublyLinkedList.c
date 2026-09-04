// Insertion at the front of a doubly linked list
// #include <stdio.h>
// #include <stdlib.h>

// struct node
// {
//     int data;
//     struct node *next;
//     struct node *prev;
// };

// void forwardTraversal(struct node *head)
// {
//     while (head != NULL)
//     {
//         printf("%d\n", head->data);
//         head = head->next;
//     }
//     printf("\n");
// }

// void backwardTraversal(struct node *tail)
// {
//     while (tail != NULL)
//     {
//         printf("%d\n", tail->data);
//         tail = tail->prev;
//     }
//     printf("\n");
// }

// struct node *createnode(int data)
// {
//     struct node *newnode = (struct node *)malloc(sizeof(struct node));
//     newnode->data = data;
//     newnode->next = NULL;
//     newnode->prev = NULL;
//     return newnode;
// }

// struct node *insertFront(int data, struct node *head)
// {
//     struct node *newnode = createnode(data);
//     newnode->next = head;
//     head->prev = newnode;
//     newnode->prev = NULL;
//     return newnode;
// }

// int main()
// {
//     struct node *head = createnode(5);
//     struct node *second = createnode(7);
//     struct node *third = createnode(9);
//     struct node *fourth = createnode(11);

//     head->prev = NULL;
//     head->next = second;

//     second->prev = head;
//     second->next = third;

//     third->prev = second;
//     third->next = fourth;

//     fourth->prev = third;
//     fourth->next = NULL;

//     forwardTraversal(head);
//     backwardTraversal(fourth);

//     head = insertFront(13, head);

//     forwardTraversal(head);
//     backwardTraversal(fourth);

//     return 0;
// }

// Insertion at the end of a doubly linked list

// #include <stdio.h>
// #include <stdlib.h>

// struct node
// {
//     int data;
//     struct node *next;
//     struct node *prev;
// };

// void forwardTraversal(struct node *head)
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
//     newnode->prev = NULL;
//     return newnode;
// }

// struct node *insertEnd(int data, struct node *head)
// {
//     struct node *newnode = createnode(data);
//     if (head == NULL)
//     {
//         head = newnode;
//     }
//     else
//     {
//         struct node *curr = head;
//         while (curr->next != NULL)
//         {
//             curr = curr->next;
//         }
//         curr->next = newnode;
//         newnode->prev = curr;
//     }
//     return head;
// }

// int main()
// {
//     struct node *head = createnode(5);
//     struct node *second = createnode(7);
//     struct node *third = createnode(9);
//     struct node *fourth = createnode(11);

//     head->prev = NULL;
//     head->next = second;

//     second->prev = head;
//     second->next = third;

//     third->prev = second;
//     third->next = fourth;

//     fourth->prev = third;
//     fourth->next = NULL;

//     forwardTraversal(head);
//     head = insertEnd(13, head);
//     forwardTraversal(head);

//     return 0;
// }
