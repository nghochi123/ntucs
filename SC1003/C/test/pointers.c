#include <stdio.h>

int b = 2;

int fun(int *k);

int main()

{

    int a[10] = {1, 2, 3, 4, 5, 6, 7, 8}, i;

    for (i = 2; i < 4; i++)

    {

        b = fun(&a[i]) + b;

        printf("%d ", b);
    }

    printf("\n");

    return 0;
}

int fun(int *k)

{

    b = *k + b;
    return (b);
}