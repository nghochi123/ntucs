#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define CHARSETSIZE 26

int maximum(int a, int b)
{
    return a > b ? a : b;
}

void printString(char *string, int len)
{
    for (int i = 0; i < len; i++)
    {
        printf("%c", string[i]);
    }
    printf("\n");
}

int *createCharJump(char *pattern, int patternLen)
{
    int *charSet = malloc(CHARSETSIZE * sizeof(int));
    for (int i = 0; i < CHARSETSIZE; i++)
        charSet[i] = patternLen;
    for (int i = 0; i < patternLen; i++)
        charSet[pattern[i] - 97] = patternLen - i;
    return charSet;
}

int bm(char *text, char *pattern)
{
    int tl = strlen(text), pl = strlen(pattern);
    int *charSet = createCharJump(pattern, pl);
    int textPtr = pl - 1, patternPtr;
    while (textPtr < tl)
    {
        patternPtr = pl - 1;
        while (text[textPtr--] == pattern[patternPtr--])
        {
            if (patternPtr < 0)
            {
                return textPtr + 1;
            }
        }
        textPtr += maximum(charSet[text[textPtr] - 97], pl - patternPtr);
    }
    return -1;
}

int main()
{
    char s[50], t[50];
    printf("Enter text item\n");
    scanf("%s", s);
    printf("Enter pattern\n");
    scanf("%s", t);
    int index = bm(s, t);
    printf("%d\n", index);
    if (index != -1)
    {
        printString((s + index), strlen(t));
    }
}