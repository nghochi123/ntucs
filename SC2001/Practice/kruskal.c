#include <stdlib.h>
#include <stdio.h>

int SIZE = 10;

// Union Find Algorithms

struct QUArray
{
    int *array;
    int size;
    int *sz;
};

void printArray(struct QUArray array)
{
    for (int i = 0; i < array.size; i++)
    {
        printf("%d ", array.array[i]);
    }
    printf("\n");
}

struct QUArray createArray(int numItems)
{
    struct QUArray array;
    array.array = malloc(numItems * sizeof(int));
    array.size = numItems;
    for (int i = 0; i < numItems; i++)
    {
        array.array[i] = i;
    }
    array.sz = malloc(sizeof(int) * SIZE);
    for (int i = 0; i < SIZE; i++)
    {
        array.sz[i] = 1;
    }
    return array;
}

int pcfind(struct QUArray array, int id)
{
    if (array.array[id] != id)
    {
        int rootID = pcfind(array, array.array[id]);
        array.array[id] = rootID;
        return rootID;
    }
    return id;
}

void wquni(struct QUArray *array, int firstID, int secondID)
{
    int a = pcfind(*array, firstID);
    int b = pcfind(*array, secondID);
    if (array->sz[a] < array->sz[b])
    {
        array->array[a] = b;
        array->sz[b] += a;
    }
    else
    {
        array->array[b] = a;
        array->sz[a] += b;
    }
}

// Storing Edges + Sorting them

struct Edge
{
    int from;
    int to;
    int weight;
};

struct EdgeStore
{
    struct Edge *edgeArray;
    int size;
};

struct EdgeStore createEdgeStore()
{
    struct EdgeStore edgeStore;
    edgeStore.edgeArray = malloc(sizeof(struct Edge));
    edgeStore.size = 1;
    return edgeStore;
}

void fixHeap(struct EdgeStore *store, int i, int n)
{
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    if (left >= store->size)
        return;
    int smallest = left;
    if (right < store->size && store->edgeArray[right].weight < store->edgeArray[left].weight)
    {
        smallest = right;
    }
    if (store->edgeArray[smallest].weight < store->edgeArray[i].weight)
    {
        struct Edge temp = store->edgeArray[smallest];
        store->edgeArray[smallest] = store->edgeArray[i];
        store->edgeArray[i] = temp;
        fixHeap(store, i, n);
    }
}

void heapify(struct EdgeStore *store, int i, int n)
{
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    if (left < store->size)
    {
        heapify(store, left, n);
    }
    if (right < store->size)
    {
        heapify(store, right, n);
    }
    fixHeap(store, i, n);
}

struct Edge getMin(struct EdgeStore *store)
{
    struct Edge ret, temp = store->edgeArray[0];
    ret.weight = temp.weight;
    ret.from = temp.from;
    ret.to = temp.to;
    store->size--;
    store->edgeArray[0] = store->edgeArray[store->size - 1];
    store->edgeArray[store->size - 1] = temp;
    store->edgeArray[store->size - 1].weight = 99999999;
    heapify(store, 0, store->size - 2);
    return ret;
}

// GRAPH FUNCTIONS

int **createGraph(int numVertices)
{
    int **g = malloc(sizeof(int *) * numVertices);
    for (int i = 0; i < numVertices; i++)
    {
        g[i] = malloc(sizeof(int) * numVertices);
        for (int j = 0; j < numVertices; j++)
        {
            g[i][j] = 0;
        }
    }
    return g;
}

void printGraphMatrix(int **graph, int vertices)
{
    for (int i = 0; i < vertices; i++)
    {
        for (int j = 0; j < vertices; j++)
        {
            printf("%d ", graph[i][j]);
        }
        printf("\n");
    }
}

void printEdgeStore(struct EdgeStore edgeStore)
{
    printf("Size: %d\n", edgeStore.size);
    for (int i = 0; i < edgeStore.size - 1; i++)
    {

        printf("%d %d %d\n", edgeStore.edgeArray[i].from, edgeStore.edgeArray[i].to, edgeStore.edgeArray[i].weight);
    }
}

void addEdge(int **graph, int from, int to, int weight, struct EdgeStore *edgeStore)
{
    graph[from][to] = weight;
    graph[to][from] = weight;
    struct Edge edge;
    edge.from = from;
    edge.to = to;
    edge.weight = weight;
    edgeStore->edgeArray[edgeStore->size - 1] = edge;
    edgeStore->size++;
    edgeStore->edgeArray = realloc(edgeStore->edgeArray, edgeStore->size * sizeof(struct Edge));
    heapify(edgeStore, 0, edgeStore->size - 1);
}

// Kruskal
void kruskal(struct EdgeStore edgeStore)
{
    int sum = 0;
    struct QUArray checkConnected = createArray(10); // Graph Size
    while (edgeStore.size > 0)
    {
        struct Edge edge = getMin(&edgeStore);
        if (pcfind(checkConnected, edge.from) != pcfind(checkConnected, edge.to))
        {
            wquni(&checkConnected, edge.from, edge.to);
            printf("Linked %d with %d with weight %d\n", edge.from, edge.to, edge.weight);
            sum += edge.weight;
        }
    }
    printf("Shortest length:%d\n", sum);
}

int main()
{
    struct QUArray array = createArray(SIZE);
    int **g = createGraph(10);
    struct EdgeStore edgeStore = createEdgeStore();
    // printArray(array);
    // printGraphMatrix(g, 10);
    addEdge(g, 0, 1, 4, &edgeStore);
    addEdge(g, 0, 7, 8, &edgeStore);
    addEdge(g, 1, 2, 8, &edgeStore);
    addEdge(g, 1, 7, 11, &edgeStore);
    addEdge(g, 2, 3, 7, &edgeStore);
    addEdge(g, 2, 8, 2, &edgeStore);
    addEdge(g, 2, 5, 4, &edgeStore);
    addEdge(g, 3, 4, 9, &edgeStore);
    addEdge(g, 3, 5, 14, &edgeStore);
    addEdge(g, 4, 5, 10, &edgeStore);
    addEdge(g, 5, 6, 2, &edgeStore);
    addEdge(g, 6, 8, 6, &edgeStore);
    addEdge(g, 6, 7, 1, &edgeStore);
    addEdge(g, 7, 8, 7, &edgeStore);
    kruskal(edgeStore);
}