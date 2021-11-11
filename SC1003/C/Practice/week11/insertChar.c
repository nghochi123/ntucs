/*edit*/

/*custom header*/

/*end_edit*/
#include <stdio.h>
#include <string.h>
void insertChar(char *str1, char *str2, char ch);
int main()
{
    char a[80], b[80];
    char ch, *p;

    printf("Enter a string: \n");
    fgets(a, 80, stdin);
    if (p = strchr(a, '\n'))
        *p = '\0';
    printf("Enter a character to be inserted: \n");
    ch = getchar();
    insertChar(a, b, ch);
    printf("insertChar(): ");
    puts(b);
    return 0;
}
void insertChar(char *str1, char *str2, char ch)
{
    /*edit*/
    /* Write your code here */
    int count = 0, i = 0, j = 0;
    while (*(str1 + i))
    {
        *(str2 + j) = *(str1 + i);
        count++;
        i++;
        j++;
        if (count == 3)
        {
            *(str2 + j) = ch;
            j++;
            count = 0;
        }
    }
    *(str2 + j) = '\0';

    /*end_edit*/
}