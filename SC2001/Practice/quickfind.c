#include <stdlib.h>
#include <stdio.h>

struct QFArray
{
    int *array;
    int size;
};

void printArray(struct QFArray array)
{
    for (int i = 0; i < array.size; i++)
    {
        printf("%d ", array.array[i]);
    }
    printf("\n");
}

struct QFArray createArray(int numItems)
{
    struct QFArray array;
    array.array = malloc(numItems * sizeof(int));
    array.size = numItems;
    for (int i = 0; i < numItems; i++)
    {
        array.array[i] = i;
    }
    return array;
}

void uni(struct QFArray array, int firstID, int secondID)
{
    int headID = array.array[firstID];
    int toCombine = array.array[secondID];
    for (int i = 0; i < array.size; i++)
    {
        if (array.array[i] == toCombine)
        {
            array.array[i] = headID;
        }
    }
}

int quickfind(struct QFArray array, int id)
{
    return array.array[id];
}

int main()
{
    struct QFArray array = createArray(10);
    printArray(array);
    uni(array, 1, 2);
    uni(array, 3, 4);
    uni(array, 4, 8);
    uni(array, 3, 9);
    uni(array, 5, 6);
    uni(array, 2, 5);
    printArray(array);
}