#include <stdio.h>
#include <stdlib.h>

typedef struct Heap
{
    int size;
    int capacity;
    int *arr;
}heap;

void heapify(heap *h, int index);

heap *createheap(int capacity, int *num)
{
    heap *h = (heap *)malloc(sizeof(heap));
    h->capacity = capacity;
    h->size = 0;
    h->arr = (int *)malloc(capacity * sizeof(int));
    int i;
    for (i = 0; i < capacity; i++)
    {
        h->arr[i] = num[i];
    }

    h->size = i;
    i = (h->size - 2) / 2;
    while (i >= 0)
    {
        heapify(h, i);
        i--;
    }
    return h;
}

void swap(heap *h, int index)
{

    int parent = index;

    if (h->arr[parent] < h->arr[index])
    {

        int temp = h->arr[parent];
        h->arr[parent] = h->arr[index];
        h->arr[index] = temp;

        swap(h, parent);
    }
}

void printHeap(heap *h)
{

    for (int i = 0; i < h->size; i++)
    {
        printf("%d ", h->arr[i]);
    }
    printf("\n");
}

void heapify(heap *h, int index)
{
    int left = index ;
    int right = index ;
    int max = index;
    if (left >= h->size || left < 0)
        left = -1;
    if (right >= h->size || right < 0)
        right = -1;

    if (left != -1 && h->arr[left] > h->arr[max])
        max = left;
    if (right != -1 && h->arr[right] > h->arr[max])
        max = right;

    if (max != index)
    {
        int temp = h->arr[max];
        h->arr[max] = h->arr[index];
        h->arr[index] = temp;

        heapify(h, max);
    }
}

int delmax(heap *h)
{
    int deleteItem;
    deleteItem = h->arr[0];
    h->arr[0] = h->arr[h->size - 1];

    h->size--;
    heapify(h, 0);
    return deleteItem;
}

void insert(heap *h, int data)
{

    if (h->size < h->capacity)
    {

        h->arr[h->size] = data;
        swap(h, h->size);
        h->size++;
    }
}

int main()
{
    int arr[9] = {1, 2, 3, 4, 5, 6, 7, 8, 9};

    heap *hp = createheap(9, arr);
    printHeap(hp);
    delmax(hp);
    printHeap(hp);
    return 0;
}