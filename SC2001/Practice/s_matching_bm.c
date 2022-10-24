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

int *createMatchJump(char *pattern, int patternLen)
{
    int *matchJump = malloc(patternLen * sizeof(int));
    int *shift = malloc(patternLen * sizeof(int) + 1);
    int *borderPosition = malloc(patternLen * sizeof(int) + 1);
    for (int x = 0; x < patternLen; x++)
    {
        shift[x] = 0;
    }
    int i = patternLen, j = patternLen + 1;
    borderPosition[i] = j;
    while (i > 0)
    {
        while (j <= patternLen && pattern[i - 1] != pattern[j - 1])
        {
            if (shift[j] == 0)
            {
                shift[j] = j - i;
            }
            j = borderPosition[j];
        }
        i--;
        j--;
        borderPosition[i] = j;
    }
    j = borderPosition[0];
    for (i = 0; i <= patternLen; i++)
    {
        if (shift[i] == 0)
        {
            shift[i] = j;
        }
        if (i == j)
        {
            j = borderPosition[j];
        }
    }
    for (int i = 0; i < patternLen; i++)
    {
        matchJump[i] = patternLen - i - 1 + shift[i + 1];
    }

    return matchJump;
}

int bm(char *text, char *pattern)
{
    int tl = strlen(text), pl = strlen(pattern);
    int *charSet = createCharJump(pattern, pl);
    int *matchJump = createMatchJump(pattern, pl);
    for (int i = 0; i < pl; i++)
    {
        printf("%d: CharSet: %d, MatchJump: %d\n", i, charSet[i], matchJump[i]);
    }
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