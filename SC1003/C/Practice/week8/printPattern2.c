/*edit*/

/*custom header*/

/*end_edit*/
#include <stdio.h>
int main()
{
    /*edit*/
    /* Write your code here */
    int i, j, n, alt;
    printf("Enter the height:\n");
    scanf("%d", &n);
    printf("The pattern is:\n");
    for (i = 1; i <= n; i++)
    {
        if (i % 2 != 0)
        {
            alt = 0;
        }
        else
            alt = 1;
        for (j = 0; j < i; j++)
        {
            if (alt == 0)
            {
                printf("A");
                alt = 1;
            }
            else
            {
                printf("B");
                alt = 0;
            }
        }
        printf("\n");
    }

    /*end_edit*/