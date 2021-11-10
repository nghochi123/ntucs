/*edit*/

/*custom header*/

/*end_edit*/
#include <stdio.h>
int main()
{
    /*edit*/
    /* Write your code here */
    int i, j, n;
    printf("Enter a number (between 1 and 9):\n");
    scanf("%d", &n);
    printf("Multiplication Table:\n");
    for (i = 0; i < n; i++)
    {
        printf(" %d", i + 1);
    }
    printf("\n");
    for (i = 1; i <= n; i++)
    {
        printf("%d", i);
        for (j = 0; j < i; j++)
        {
            printf(" %d", i * (j + 1));
        }
        printf("\n");
    }

    /*end_edit*/
    return 0;
}