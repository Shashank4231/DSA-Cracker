#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
    struct node *prev;
};

void forwardTraversal(struct node *head)
{
    while (head != NULL)
    {
        printf("%d\n", head->data);
        head = head->next;
    }
}

void backwardTraversal(struct node *tail)
{
    while (tail != NULL)
    {
        printf("%d\n", tail->data);
        tail = tail->prev;
    }
}

int main()
{
    struct node *first = (struct node *)malloc(sizeof(struct node));
    struct node *second = (struct node *)malloc(sizeof(struct node));
    struct node *third = (struct node *)malloc(sizeof(struct node));
    struct node *fourth = (struct node *)malloc(sizeof(struct node));

    first->data = 9;
    first->prev = NULL;
    first->next = second;

    second->data = 13;
    second->prev = first;
    second->next = third;

    third->data = 7;
    third->prev = second;
    third->next = fourth;

    fourth->data = 10;
    fourth->prev = third;
    fourth->next = NULL;

    forwardTraversal(first);
    backwardTraversal(fourth);

    return 0;
}