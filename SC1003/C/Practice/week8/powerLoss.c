/*edit*/

/*custom header*/

/*end_edit*/
#include <stdio.h>
int main()
{
    /*edit*/
    /* Write your code here */
    int n, i;
    float cur, res;
    printf("Enter the number of times:\n");
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        printf("Enter the current:\n");
        scanf("%f", &cur);
        printf("Enter the resistance:\n");
        scanf("%f", &res);
        printf("The power loss: %.2f\n", (cur * cur * res));
    }

    /*end_edit*/
    return 0;
}