/*
1. Add1 function adds 1 to each element in an array.
In the main function, the add1 function is being run on each elmement (which is an array) of 'array'.


2.
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Two functions, first to collect frequency distribution, second to print histogram.

int main()
{
    srand(time(NULL));
    int n, random;
    int array[10] = {0};

    scanf("%d", &n);

    // Collection of frequency distribution

    for (int i = 0; i < n; i++)
    {
        random = rand() % 100;
        array[random / 10]++;
    }

    // Printing of histogram.

    for (int i = 0; i < 10; i++)
    {
        printf("%d0-%d9     |", i, i);
        for (int j = 0; j < array[i]; j++)
        {
            printf("*");
        }
        printf("\n");
    }
}

3.
#include <stdio.h>

#define SIZE 4

void transpose2D(int ar[][SIZE], int rowSize, int colSize);
void printArr(int ar[][SIZE], int row, int col);

int ar[4][4] = {1, 2, 3, 4, 5, 1, 2, 2, 6, 3, 4, 4, 7, 5, 6, 7};

int main()
{
    printArr(ar, SIZE, SIZE);
    transpose2D(ar, SIZE, SIZE);
    printf("---------------------\nAfter transposition\n---------------------\n");
    printArr(ar, SIZE, SIZE);
}

void transpose2D(int ar[][SIZE], int rowSize, int colSize)
{
    for (int i = 0; i < rowSize; i++)
    {
        for (int j = i; j < colSize; j++)
        {
            int temp = *(*(ar + i) + j);
            *(*(ar + i) + j) = *(*(ar + j) + i);
            *(*(ar + j) + i) = temp;
        }
    }
}

void printArr(int ar[][SIZE], int row, int col)
{
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {

            printf("%d", ar[i][j]);
        }
        printf("\n");
    }
}

4.

#include <stdio.h>

#define SIZE 4
void reduceMatrix2D(int ar[][SIZE], int rowSize, int colSize);
void printArr(int ar[][SIZE], int row, int col);

int ar[4][4] = {4, 3, 8, 6, 9, 0, 6, 5, 5, 1, 2, 4, 9, 8, 3, 7};

int main()
{
    printArr(ar, SIZE, SIZE);
    printf("---------------------\nAfter Reduction\n---------------------\n");
    reduceMatrix2D(ar, SIZE, SIZE);
    printArr(ar, SIZE, SIZE);
}

void reduceMatrix2D(int ar[][SIZE], int rowSize, int colSize)
{
    for (int i = 0; i < rowSize; i++)
    {
        for (int j = 0; j < i; j++)
        {
            *(*(ar + j) + j) += *(*(ar + i) + j);
            *(*(ar + i) + j) = 0;
        }
    }
}

void printArr(int ar[][SIZE], int row, int col)
{
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {

            printf("%d", ar[i][j]);
        }
        printf("\n");
    }
}

*/