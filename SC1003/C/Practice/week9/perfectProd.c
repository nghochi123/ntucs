/*edit*/

/*custom header*/

/*end_edit*/
#include <stdio.h>
int perfectProd1(int num);
void perfectProd2(int num, int *prod);
int main()
{
    int number, result = 0;

    printf("Enter a number: \n");
    scanf("%d", &number);
    printf("Calling perfectProd1() \n");
    printf("perfectProd1(): %d\n", perfectProd1(number));

    printf("Calling perfectProd2() \n");
    perfectProd2(number, &result);
    printf("perfectProd2(): %d\n", result);
    return 0;
}
int perfectProd1(int num)
{
    /*edit*/
    /* Write your code here */
    int i, j, product = 1;
    for (i = 3; i < num; i++)
    {
        int sum = 0;
        for (j = 1; j < i; j++)
        {
            if (i % j == 0)
            {
                sum += j;
            }
        }
        if (sum == i)
        {
            printf("Perfect number: %d\n", i);
            product *= sum;
        }
    }
    return product;

    /*end_edit*/
}
void perfectProd2(int num, int *prod)
{
    /*edit*/
    /* Write your code here */
    int i, j;
    *prod = 1;
    for (i = 3; i < num; i++)
    {
        int sum = 0;
        for (j = 1; j < i; j++)
        {
            if (i % j == 0)
            {
                sum += j;
            }
        }
        if (sum == i)
        {
            printf("Perfect number: %d\n", i);
            (*prod) *= sum;
        }
    }

    /*end_edit*/
}