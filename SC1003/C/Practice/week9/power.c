/*edit*/

/*custom header*/

/*end_edit*/
#include <stdio.h>
float power1(float num, int p);
void power2(float num, int p, float *result);
int main()
{
    int power;
    float number, result = -1;

    printf("Enter the number and power: \n");
    scanf("%f %d", &number, &power);
    printf("power1(): %.2f\n", power1(number, power));
    power2(number, power, &result);
    printf("power2(): %.2f\n", result);
    return 0;
}
float power1(float num, int p)
{
    /*edit*/
    /* Write your code here */
    int reciprocal = p < 0 ? 1 : 0;
    int value = 1;
    p = p < 0 ? 0 - p : p;
    while (p > 0)
    {
        value *= num;
        p--;
    }
    if (reciprocal == 1)
    {
        return 1.0 / (float)value;
    }
    return (float)value;

    /*end_edit*/
}
void power2(float num, int p, float *result)
{
    /*edit*/
    /* Write your code here */
    int reciprocal = p < 0 ? 1 : 0;
    int value = 1;
    p = p < 0 ? 0 - p : p;
    while (p > 0)
    {
        value *= num;
        p--;
    }
    if (reciprocal == 1)
    {
        (*result) = 1.0 / (float)value;
    }
    else
    {
        *result = (float)value;
    }

    /*end_edit*/
}