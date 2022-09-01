#include <stdio.h>

int size = 0;

void printArray(int *array, int n, int m)
{
    for (int i = n; i <= m; i++)
    {
        printf("%d ", array[i]);
    }
    printf("\n");
}

void swap(int *array, int a, int b)
{
    int temp = array[a];
    array[a] = array[b];
    array[b] = temp;
}

void fixHeap(int *array, int n, int i)
{
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    if (left > n)
        return;
    int largest = left;
    if (right <= n && array[right] > array[largest])
        largest = right;
    if (array[largest] > array[i])
    {
        swap(array, i, largest);
        fixHeap(array, n, largest);
    }
}

void heapify(int *array, int n, int i)
{
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    if (left <= n)
    {
        heapify(array, n, left);
    }
    if (right <= n)
    {
        heapify(array, n, right);
    }
    fixHeap(array, n, i);
}

void insert(int *array, int p)
{
    array[size] = p;
    heapify(array, size, 0);
    size++;

} // Insert node with value p

int getMaximum(int *array)
{
    if (array[0])
        return array[0];
    return -1;
} // returns int at top

int extractMax(int *array)
{
    swap(array, 0, size - 1);
    size--;
    int mx = array[size];
    array[size] = -1;
    heapify(array, size, 0);
    return mx;
} // Get maximum value

int main()
{
    int array[500];
    insert(array, 3);
    insert(array, 4);
    insert(array, 9);
    insert(array, 5);
    insert(array, 2);
    printArray(array, 0, size - 1);
    printf("%d\n", extractMax(array));
    printf("%d\n", getMaximum(array));
    printArray(array, 0, size - 1);
}