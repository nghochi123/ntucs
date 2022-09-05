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

// Graph Stuff

struct AdjListNode
{
    int dest;
    int weight;
    struct AdjListNode *next;
};

struct AdjList
{
    struct AdjListNode *head;
};

struct Graph
{
    int V;
    struct AdjList *array;
};

struct AdjListNode *newAdjListNode(
    int dest, int weight)
{
    struct AdjListNode *newNode =
        (struct AdjListNode *)
            malloc(sizeof(struct AdjListNode));
    newNode->dest = dest;
    newNode->weight = weight;
    newNode->next = NULL;
    return newNode;
}

struct Graph *createGraph(int V)
{
    struct Graph *graph = (struct Graph *)
        malloc(sizeof(struct Graph));
    graph->V = V;
    graph->array = (struct AdjList *)
        malloc(V * sizeof(struct AdjList));
    for (int i = 0; i < V; ++i)
        graph->array[i].head = NULL;

    return graph;
}

void addEdge(struct Graph *graph, int src,
             int dest, int weight)
{
    struct AdjListNode *newNode =
        newAdjListNode(dest, weight);
    newNode->next = graph->array[src].head;
    graph->array[src].head = newNode;
    newNode = newAdjListNode(src, weight);
    newNode->next = graph->array[dest].head;
    graph->array[dest].head = newNode;
}

struct Node
{
    int source;
    int dest;
    int weight;
};

void printGraphList(struct Graph *graph, int vertices)
{
    for (int i = 0; i < vertices; i++)
    {
        struct AdjListNode *hd = (graph->array)[i].head;
        while (hd != NULL)
        {
            printf("Source:%d Dest: %d Weight: %d\n", i, hd->dest, hd->weight);
            hd = hd->next;
        }
    }
}

void swapEdge(struct Node *PQ, int a, int b)
{
    struct Node temp = PQ[a];
    PQ[a] = PQ[b];
    PQ[b] = temp;
}

// Priority Queue

void fixHeap(struct Node *PQ, int n, int i)
{
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    if (left > n)
        return;
    int smallest = left;
    if (right <= n && PQ[right].weight < PQ[smallest].weight)
    {
        smallest = right;
    }
    if (PQ[smallest].weight < PQ[i].weight)
    {
        swapEdge(PQ, i, smallest);
        fixHeap(PQ, n, smallest);
    }
}

void heapify(struct Node *PQ, int n, int i)
{
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    if (left <= n)
    {
        heapify(PQ, n, left);
    }
    if (right <= n)
    {
        heapify(PQ, n, right);
    }
    fixHeap(PQ, n, i);
}

void insert(struct Node *PQ, int dest, int totalWeight)
{
    struct Node new;
    new.dest = dest;
    new.weight = totalWeight;
    PQ[curSize] = new;
    heapify(PQ, curSize, 0);
    curSize++;
}

int getMinimumWeight(struct Node *PQ)
{
    return PQ[0].weight;
}

struct Node checkMin(struct Node *PQ)
{
    return PQ[0];
}

struct Node extractMin(struct Node *PQ)
{
    swapEdge(PQ, 0, curSize - 1);
    curSize--;
    struct Node mx = PQ[curSize];
    struct Node new;
    new.source = -1;
    new.dest = -1;
    new.weight = 99999999;
    PQ[curSize] = new;
    heapify(PQ, curSize, 0);
    return mx;
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
    // Source is 0.
    dist[0] = 0;
    insert(PQ, 0, 0);
    while (curSize > 0)
    {
        struct Node pqMin = extractMin(PQ);
        int index = pqMin.dest;
        visited[index] = 1;
        struct AdjListNode *curNode = g->array[index].head;
        while (curNode != NULL)
        {
            if (visited[curNode->dest] == 1)
            {
                curNode = curNode->next;
                continue;
            }
            int newDist = dist[index] + curNode->weight;
            if (newDist < dist[curNode->dest])
            {
                dist[curNode->dest] = newDist;
                insert(PQ, curNode->dest, newDist);
            }
            curNode = curNode->next;
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
    printGraphList(g, VER);
    printArray(dist, 0, VER - 1);
}