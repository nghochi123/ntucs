/*edit*/

/*custom header*/

/*end_edit*/
#include <stdio.h>
void specialNumbers1D(int ar[], int num, int *size);
int main()
{
    int a[20], i, size = 0, num;

    printf("Enter a number (between 100 and 999): \n");
    scanf("%d", &num);
    specialNumbers1D(a, num, &size);
    printf("specialNumbers1D(): ");
    for (i = 0; i < size; i++)
        printf("%d ", a[i]);
    return 0;
}
void specialNumbers1D(int ar[], int num, int *size)
{
    /*edit*/
    /* Write your code here */
    int i, sum, hun, ten, one;
    *size = 0;
    for (i = 100; i <= num; i++)
    {
        hun = i / 100;
        ten = (i / 10) % 10;
        one = i % 10;
        sum = hun * hun * hun + ten * ten * ten + one * one * one;
        // if(sum == 153)printf("%d %d ", sum, i);
        if (sum == i)
        {
            ar[(*size)] = i;
            (*size)++;
        }
    }

    /*end_edit*/
}