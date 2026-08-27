#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Node structure
struct Node {
    int data;
    struct Node* next;
};

// Adjacency list
struct List {
    struct Node* head;
};

// Graph structure
struct Graph {
    int vertices;
    struct List* array;
};

// Create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Create a graph
struct Graph* createGraph(int vertices) {
    struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));
    graph->vertices = vertices;
    graph->array = (struct List*)malloc(vertices * sizeof(struct List));
    for (int i = 0; i < vertices; i++)
        graph->array[i].head = NULL;
    return graph;
}

// Add an edge (undirected)
void addEdge(struct Graph* graph, int src, int dest) {
    // Add dest to src's list
    struct Node* newNode = createNode(dest);
    newNode->next = graph->array[src].head;
    graph->array[src].head = newNode;

    // Add src to dest's list (undirected)
    newNode = createNode(src);
    newNode->next = graph->array[dest].head;
    graph->array[dest].head = newNode;
}

// DFS helper function
void DFS(struct Graph* graph, int vertex, bool visited[]) {
    visited[vertex] = true;
    printf("%d ", vertex);

    struct Node* currentNode = graph->array[vertex].head;
    while (currentNode) {
        int adjVertex = currentNode->data;
        if (!visited[adjVertex]) {
            DFS(graph, adjVertex, visited);
        }
        currentNode = currentNode->next;
    }
}

// DFS traversal in given order
void DFSTraversal(struct Graph* graph, int* order, int orderSize) {
    bool* visited = (bool*)malloc(graph->vertices * sizeof(bool));
    for (int i = 0; i < graph->vertices; i++)
        visited[i] = false;

    for (int i = 0; i < orderSize; i++) {
        if (!visited[order[i]]) {
            DFS(graph, order[i], visited);
        }
    }

    free(visited);
}

// Main function
int main() {
    int vertices = 9;
    struct Graph* graph = createGraph(vertices);

    // Creating the graph:
    // 0 -- 1
    // |    |
    // 2 -- 3
    addEdge(graph, 0, 1);
    addEdge(graph, 0, 2);
    addEdge(graph, 0, 3);
    addEdge(graph, 1, 4);
    addEdge(graph, 2, 6);
    addEdge(graph, 2, 1);
    addEdge(graph, 3, 2);
    addEdge(graph, 3, 6);
    addEdge(graph, 4, 5);
    addEdge(graph, 4, 2);
    addEdge(graph, 5, 2);
    addEdge(graph, 5, 7);
    addEdge(graph, 6, 5);
    addEdge(graph, 6, 7);
    addEdge(graph, 6, 8);
    addEdge(graph, 7, 4);
    addEdge(graph, 7, 8);
    addEdge(graph, 8, 5);

    int order[] = {7};  
    int orderSize = sizeof(order) / sizeof(order[0]);

    printf("Following is Depth First Traversal (starting from vertex 7):\n");
    DFSTraversal(graph, order, orderSize);

    return 0;
}