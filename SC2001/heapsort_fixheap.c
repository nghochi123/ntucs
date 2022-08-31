#include <stdio.h>

void printArray(int *array, int n, int m)
{
    for (int i = n; i <= m; i++)
    {
        printf("%d ", array[i]);
    }
    printf("\n");
}

void fixHeap(int *array, int i, int n)
{
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    if (left > n)
        return;
    int larger = left;
    if (right <= n && array[right] > array[larger])
        larger = right;
    if (array[i] < array[larger])
    {
        int temp = array[i];
        array[i] = array[larger];
        array[larger] = temp;
        fixHeap(array, larger, n);
    }
}

void heapify(int *array, int i, int n)
{
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    if (left <= n)
    {
        heapify(array, left, n);
    }
    if (right <= n)
    {
        heapify(array, right, n);
    }
    fixHeap(array, i, n);
}

void heapSort(int *array, int n)
{

    int N = n;
    while (N >= 0)
    {
        heapify(array, 0, N);
        int temp = array[N];
        array[N] = array[0];
        array[0] = temp;
        N--;
    }
}

int main()
{
    int array[10] = {6, 1, 15, 3, 22, 3, 88, 10, 90, 4};
    printArray(array, 0, 9);
    heapSort(array, 9);
    printArray(array, 0, 9);
}