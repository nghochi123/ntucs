/*edit*/

/*custom header*/

/*end_edit*/
#include <stdio.h>
#include <string.h>
#define SIZE 10
void findMinMaxStr(char word[][40], char *first, char *last, int size);
int main()
{
    char word[SIZE][40];
    char first[40], last[40];
    int i, size;

    printf("Enter size: \n");
    scanf("%d", &size);
    printf("Enter %d words: \n", size);
    for (i = 0; i < size; i++)
        scanf("%s", word[i]);
    findMinMaxStr(word, first, last, size);
    printf("First word = %s, Last word = %s\n", first, last);
    return 0;
}
void findMinMaxStr(char word[][40], char *first, char *last, int size)
{
    /*edit*/
    /* Write your code here */
    int i = 0;
    *last = *(word[i]);
    *first = *(word[i]);
    for (i = 0; i < size; i++)
    {
        if (strcmp(last, word[i]) < 0)
        {
            strcpy(last, word[i]);
        }
        if (strcmp(first, word[i]) > 0)
        {
            strcpy(first, word[i]);
        }
    }

    /*end_edit*/
}