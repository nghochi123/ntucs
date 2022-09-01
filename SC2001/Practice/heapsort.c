#include <stdio.h>

void printArray(int *array, int n, int m)
{
    for (int i = n; i <= m; i++)
    {
        printf("%d ", array[i]);
    }
    printf("\n");
}

void heapify(int *array, int N, int i)
{
    int lg = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;
    if (l < N && array[lg] < array[l])
    {
        lg = l;
    }
    if (r < N && array[lg] < array[r])
    {
        lg = r;
    }
    if (lg != i)
    {
        int temp = array[lg];
        array[lg] = array[i];
        array[i] = temp;
        heapify(array, N, lg);
    }
}

void heapSort(int *array, int st, int ed)
{
    int N = ed / 2;
    while (N >= 0)
    {

        heapify(array, ed, N);
        N--;
    }
    N = ed;
    while (N >= 0)
    {
        int temp = array[N];
        array[N] = array[0];
        array[0] = temp;
        heapify(array, N, 0);
        N--;
    }
}

int main()
{
    int array[10] = {6, 1, 15, 3, 22, 3, 88, 10, 90, 4};
    printArray(array, 0, 9);
    heapSort(array, 0, 9);
    printArray(array, 0, 9);
}