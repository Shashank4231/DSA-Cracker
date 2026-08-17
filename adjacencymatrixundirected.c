#include <stdio.h>
#define V 4

void init(int arr[][V])
{
    int i, j;
    for (i = 0; i < V; i++)
        for (j = 0; j < V; j++)
            arr[i][j] = 0;
}

void addEdge(int arr[][V], int i, int j)
{
    arr[i][j] = 1;
    arr[j][i] = 1;
}

void printAdjMatrix(int arr[][V])
{
    int i, j;

    for (i = 0; i < V; i++)
    {
        printf("%d: ", i);
        for (j = 0; j < V; j++)
        {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }
}

void PathMatrix(int adj[][V], int path[][V])
{
    int i, j, k;
    for (i = 0; i < V; i++)
    {
        for (j = 0; j < V; j++)
        {
            for (k = 0; k < V; k++)
            {
                if (adj[i][k] && adj[k][j])
                    path[i][j] = 1;
            }
        }
    }
}
void multiplyMatrix(int mat1[][V], int mat2[][V], int result[][V])
{
    int i, j, k;

    for (i = 0; i < V; i++)
        for (j = 0; j < V; j++)
            result[i][j] = 0;

    for (i = 0; i < V; i++)
        for (j = 0; j < V; j++)
            for (k = 0; k < V; k++)
                result[i][j] += mat1[i][k] * mat2[k][j];
}

int main()
{
    int adjMatrix[V][V];
    int pathMatrix[V][V];

    init(adjMatrix);
    addEdge(adjMatrix, 0, 1);
    addEdge(adjMatrix, 0, 2);
    addEdge(adjMatrix, 1, 2);
    addEdge(adjMatrix, 1, 3);
    addEdge(adjMatrix, 2, 3);
    addEdge(adjMatrix, 3, 0);
    addEdge(adjMatrix, 3, 1);

    int squaredMatrix[V][V];
    int cubedMatrix[V][V];
    int fourthMatrix[V][V];

    multiplyMatrix(adjMatrix, adjMatrix, squaredMatrix);

    printf("\nAdjacency Matrix Squared (2-step paths):\n");
    printAdjMatrix(squaredMatrix);

    multiplyMatrix(squaredMatrix, adjMatrix, cubedMatrix);
    printf("\nAdjacency Matrix Cubed (A^3 - 3-step paths):\n");
    printAdjMatrix(cubedMatrix);

    
    multiplyMatrix(cubedMatrix, adjMatrix, fourthMatrix);
    printf("\nAdjacency Matrix to the 4th Power (A^4 - 4-step paths):\n");
    printAdjMatrix(fourthMatrix);


    printf("Adjacency Matrix:\n");
    printAdjMatrix(adjMatrix);
    PathMatrix(adjMatrix, pathMatrix);
    printf("\nPath Matrix (Transitive Closure):\n");
    printAdjMatrix(pathMatrix);

    return 0;
}