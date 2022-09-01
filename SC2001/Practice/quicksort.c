#include <stdio.h>

void printArray(int *array, int n, int m)
{
    for (int i = n; i <= m; i++)
    {
        printf("%d ", array[i]);
    }
    printf("\n");
}

int partition(int *array, int start, int end)
{
    int pivot = array[start];
    int movePivotTo = start;
    for (int curIndex = start; curIndex <= end; curIndex++)
    {
        if (pivot > array[curIndex])
        {
            movePivotTo++;
            int temp = array[movePivotTo];
            array[movePivotTo] = array[curIndex];
            array[curIndex] = temp;
        }
    }
    int temp = pivot;
    array[start] = array[movePivotTo];
    array[movePivotTo] = temp;
    return movePivotTo;
}

void quickSort(int *array, int start, int end)
{
    if (end <= start)
        return;
    int pivotPos = partition(array, start, end);
    quickSort(array, start, pivotPos - 1);
    quickSort(array, pivotPos + 1, end);
}

int main()
{
    int array[10] = {6, 1, 15, 3, 22, 3, 88, 10, 90, 4};
    printArray(array, 0, 9);
    quickSort(array, 0, 9);
    printArray(array, 0, 9);
}