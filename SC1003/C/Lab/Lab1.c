#include <stdio.h>
// 1. #include <stdio.h>

// int main()
// {
//     int studentNo = 0, mark;

//     while (studentNo != -1)
//     {
//         printf("Enter Student ID");
//         scanf("%d", &studentNo);
//         printf("Enter Mark");
//         scanf("%d", &mark);
//     }
// }

// 2.
// #include <stdio.h>

// int main()
// {

//     int lines = 0, total, input, count;

//     printf("Enter number of lines:");
//     scanf("%d", &lines);
//     for (int i = 0; i < lines; i++)
//     {
//         printf("Enter line %d (end with -1)", i + 1);
//         total = 0;
//         input = 0;
//         count = 0;
//         while (input != -1)
//         {
//             scanf("%d", &input);
//             total += input;
//             count++;
//         }
//         total++;
//         count--;
//         printf("Average: %.2f", total / (float)count);
//     }

//     return 0;
// }

// 3.
// int main()
// {
//     int height;
//     printf("Key in height");
//     scanf("%d", &height);
//     for (int rows = 0; rows < height; rows++)
//     {
//         for (int column = 0; column <= rows; column++)
//         {
//             printf("%d", rows % 3 + 1);
//         }
//         printf("\n");
//     }
//     return 0;
// }

// 4.
int main()
{
    int den;
    float total = 1, x, num = 1.0;
    printf("What is x?");
    scanf("%f", &x);
    for (int i = 1; i < 11; i++)
    {
        den = 1;
        for (int j = 1; j <= i; j++)
        {
            den *= j;
        }
        num *= x;
        total += num / (float)den;
    }
    printf("%.2f", total);
}
