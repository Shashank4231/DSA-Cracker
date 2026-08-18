
// BFS Algorithm
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 50

typedef struct Graph_t
{
    int V;
    bool adj[MAX_VERTICES][MAX_VERTICES];
} Graph;

Graph *Graph_create(int V)
{
    Graph *g = malloc(sizeof(Graph));
    g->V = V;
    for (int i = 0; i < V; i++)
        for (int j = 0; j < V; j++)
            g->adj[i][j] = false;
    return g;
}

void Graph_destroy(Graph *g)
{
    free(g);
}

void Graph_addEdge(Graph *g, int v, int w)
{
    g->adj[v][w] = true;
}

void Graph_BFS(Graph *g, int s)
{
    bool visited[MAX_VERTICES] = {false};
    int queue[MAX_VERTICES];
    int front = 0, rear = 0;

    visited[s] = true;
    queue[rear++] = s;

    while (front != rear)
    {
        s = queue[front++];
        printf("%c ", s + 'A');

        for (int adjacent = 0; adjacent < g->V; adjacent++)
        {
            if (g->adj[s][adjacent] && !visited[adjacent])
            {
                visited[adjacent] = true;
                queue[rear++] = adjacent;
            }
        }
    }
}

int main()
{
    Graph *g = Graph_create(9);

    // Adding edges from the image
    Graph_addEdge(g, 0, 1); // A → B
    Graph_addEdge(g, 0, 2); // A → C
    Graph_addEdge(g, 0, 3); // A → D
    Graph_addEdge(g, 1, 4); // B → E
    Graph_addEdge(g, 2, 1); // C → B
    Graph_addEdge(g, 2, 6); // C → G
    Graph_addEdge(g, 3, 2); // D -> C
    Graph_addEdge(g, 3, 6); // D → G
    Graph_addEdge(g, 4, 2); // E → C
    Graph_addEdge(g, 4, 5); // E → F
    Graph_addEdge(g, 5, 2); // F → C
    Graph_addEdge(g, 5, 7); // F → H
    Graph_addEdge(g, 6, 5); // G → F
    Graph_addEdge(g, 6, 8); // G → I
    Graph_addEdge(g, 7, 4); // H → E
    Graph_addEdge(g, 7, 8); // H → I
    Graph_addEdge(g, 8, 5); // I → F

    printf("Following is Breadth First Traversal (starting from vertex A):\n");
    Graph_BFS(g, 0); // Start from A (index 0)

    Graph_destroy(g);
    return 0;
}
