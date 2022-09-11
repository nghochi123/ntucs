#include <stdlib.h>
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
    {
        return;
    }
    int smallest = left;
    if (right <= n && array[right] < array[smallest])
    {

        smallest = right;
    }
    if (array[smallest] < array[i])
    {
        int temp = array[i];
        array[i] = array[smallest];
        array[smallest] = temp;
        fixHeap(array, smallest, n);
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

int main()
{
    int dates[11] = {182,
                     30,
                     81,
                     356,
                     150,
                     52,
                     307,
                     158,
                     53,
                     325,
                     364};
    printArray(dates, 0, 10);
    heapify(dates, 0, 10);
    printArray(dates, 0, 10);
    // 30 53 52 158 150 81 307 182 356 325 364
    // 30 Jan, 22 Feb, 21 Feb, 7 Jun, 30 May, 22 Mar, 3 Nov, 1 Jul, 22 Dec, 21 Nov, 30 Dec
}