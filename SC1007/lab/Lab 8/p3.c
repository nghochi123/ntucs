#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

// memory
int *r;

void printSol(int n, int *arr)
{
    if (arr[n] == n)
    {
        printf("%d ", arr[n]);
        return;
    }
    printSol(arr[n], arr);
    printSol(n - arr[n], arr);
}

int cr_bottom_up_dp_print(int *p, int n)
{
    int arr[n + 1];
    r[0] = 0;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            int temp = p[j] + r[i - j];
            if (temp > r[i])
            {
                r[i] = temp;
                arr[i] = j;
            }
        }
    }
    printf("The rods are: ");
    printSol(n, arr);
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
        r[i] = -1;

    printf("The maximum value is: %d \n", cr_bottom_up_dp_print(p, n));
}