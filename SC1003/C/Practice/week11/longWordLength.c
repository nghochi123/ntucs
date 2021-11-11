/*edit*/

/*custom header*/

/*end_edit*/
#include <stdio.h>
#include <string.h>
int longWordLength(char *s);
int main()
{
    char str[80], *p;

    printf("Enter a string: \n");
    fgets(str, 80, stdin);
    if (p = strchr(str, '\n'))
        *p = '\0';
    printf("longWordLength(): %d\n", longWordLength(str));
    return 0;
}
int longWordLength(char *s)
{
    /*edit*/
    /* Write your code here */
    int i = 0, length = 0, max = 0;
    while (*(s + i))
    {
        if (tolower(*(s + i)) >= 97 && tolower(*(s + i)) <= 122)
        {
            length++;
            if (length > max)
            {
                max = length;
            }
        }
        else
        {
            length = 0;
        }
        i++;
    }
    // return 0;
    return max;

    /*end_edit*/
}