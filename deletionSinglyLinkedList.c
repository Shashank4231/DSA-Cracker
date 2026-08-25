Deletion from front in a singly linked list
#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *deletionAtFront(struct node *head)
{
    if (head == NULL)
        return NULL;
    struct node *temp = head;
    head = head->next;
    free(temp);
    return head;
}

void printlist(struct node *head)
{
    while (head != NULL)
    {
        printf("%d\n", head->data);
        head = head->next;
    }
    printf("\n");
}

struct node *createnode(int data)
{
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = data;
    newnode->next = NULL;
    return newnode;
}

int main()
{
    struct node *head = createnode(2);
struct node *second = createnode(7);
struct node *third = createnode(9);
struct node *fourth = createnode(6);
head->next = second;
second->next = third;
third->next = fourth;
fourth->next = NULL;
    head->next = createnode(7);
    head->next->next = createnode(9);
    head->next->next->next = createnode(6);
    printlist(head);
    head = deletionAtFront(head);
    printlist(head);
    return 0;
}

Deletion from the end in a singly linked list

#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *deleteLast(struct node *head)
{
    if (head == NULL)
        return NULL;

    if (head->next == NULL)
    {
        free(head);
        return NULL;
    }
    struct node *secondlast = head;
    while (secondlast->next->next != NULL)
    {
        secondlast = secondlast->next;
    }
    free(secondlast->next);
    secondlast->next = NULL;
    return head;
}

void printlist(struct node *head)
{
    while (head != NULL)
    {
        printf("%d\n", head->data);
        head = head->next;
    }
    printf("\n");
}

struct node *createnode(int data)
{
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = data;
    newnode->next = NULL;
    return newnode;
}

int main()
{
    struct node *head = createnode(3);
    head->next = createnode(5);
    head->next->next = createnode(7);
    head->next->next->next = createnode(9);
    printlist(head);
    head = deleteLast(head);
    printlist(head);
    return 0;
}