#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

// memory
int *r;

int **x;

int cr_bottom_up_dp_print(int *p, int n)
{
    // write your code here
    x = malloc(sizeof(int *) * (n + 1));
    // set all memory elements to -1
    int i, j;
    for (i = 0; i <= n; i++)
    {
        x[i] = malloc(sizeof(int) * (n + 1));

        for (j = 0; j <= n; j++)
        {
            x[i][j] = 0;
        }
    }
    r[0] = 0;
    for (i = 1; i <= n; i++)
    {
        for (j = i; j <= n; j++)
        {
            if (r[j] < p[i] + r[j - i])
            {
                r[j] = p[i] + r[j - i];
                x[i][j] = p[i];
                if (i != j)
                {
                    x[i][j] = p[i];
                }
            }
        }
    }
    int row = n, column = n;
    while (row > 0 && column > 0)
    {
        if (x[row][column] == 0)
        {
            row -= 1;
        }
        else
        {
            printf("%d ", row);
            column -= row;
        }
    }
    printf("\n");
    return r[n];
}

void main()
{
    int n; // length of  rod
    int function;
    int i;
    int *p; // price list

    int price_list[10] = {0, 1, 5, 8, 9, 10, 17, 17, 20, 24}; // declare one more value to cover the index 0;

    n = 4;
    p = price_list;

    // allocate the memory array
    r = malloc(sizeof(int) * (n + 1));

    // set all memory elements to -1
    for (i = 0; i <= n; i++)
        r[i] = 0;

    printf("The maximun value is: %d \n", cr_bottom_up_dp_print(p, n));
}