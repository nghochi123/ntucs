/*edit*/

/*custom header*/

/*end_edit*/
#include <stdio.h>
int main()
{
    /*edit*/
    /* Write your code here */
    char c;
    int digit = 0, letter = 0;
    printf("Enter your characters (# to end):\n");
    while (c != '#')
    {
        scanf("%c", &c);
        if ((c <= 122 && c >= 97) || (c <= 90 && c >= 65))
        {
            letter++;
        }
        else if ((c <= 57 && c >= 48))
        {
            digit++;
        }
    }
    printf("The number of digits: %d\n", digit);
    printf("The number of letters: %d\n", letter);

    /*end_edit*/
    return 0;
}