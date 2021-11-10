/*edit*/

/*custom header*/

/*end_edit*/
#include <stdio.h>
#define PI 3.1416
int main()
{
    /*edit*/
    /* Write your code here */
    int i, n, r, h;
    float V, SA;
    printf("Enter the number of times:\n");
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        printf("Enter the radius:\n");
        scanf("%d", &r);
        printf("Enter the height:\n");
        scanf("%d", &h);
        V = PI * r * r * h;
        SA = 2 * PI * r * h + 2 * PI * r * r;
        printf("The volume is: %.2f\n", V);
        printf("The surface area is: %.2f\n", SA);
    }

    /*end_edit*/
    return 0;
}