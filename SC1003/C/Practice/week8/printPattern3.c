/*edit*/

/*custom header*/

/*end_edit*/
#include <stdio.h>
int main()
{
    /*edit*/
    /* Write your code here */
    int i, j, h;
    printf("Enter the height:\n");
    scanf("%d", &h);
    printf("The pattern is:\n");
    for (i = 1; i <= h; i++)
    {
        for (j = 0; j < i; j++)
        {
            printf("%d", (i + j) % 10);
        }
        printf("\n");
    }

    /*end_edit*/
    return 0;
}