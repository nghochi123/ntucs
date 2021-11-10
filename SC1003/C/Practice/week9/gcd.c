/*edit*/

/*custom header*/

/*end_edit*/
#include <stdio.h>
int gcd1(int num1, int num2);
void gcd2(int num1, int num2, int *result);
int main()
{
    int x, y, result = -1;

    printf("Enter 2 numbers: \n");
    scanf("%d %d", &x, &y);
    printf("gcd1(): %d\n", gcd1(x, y));
    gcd2(x, y, &result);
    printf("gcd2(): %d\n", result);
    return 0;
}
int gcd1(int num1, int num2)
{
    /*edit*/
    /* Write your code here */
    int divisor = num1 < num2 ? num1 : num2;
    while (1 == 1)
    {
        if (num1 % divisor == 0 && num2 % divisor == 0)
        {
            break;
        }
        divisor--;
    }
    return divisor;

    /*end_edit*/
}
void gcd2(int num1, int num2, int *result)
{
    /*edit*/
    /* Write your code here */
    *result = num1 < num2 ? num1 : num2;
    while (1 == 1)
    {
        if (num1 % *result == 0 && num2 % *result == 0)
        {
            break;
        }
        (*result)--;
    }

    /*end_edit*/
}