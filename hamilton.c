#include <stdio.h>
#include <stdbool.h>

#define V 5

int graph[V][V] = {
    {0, 1, 0, 0, 1}, // vertex 1
    {1, 0, 1, 0, 0}, // vertex 2
    {0, 1, 0, 1, 0}, // vertex 3
    {0, 0, 1, 0, 1}, // vertex 4
    {1, 0, 0, 1, 0}  // vertex 5
};

int path[V];
int cycleCount = 0;

bool isSafe(int v, int pos) {
    if (graph[path[pos - 1]][v] == 0)
        return false;

    for (int i = 0; i < pos; i++)
        if (path[i] == v)
            return false;

    return true;
}

void printCycle() {
    cycleCount++;
    printf("Cycle %d: ", cycleCount);
    for (int i = 0; i < V; i++)
        printf("%d ", path[i] + 1);
    printf("%d\n", path[0] + 1); // back to start
}

void hamCycleUtil(int pos) {
    if (pos == V) {
        if (graph[path[pos - 1]][path[0]] == 1)
            printCycle();
        return;
    }

    for (int v = 1; v < V; v++) {
        if (isSafe(v, pos)) {
            path[pos] = v;
            hamCycleUtil(pos + 1);
            path[pos] = -1;
        }
    }
}

void findAllHamiltonianCycles() {
    for (int i = 0; i < V; i++)
        path[i] = -1;

    path[0] = 0;

    hamCycleUtil(1);

    if (cycleCount == 0)
        printf("No Hamiltonian Cycle exists\n");
}

int main() {
    findAllHamiltonianCycles();
    return 0;
}