#include <stdio.h>

void printArray(int *array, int n, int m)
{
    for (int i = n; i <= m; i++)
    {
        printf("%d ", array[i]);
    }
    printf("\n");
}

void insertionSort(int *array, int len)
{
    int smallest, temp, sIndex;
    for (int i = 0; i < len; i++)
    {
        for (int j = i; j > 0; j--)
        {
            if (array[j] < array[j - 1])
            {
                int temp = array[j];
                array[j] = array[j - 1];
                array[j - 1] = temp;
            }
            else
                break;
        }
    }
}

int main()
{
    int array[10] = {6, 1, 15, 3, 22, 3, 88, 10, 90, 4};
    printArray(array, 0, 9);
    insertionSort(array, 10);
    printArray(array, 0, 9);
}