#include <stdio.h>
int main()
{
    int num = 5;
    printf("num = %d, &num = %p\n", num, &num);
    scanf("%d", &num);
    printf("num = %d, &num = %p\n", num, &num);
}