#include <stdio.h>
#include <stdlib.h>

#define VERTICES 9

int PQSize = 0;

// PRIORITY QUEUE FUNCTIONS

struct Edge
{
    int from;
    int to;
    int weight;
};

// CONVENIENCE FUNCTIONS

void printArray(int *array, int n, int m)
{
    for (int i = n; i <= m; i++)
    {
        printf("%d ", array[i]);
    }
    printf("\n");
}

void swap(struct Edge *array, int a, int b)
{
    struct Edge temp = array[a];
    array[a] = array[b];
    array[b] = temp;
}

void fixHeap(struct Edge *PQ, int size, int i)
{
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    if (left > size)
        return;
    int smallest = left;
    if (right <= size && PQ[right].weight < PQ[left].weight)
    {
        smallest = right;
    }
    if (PQ[smallest].weight < PQ[i].weight)
    {
        swap(PQ, smallest, i);
        fixHeap(PQ, size, smallest);
    }
}

void heapify(struct Edge *PQ, int size, int i)
{
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    if (left <= size)
    {
        heapify(PQ, size, left);
    }
    if (right <= size)
    {
        heapify(PQ, size, right);
    }
    fixHeap(PQ, size, i);
}

void insert(struct Edge *PQ, int from, int to, int weight)
{
    if (from > to)
    {
        int temp = from;
        from = to;
        to = temp;
    }
    struct Edge new;
    new.from = from;
    new.to = to;
    new.weight = weight;
    PQ[PQSize] = new;
    swap(PQ, 0, PQSize);
    heapify(PQ, PQSize, 0);
    PQSize++;
}

struct Edge extractMin(struct Edge *PQ)
{
    swap(PQ, 0, PQSize - 1);
    PQSize--;
    struct Edge item;
    item.from = PQ[PQSize].from;
    item.to = PQ[PQSize].to;
    item.weight = PQ[PQSize].weight;
    PQ[PQSize].from = -1;
    PQ[PQSize].to = -1;
    PQ[PQSize].weight = 99999999;
    heapify(PQ, PQSize, 0);
    return item;
}

// GRAPH FUNCTIONS

void addEdge(int **g, int from, int to, int weight)
{
    g[from][to] = weight;
    g[to][from] = weight;
}

void updateFringe(struct Edge *PQ, int **g, int vertex, int *visited, int *verts, int *connectedFrom)
{
    for (int i = 0; i < VERTICES; i++)
    {
        if (g[vertex][i] != 0 && visited[i] != 1)
        {
            int newWeight = g[vertex][i];
            if (newWeight < verts[i])
            {
                verts[i] = newWeight;
                connectedFrom[i] = vertex;
                insert(PQ, vertex, i, newWeight);
            }
        }
    }
}

void prim(int **g)
{
    int verts[VERTICES];
    int visited[VERTICES];
    int connectedFrom[VERTICES];
    for (int i = 0; i < VERTICES; i++)
    {
        verts[i] = 9999999;
        visited[i] = 0;
        connectedFrom[i] = -1;
    }
    connectedFrom[0] = 0;
    verts[0] = 0;
    visited[0] = 1;
    struct Edge PQ[500];
    insert(PQ, 0, 0, 0);
    while (PQSize > 0)
    {
        struct Edge e = extractMin(PQ);
        visited[e.to] = 1;
        updateFringe(PQ, g, e.to, visited, verts, connectedFrom);
    }
    printArray(verts, 0, VERTICES - 1);
    printArray(visited, 0, VERTICES - 1);
    printArray(connectedFrom, 0, VERTICES - 1);
    int sum = 0;
    for (int i = 0; i < VERTICES; i++)
    {
        printf("Linked %d with %d with weight %d\n", connectedFrom[i], i, verts[i]);
        sum += verts[i];
    }
    printf("Total weight: %d\n", sum);
}

int main()
{
    int **g = (int **)malloc(VERTICES * sizeof(int *));
    for (int i = 0; i < VERTICES; i++)
    {
        g[i] = (int *)malloc(VERTICES * sizeof(int));
        for (int j = 0; j < VERTICES; j++)
        {
            g[i][j] = 0;
        }
    }
    addEdge(g, 0, 1, 4);
    addEdge(g, 0, 7, 8);
    addEdge(g, 1, 2, 8);
    addEdge(g, 1, 7, 11);
    addEdge(g, 2, 3, 7);
    addEdge(g, 2, 8, 2);
    addEdge(g, 2, 5, 4);
    addEdge(g, 3, 4, 9);
    addEdge(g, 3, 5, 14);
    addEdge(g, 4, 5, 10);
    addEdge(g, 5, 6, 2);
    addEdge(g, 6, 8, 6);
    addEdge(g, 6, 7, 1);
    addEdge(g, 7, 8, 7);
    prim(g);
}