/*edit*/

/*custom header*/

/*end_edit*/
#include <stdio.h>
#define INIT_VALUE 999
int extOddDigits1(int num);
void extOddDigits2(int num, int *result);
int main()
{
    int number, result = INIT_VALUE;

    printf("Enter a number: \n");
    scanf("%d", &number);
    printf("extOddDigits1(): %d\n", extOddDigits1(number));
    extOddDigits2(number, &result);
    printf("extOddDigits2(): %d\n", result);
    return 0;
}
int extOddDigits1(int num)
{
    /*edit*/
    /* Write your code here */
    int otherNum = 0, pow10 = 1;
    while (num > 9)
    {
        if (num % 2 == 1)
        {
            otherNum += (num % 10) * pow10;
            pow10 *= 10;
        }
        num /= 10;
    }
    if (num % 2 == 1)
    {
        otherNum += (num % 10) * pow10;
    }
    if (otherNum == 0)
    {
        return -1;
    }
    return otherNum;

    /*end_edit*/
}
void extOddDigits2(int num, int *result)
{
    /*edit*/
    /* Write your code here */
    int pow10 = 1;
    *result = 0;
    while (num > 9)
    {
        if (num % 2 == 1)
        {
            *result += (num % 10) * pow10;
            pow10 *= 10;
        }
        num /= 10;
    }
    if (num % 2 == 1)
    {
        *result += (num % 10) * pow10;
    }
    if (*result == 0)
    {
        *result = -1;
    }

    /*end_edit*/
}