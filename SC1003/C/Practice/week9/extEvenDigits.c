/*edit*/

/*custom header*/

/*end_edit*/
#include <stdio.h>
#define INIT_VALUE 999
int extEvenDigits1(int num);
void extEvenDigits2(int num, int *result);
int main()
{
    int number, result = INIT_VALUE;

    printf("Enter a number: \n");
    scanf("%d", &number);
    printf("extEvenDigits1(): %d\n", extEvenDigits1(number));
    extEvenDigits2(number, &result);
    printf("extEvenDigits2(): %d\n", result);
    return 0;
}
int extEvenDigits1(int num)
{
    /*edit*/
    /* Write your code here */
    int result = 0, pow10 = 1;
    while (num > 0)
    {
        if (num % 2 == 0)
        {
            result += (num % 10) * pow10;
            pow10 *= 10;
        }
        num /= 10;
    }
    return result != 0 ? result : -1;

    /*end_edit*/
}
void extEvenDigits2(int num, int *result)
{
    /*edit*/
    /* Write your code here */
    *result = 0;
    int pow10 = 1;
    while (num > 0)
    {
        if (num % 2 == 0)
        {
            (*result) += (num % 10) * pow10;
            pow10 *= 10;
        }
        num /= 10;
    }
    *result = *result != 0 ? *result : -1;

    /*end_edit*/
}