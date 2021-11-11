/*edit*/

/*custom header*/

/*end_edit*/
#include <stdio.h>
#include <string.h>
void processString(char *str, int *totVowels, int *totDigits);
int main()
{
    char str[50], *p;
    int totVowels, totDigits;

    printf("Enter the string: \n");
    fgets(str, 80, stdin);
    if (p = strchr(str, '\n'))
        *p = '\0';
    processString(str, &totVowels, &totDigits);
    printf("Total vowels = %d\n", totVowels);
    printf("Total digits = %d\n", totDigits);
    return 0;
}
void processString(char *str, int *totVowels, int *totDigits)
{
    /*edit*/
    /* Write your code here */
    *totVowels = 0;
    *totDigits = 0;
    int i = -1;
    while (*(str + i))
    {
        if (tolower(*(str + i)) == 'a' || tolower(*(str + i)) == 'e' || tolower(*(str + i)) == 'i' || tolower(*(str + i)) == 'o' || tolower(*(str + i)) == 'u')
        {
            (*totVowels)++;
            printf("%c\n", *(str + i));
        }
        else if (*(str + i) >= 48 && *(str + i) <= 57)
        {
            (*totDigits)++;
            printf("%c\n", *(str + i));
        }
        i++;
    }

    /*end_edit*/
}