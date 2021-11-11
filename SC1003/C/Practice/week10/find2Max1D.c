/*edit*/

/*custom header*/

/*end_edit*/
#include <stdio.h>
void find2Max1D(int ar[], int size, int *max1, int *max2);
int main()
{
    int max1, max2;
    int ar[10], size, i;

    printf("Enter array size: \n");
    scanf("%d", &size);
    printf("Enter %d data: \n", size);
    for (i = 0; i < size; i++)
        scanf("%d", &ar[i]);
    find2Max1D(ar, size, &max1, &max2);
    printf("Max1: %d\nMax2: %d\n", max1, max2);
    return 0;
}
void find2Max1D(int ar[], int size, int *max1, int *max2)
{
    /*edit*/
    /* Write your program code here */
    int i;
    *max1 = ar[0], *max2 = ar[0];
    for (i = 0; i < size; i++)
    {
        if (ar[i] > *max1)
        {
            *max1 = ar[i];
        }
    }
    if (*max1 == ar[0])
    {
        *max2 = ar[1];
    }
    for (i = 0; i < size; i++)
    {
        if (ar[i] > *max2 && ar[i] != *max1)
        {
            *max2 = ar[i];
        }
    }

    /*end_edit*/
}