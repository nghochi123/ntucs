/*edit*/

/*custom header*/

/*end_edit*/
#include <stdio.h>
int main()
{
    /*edit*/
    /* Write your code here */
    int salary, merit;
    printf("Enter the salary:\n");
    scanf("%d", &salary);
    printf("Enter the merit:\n");
    scanf("%d", &merit);
    if (salary >= 800 || (salary >= 700 && merit >= 20))
    {
        printf("The grade: A\n");
    }
    else if (salary >= 650 || (salary >= 600 && merit >= 10))
    {
        printf("The grade: B\n");
    }
    else
    {
        printf("The grade: C\n");
    }

    /*end_edit*/
    return 0;
}