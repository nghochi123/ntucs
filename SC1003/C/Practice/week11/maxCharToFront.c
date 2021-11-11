/*edit*/

/*custom header*/

/*end_edit*/
#include <stdio.h>
#include <string.h>
void maxCharToFront(char *str);
int main()
{
    char str[80], *p;

    printf("Enter a string: \n");
    fgets(str, 80, stdin);
    if (p = strchr(str, '\n'))
        *p = '\0';
    printf("maxCharToFront(): ");
    maxCharToFront(str);
    puts(str);
    return 0;
}
void maxCharToFront(char *str)
{
    /*edit*/
    /* Write your code here */
    int i = 0, max = 0, maxIndex = 0;
    char temp;
    while (*(str + i))
    {
        if (*(str + i) > max)
        {
            max = *(str + i);
            maxIndex = i;
        }
        i++;
    }
    temp = *(str + maxIndex);
    for (i = maxIndex; i > 0; i--)
    {
        *(str + i) = *(str + i - 1);
    }
    *(str) = temp;

    /*end_edit*/
}