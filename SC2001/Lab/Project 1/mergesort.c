#include <stdio.h>

int keycomparisons = 0;

void printArray(int *array, int n, int m)
{
    for (int i = n; i <= m; i++)
    {
        printf("%d ", array[i]);
    }
    printf("\n");
}

void merge(int *array, int n, int m)
{
    int mid = (n + m) / 2;
    int a = n, b = mid + 1;
    if (m - n <= 0)
        return;
    while (a <= mid && b <= m)
    {
        keycomparisons++;
        if (array[a] <= array[b])
            a++;
        else
        {
            int val = array[b];
            for (int i = b; i > a; i--)
            {
                array[i] = array[i - 1];
            }
            array[a] = val;
            mid++;
            a++;
            b++;
        }
    }
}

void mergeSort(int *array, int start, int end)
{
    int mid = (start + end) / 2;
    if (end - start <= 0)
        return;
    mergeSort(array, start, mid);
    mergeSort(array, mid + 1, end);
    merge(array, start, end);
}

int main()
{
    int array[10] = {6, 1, 15, 3, 22, 3, 88, 10, 90, 4};
    printArray(array, 0, 9);
    mergeSort(array, 0, 9);
    printArray(array, 0, 9);
    printf("%d\n", keycomparisons);
}