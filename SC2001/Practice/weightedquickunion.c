#include <stdlib.h>
#include <stdio.h>

int SIZE = 10;
int *sz;

struct QUArray
{
    int *array;
    int size;
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

int fnd(struct QUArray array, int id)
{
    if (array.array[id] != id)
    {
        return fnd(array, array.array[id]);
    }
    return id;
}

void wquni(struct QUArray array, int firstID, int secondID)
{
    int a = fnd(array, firstID);
    int b = fnd(array, secondID);
    if (sz[a] < sz[b])
    {
        array.array[a] = b;
        sz[b] += a;
    }
    else
    {
        array.array[b] = a;
        sz[a] += b;
    }
    printArray(array);
}

int main()
{
    struct QUArray array = createArray(SIZE);
    sz = malloc(sizeof(int) * SIZE);
    for (int i = 0; i < SIZE; i++)
    {
        sz[i] = 1;
    }
    printArray(array);
    wquni(array, 3, 4);
    wquni(array, 4, 9);
    wquni(array, 8, 0);
    wquni(array, 2, 3);
    wquni(array, 5, 6);
    wquni(array, 5, 9);
    wquni(array, 7, 3);
    wquni(array, 4, 8);
    wquni(array, 6, 1);
    printArray(array);
}