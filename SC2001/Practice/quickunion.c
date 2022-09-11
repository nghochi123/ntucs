#include <stdlib.h>
#include <stdio.h>

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

int fd(struct QUArray array, int id)
{
    if (array.array[id] != id)
    {
        return fd(array, array.array[id]);
    }
    return id;
}

void quickunion(struct QUArray array, int firstID, int secondID)
{
    int a = fd(array, firstID);
    int b = fd(array, secondID);
    array.array[a] = b;
    printArray(array);
}

int main()
{
    struct QUArray array = createArray(10);
    printArray(array);
    quickunion(array, 4, 3);
    quickunion(array, 3, 8);
    quickunion(array, 6, 5);
    quickunion(array, 9, 4);
    printArray(array);
}