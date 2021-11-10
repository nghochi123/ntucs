/*edit*/

/*custom header*/

/*end_edit*/
#include <stdio.h>
int reverseDigits1(int num);
void reverseDigits2(int num, int *result);
int main()
{
    int num, result = 999;

    printf("Enter a number: \n");
    scanf("%d", &num);
    printf("reverseDigits1(): %d\n", reverseDigits1(num));
    reverseDigits2(num, &result);
    printf("reverseDigits2(): %d\n", result);
    return 0;
}
int reverseDigits1(int num)
{
    /*edit*/
    /* Write your code here */
    int result = 0, digits = 1, orig = num;
    while (num > 0)
    {
        num /= 10;
        digits *= 10;
    }
    digits /= 10;
    while (orig > 0)
    {
        result += digits * (orig % 10);
        digits /= 10;
        orig /= 10;
    }
    return result;

    /*end_edit*/
}
void reverseDigits2(int num, int *result)
{
    /*edit*/
    /* Write your code here */
    int digits = 1, orig = num;
    *result = 0;
    while (num > 0)
    {
        num /= 10;
        digits *= 10;
    }
    digits /= 10;
    while (orig > 0)
    {
        (*result) += digits * (orig % 10);
        digits /= 10;
        orig /= 10;
    }

    /*end_edit*/
}