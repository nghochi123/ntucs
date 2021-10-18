/* 
1.
"How are ya, sweetie?"
"How are ya, sweetie?"
"Beat the clock."
"win a toy"
"win a snoopy"
"win"
"c" "h" "a" "t"
?
?
"How are ya, sweetie?"

ANS:
How are ya, sweetie ?How are ya, sweetie ?
Beat the clock.
eat the clock.
input: win a toy
win a toy
input: snoopy
win a toy
win
chat
hat
at
t
t
at
How are ya, sweetie ?

#include <stdio.h>
#include <string.h>
#define M1 "How are ya, sweetie ?"
char M2[40] = "Beat the clock.";
char *M3 = "chat";

int main()
{
    char words[80], *p;
    printf(M1);
    puts(M1);
    puts(M2);
    puts(M2 + 1);
    fgets(words, 80, stdin); // user inputs :  win a toy.
if (p = strchr(words, '\n'))
    *p = '\0';
puts(words);
scanf("% s", words + 6); // user inputs :  snoopy.
puts(words);
words[3] = '\0';
puts(words);
while (*M3)
    puts(M3++);
puts(--M3);
puts(--M3);
M3 = M1;
puts(M3);
return 0;
}

2.
Count how many of the characters are in the string.

#include <stdio.h>
#include <string.h>
int unknown(char str[], char c);
int main()
{
    int x;
    x = unknown("ccccpenis", 'c');
    printf("%d", x);
    return 0;
}
int unknown(char str[], char c)
{
    int x, y = 0, z = 0;

    for (x = 0; str[x] != '\0'; x++)
    {

        if (str[x] != c)
        {
            // str[y] = str[x];
            // printf("%c", str[y]);
        }
        else
        {
            z++;
        }
    }
    // str[y] = '\0';
    return z;
}

3.
#include <stdio.h>

char *strncpy(char *s1, char *s2, int n);
int main()
{
    char *s1, *s2, n;
    printf("Enter string:\n");
    scanf("%s", s1);
    printf("Enter number of characters:\n");
    scanf("%d", &n);
    strncpy(s1, s2, n);
    return 0;
}

char *strncpy(char *s1, char *s2, int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%c", *(s1 + i));
        *(s2 + i) = 'c';
    }
    printf("%s", s2);
}

4.
#include <stdio.h>

int stringcmp(char *s1, char *s2);
int main()
{
    printf("%d", stringcmp("nigga", "nigga"));
}

int stringcmp(char *s1, char *s2)
{
    for (int i = 0; *(s2 + i) != '\0' && *(s1 + i) != '\0'; i++)
    {
        if (*(s1 + i) < *(s2 + i))
        {
            return -1;
        }
        else if (*(s1 + i) > *(s2 + i))
        {
            return 1;
        }
    }
    return 0;
}
*/
