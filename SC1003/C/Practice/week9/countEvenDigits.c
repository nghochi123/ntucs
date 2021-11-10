/*edit*/

/*custom header*/

/*end_edit*/
#include <stdio.h>
int countEvenDigits1(int number);
void countEvenDigits2(int number, int *count);
int main()
{
    int number, result;

    printf("Enter a number: \n");
    scanf("%d", &number);
    printf("countEvenDigits1(): %d\n", countEvenDigits1(number));
    countEvenDigits2(number, &result);
    printf("countEvenDigits2(): %d\n", result);
    return 0;
}
int countEvenDigits1(int number)
{
    /*edit*/
    /* Write your code here */
    int count = 0;
    while (number > 0)
    {
        if (number % 2 == 0)
        {
            count++;
        }
        number /= 10;
    }
    return count;

    /*end_edit*/
}
void countEvenDigits2(int number, int *count)
{
    /*edit*/
    /* Write your code here */
    *count = 0;
    while (number > 0)
    {
        if (number % 2 == 0)
        {
            (*count)++;
        }
        number /= 10;
    }

    /*end_edit*/
}