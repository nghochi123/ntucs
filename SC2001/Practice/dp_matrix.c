#include <stdlib.h>
#include <stdio.h>

// We will use all the first values of the matrix instead of the
// second values, except the last one.

int main()
{
    int len;
    printf("Enter the length of array:\n");
    scanf("%d", &len);
    int *array = (int *)malloc(len * sizeof(int));
    for (int i = 0; i < len; i++)
    {
        printf("Enter an item\n");
        scanf("%d", &array[i]);
    }
    int **dpArray = malloc((len + 2) * sizeof(int *));
    for (int i = 0; i < len + 2; i++)
    {
        dpArray[i] = malloc(sizeof(int) * (len + 2));
        for (int j = 0; j < len + 2; j++)
        {
            dpArray[i][j] = 999999;
            // if (i == j && i >= 1)
            // {
            //     dpArray[i][j] = array[i - 1];
            // }
        }
    }
    for (int i = 2; i < len + 1; i++)
    {
        for (int j = 0; i + j < len + 1; j++)
        {
            printf("%d %d\n", j, i + j);
            // for (int k = 0; k < i; k++)
            // {
            //     printf("%d ", j + k);
            // }
        }
        printf("\n");
    }
    for (int i = 0; i < len + 2; i++)
    {
        for (int j = 0; j < len + 2; j++)
        {
            printf("%d ", dpArray[i][j]);
            // if (alt[i][j] == 1)
            // {
            //     final[finalCount] = s[i - 1];
            //     finalCount++;
            // }
        }
        printf("\n");
    }
}