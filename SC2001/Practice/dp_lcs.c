#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define SIZE 50

int maximum(int a, int b)
{
    return a > b ? a : b;
}

int lcs(char *s, char *t, int f[SIZE + 1][SIZE + 1], int alt[SIZE + 1][SIZE + 1], int *a, int *b)
{
    int max = 0;
    for (int i = 0; i < SIZE; i++)
    {
        if (s[i] == '\0')
        {
            *a = i;
            break;
        }
        for (int j = 0; j < SIZE; j++)
        {
            if (t[j] == '\0')
            {
                *b = j;
                break;
            }
            if (s[i] == t[j])
            {
                // Move diagonally
                f[i + 1][j + 1] = 1 + f[i][j];
                alt[i + 1][j + 1] = 1;
                if (f[i + 1][j + 1] > max)
                {
                    max = f[i + 1][j + 1];
                }
            }
            else if (f[i + 1][j] > f[i][j + 1])
            {
                // Move right
                f[i + 1][j + 1] = f[i + 1][j];
                alt[i + 1][j + 1] = 2;
            }
            else
            {
                // Move down
                f[i + 1][j + 1] = f[i][j + 1];
                alt[i + 1][j + 1] = 3;
            }
        }
    }
    return max;
}

int main()
{
    int ptr = 0;
    int f[SIZE + 1][SIZE + 1];
    int alt[SIZE + 1][SIZE + 1];
    for (int i = 0; i < SIZE + 1; i++)
    {
        for (int j = 0; j < SIZE + 1; j++)
        {
            f[i][j] = 0;
            alt[i][j] = 0;
        }
    }
    char s[SIZE], t[SIZE];
    printf("Enter first item\n");
    scanf("%s", s);
    printf("Enter second item\n");
    scanf("%s", t);
    int *a = malloc(sizeof(int)), *b = malloc(sizeof(int));
    int max = lcs(s, t, f, alt, a, b);
    char final[SIZE];
    printf("%d\n", max);
    final[max] = '\0';
    while (alt[*a][*b] != 0)
    {
        if (alt[*a][*b] == 1)
        {
            max -= 1;
            final[max] = s[*a - 1];
            // printf("%d %d %c\n", *a, *b, s[*a - 1]);
            (*a)--;
            (*b)--;
        }
        else if (alt[*a][*b] == 2)
        {
            (*b)--;
        }
        else if (alt[*a][*b] == 3)
            (*a)--;
    }
    // for (int i = 0; i < SIZE + 1; i++)
    // {
    //     for (int j = 0; j < SIZE + 1; j++)
    //     {
    //         printf("%d ", f[i][j]);
    //         // if (alt[i][j] == 1)
    //         // {
    //         //     final[finalCount] = s[i - 1];
    //         //     finalCount++;
    //         // }
    //     }
    //     printf("\n");
    // }
    printf("%s\n", final);
}