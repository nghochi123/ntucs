#include <stdlib.h>
#include <stdio.h>

// 5 items in each sorted array

void printArray(int *array, int n, int m)
{
    for (int i = n; i <= m; i++)
    {
        printf("%d ", array[i]);
    }
    printf("\n");
}

struct SortedArray
{
    int *array;
    int current;
};

void fixHeap(struct SortedArray *sortedArrayList, int i, int n)
{
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    if (left > n)
        return;
    int largest = left;
    if (right <= n && sortedArrayList[right].array[sortedArrayList[right].current] > sortedArrayList[left].array[sortedArrayList[left].current])
    {
        largest = right;
    }
    if (sortedArrayList[largest].array[sortedArrayList[largest].current] > sortedArrayList[i].array[sortedArrayList[i].current])
    {
        struct SortedArray temp = sortedArrayList[largest];
        sortedArrayList[largest] = sortedArrayList[i];
        sortedArrayList[i] = temp;
        fixHeap(sortedArrayList, largest, n);
    }
}

void heapify(struct SortedArray *sortedArrayList, int i, int n)
{
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    if (left <= n)
    {
        heapify(sortedArrayList, left, n);
    }
    if (right <= n)
    {
        heapify(sortedArrayList, right, n);
    }
    fixHeap(sortedArrayList, i, n);
}

struct SortedArray *createSortedArray(int arr[5])
{
    struct SortedArray *sortedArray;
    sortedArray->array = malloc(sizeof(int) * 5);
    for (int i = 0; i < 5; i++)
    {
        sortedArray->array[i] = arr[i];
    }
    sortedArray->current = 0;
    return sortedArray;
}

void mergeSortedArrays(struct SortedArray *sortedArrayList, int *finalArray)
{
    int arrayCount = 5;
    int overallCounter = 0;
    while (arrayCount > 0)
    {
        heapify(sortedArrayList, 0, arrayCount - 1);
        int toPush = sortedArrayList[0].array[sortedArrayList[0].current++];
        finalArray[overallCounter++] = toPush;
        if (sortedArrayList[0].current > 4)
        {
            arrayCount--;
            struct SortedArray temp = sortedArrayList[arrayCount];
            sortedArrayList[arrayCount] = sortedArrayList[0];
            sortedArrayList[0] = temp;
        }
    }
    printArray(finalArray, 0, overallCounter);
}

int main()
{
    struct SortedArray *sortedArrayList = malloc(sizeof(struct SortedArray) * 5);
    int arr1[5] = {5, 4, 3, 2, 1};
    int arr2[5] = {6, 3, 2, 2, 0};
    int arr3[5] = {10, 7, 6, 1, 1};
    int arr4[5] = {12, 8, 4, 1, 0};
    int arr5[5] = {13, 13, 10, 9, 9};
    int sortedArray[100000] = {0};

    // printf("Starting Program\n");

    sortedArrayList[0] = *createSortedArray(arr1);
    sortedArrayList[1] = *createSortedArray(arr2);
    sortedArrayList[2] = *createSortedArray(arr3);
    sortedArrayList[3] = *createSortedArray(arr4);
    sortedArrayList[4] = *createSortedArray(arr5);
    mergeSortedArrays(sortedArrayList, sortedArray);
}