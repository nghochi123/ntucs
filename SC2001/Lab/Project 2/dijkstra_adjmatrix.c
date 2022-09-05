#include <stdio.h>
#include <stdlib.h>

#define VER 10

int curSize = 0;

void printArray(int *array, int n, int m)
{
    for (int i = n; i <= m; i++)
    {
        printf("%d ", array[i]);
    }
    printf("\n");
}

struct Graph
{
    int V;
    int **array;
};

struct Graph *createGraph(int V)
{
    struct Graph *graph = (struct Graph *)
        malloc(sizeof(struct Graph));
    graph->V = V;
    graph->array = (int **)malloc(V * sizeof(int *));
    for (int i = 0; i < V; i++)
    {
        graph->array[i] = (int *)malloc(V * sizeof(int));
        for (int j = 0; j < V; j++)
        {
            graph->array[i][j] = -1;
        }
    }
    return graph;
}

void printGraphMatrix(struct Graph *graph, int vertices)
{
    for (int i = 0; i < vertices; i++)
    {
        for (int j = 0; j < vertices; j++)
        {
            printf("%d ", graph->array[i][j]);
        }
        printf("\n");
    }
}

void addEdge(struct Graph *graph, int src, int dest, int weight)
{
    graph->array[src][dest] = weight;
    graph->array[dest][src] = weight;
}

// Priority Queue

struct Node
{
    int dest;
    int weight;
};

void insert(struct Node *PQ, int dest, int totalWeight)
{
    struct Node new;
    new.dest = dest;
    new.weight = totalWeight;
    PQ[curSize] = new;
    curSize++;
}

struct Node extractMin(struct Node *PQ)
{
    int min = PQ[0].weight;
    int minDex = 0;
    for (int i = 0; i < curSize; i++)
    {
        if (PQ[i].weight < min)
        {
            min = PQ[i].weight;
            minDex = i;
        }
    }
    struct Node returnNode = PQ[minDex];
    for (int i = minDex; i < curSize; i++)
    {
        PQ[i] = PQ[i + 1];
    }
    curSize--;
    return returnNode;
}

void dijkstra(struct Graph *g, int *dist)
{
    struct Node PQ[500];
    int visited[VER];
    for (int i = 0; i < VER; i++)
    {
        visited[i] = 0;
        dist[i] = 99999999;
    }
    dist[0] = 0;
    insert(PQ, 0, 0);
    while (curSize > 0)
    {
        struct Node currentNode = extractMin(PQ);
        visited[currentNode.dest] = 1;
        for (int i = 0; i < VER; i++)
        {

            if (g->array[currentNode.dest][i] != -1)
            {
                if (visited[i] != 1)
                {
                    int newDist = dist[currentNode.dest] + g->array[currentNode.dest][i];
                    if (newDist < dist[i])
                    {
                        dist[i] = newDist;
                        insert(PQ, i, newDist);
                    }
                }
            }
        }
    }
    printArray(visited, 0, VER - 1);
}

int main()
{
    struct Graph *g = createGraph(VER);
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
    int dist[VER];
    dijkstra(g, dist);
    printGraphMatrix(g, VER);
    printArray(dist, 0, VER - 1);
}