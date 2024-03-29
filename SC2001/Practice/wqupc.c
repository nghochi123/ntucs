#include <stdlib.h>
#include <stdio.h>

int SIZE = 10;

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

void wquni(struct QUArray array, int firstID, int secondID)
{
    int a = pcfind(array, firstID);
    int b = pcfind(array, secondID);
    if (array.sz[a] < array.sz[b])
    {
        array.array[a] = b;
        array.sz[b] += a;
    }
    else
    {
        array.array[b] = a;
        array.sz[a] += b;
    }
    printArray(array);
}

int main()
{
    struct QUArray array = createArray(SIZE);
    array.sz = malloc(sizeof(int) * SIZE);
    for (int i = 0; i < SIZE; i++)
    {
        array.sz[i] = 1;
    }
    printArray(array);
    // wquni(array, 3, 4);
    // wquni(array, 4, 9);
    // wquni(array, 8, 0);
    // wquni(array, 2, 3);
    // wquni(array, 5, 6);
    // wquni(array, 5, 9);
    // wquni(array, 7, 3);
    // wquni(array, 4, 8);
    // wquni(array, 6, 1);
    wquni(array, 4, 3);
    wquni(array, 3, 8);
    wquni(array, 6, 5);
    wquni(array, 9, 4);
    wquni(array, 2, 1);
    wquni(array, 5, 0);
    printArray(array);
}