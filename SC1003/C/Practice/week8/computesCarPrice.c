/*edit*/

/*custom header*/

/*end_edit*/
#include <stdio.h>
int main()
{
    /*edit*/
    /* Write your code here */
    int category;
    float list;
    printf("Please enter the list price:\n");
    scanf("%f", &list);
    printf("Please enter the category:\n");
    scanf("%d", &category);
    list = list * 0.9;
    if (list > 100000)
    {
        list *= 1.1;
    }
    list *= 1.03;
    switch (category)
    {
    case 1:
        list += 70000;
        break;
    case 2:
        list += 80000;
        break;
    case 3:
        list += 23000;
        break;
    case 4:
        list += 600;
        break;
    }
    printf("Total price is $%.2f", list);
    /*end_edit*/
    return 0;
}