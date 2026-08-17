#include <stdio.h>

#define V 4

void displayMatrix(int matrix[V][V], const char *name)
{
    printf("%s:\n", name);
    for (int i = 0; i < V; i++)
    {
        for (int j = 0; j < V; j++)
        {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

void multiplyMatrix(int a[V][V], int b[V][V], int result[V][V])
{
    for (int i = 0; i < V; i++)
    {
        for (int j = 0; j < V; j++)
        {
            result[i][j] = 0;
            for (int k = 0; k < V; k++)
            {
                result[i][j] += a[i][k] * b[k][j];
            }
        }
    }
}

void addMatrices(int a[V][V], int b[V][V], int result[V][V])
{
    for (int i = 0; i < V; i++)
    {
        for (int j = 0; j < V; j++)
        {
            result[i][j] = a[i][j] + b[i][j];
        }
    }
}

void warshallAlgorithm(int adj[V][V], int path[V][V])
{
    for (int i = 0; i < V; i++)
        for (int j = 0; j < V; j++)
            path[i][j] = adj[i][j];

    for (int k = 0; k < V; k++)
        for (int i = 0; i < V; i++)
            for (int j = 0; j < V; j++)
                path[i][j] = path[i][j] || (path[i][k] && path[k][j]);
}

int main()
{

    int adj[V][V] = {
        {0, 1, 1, 0},
        {0, 0, 1, 1},
        {0, 0, 0, 1},
        {1, 1, 0, 0}};

    int a2[V][V], a3[V][V], a4[V][V];
    int totalPath[V][V];
    int path[V][V];
    int temp1[V][V], temp2[V][V];

    displayMatrix(adj, "Adjacency Matrix (A)");

    multiplyMatrix(adj, adj, a2);
    displayMatrix(a2, "A^2 Matrix");

    multiplyMatrix(a2, adj, a3);
    displayMatrix(a3, "A^3 Matrix");

    multiplyMatrix(a3, adj, a4);
    displayMatrix(a4, "A^4 Matrix");

    addMatrices(adj,a2,temp1);
    addMatrices(temp1,a3,temp2);
    addMatrices(temp2,a4,totalPath);

    displayMatrix(totalPath,"Total Path Matrix(A+A^2+A^3+A^4)");

    warshallAlgorithm(adj, path);
    displayMatrix(path, "Path Matrix (Transitive Closure)");
    return 0;
}