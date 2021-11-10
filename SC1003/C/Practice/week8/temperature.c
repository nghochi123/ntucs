/*edit*/

/*custom header*/

/*end_edit*/
#include <stdio.h>
int main()
{

    /*edit*/
    /* Write your code here */
    float F, C;
    while (F != -1)
    {
        printf("Enter the temperature in degree F:\n");
        scanf("%f", &F);
        C = (5.0 / 9.0) * (F - 32);
        printf("Converted degree in C: %.2f\n", C);
    }

    /*end_edit*/

    return 0;
}