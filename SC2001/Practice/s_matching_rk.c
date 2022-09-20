#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int compareString(const char *s1, const char *s2, int length) // Returns 1 if string is equal, 0 if not.
{
    for (int i = 0; i < length; i++)
    {
        if (s1[i] != s2[i])
            return 0;
    }
    return 1;
}

int main()
{
    char s[50], t[50];
    printf("Enter text item\n");
    scanf("%s", s);
    printf("Enter pattern\n");
    scanf("%s", t);
    int sl = strlen(s), tl = strlen(t);
    int patternValue = 0, textValue = 0;
    for (int i = 0; i < tl; i++)
    {
        patternValue = ((10 * patternValue) + (t[i] - 96)) % 2147483647;
        textValue = ((10 * textValue) + (s[i] - 96)) % 2147483647;
    }
    int textPtr = 0, matchFound = 0;
    while (textPtr + tl <= sl)
    {
        textValue = (textValue - s[textPtr] * pow(10, tl - 1)) * 10 + s[textPtr + tl];
        if (compareString((s + textPtr), t, tl))
        {
            printf("There is a match: index %d\n", textPtr);
            return 0;
        }
        textPtr++;
    }
}