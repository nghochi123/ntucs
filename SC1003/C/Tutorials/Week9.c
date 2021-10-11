/*
1.
i.      a) 8     b) 7700     c) 100      d) 3478     e) ?
ii.     a) 

#include <stdio.h>

int main()
{
    int number;
    int *p;
    number = 8;
    *p = 100;
    printf("%d %d", number, 12);
    return 0;
}

2.
a) Value not returned.
b) Sum not returned.
c) a declared again inside, not correct value will be shown.
d) * used in parameter and & used in scanf. Only choose one.
e) cannot return in void function.
f) return is not an integer if division.

3. 
i. "h = 5, k = 15"
ii. "h = 5, k = 15"
iii. "h = 5, k = 15"
iv. "h = 200, k = 200"

v. "h = -100, k =-100" (in between line i and ii)
vi. "h = 5, k = 15" (in between line ii and iii)
vii. "h = 100, k = 100" (in between line ii and iii)
viii. "h = 5, k = 15" (in between line iii and iv)
ix. "h = 200, k = 200" (in between line iii and iv)

4.
#include <stdio.h>
#include <math.h>

int main()
{

    int x1, x2, y1, y2;

    double cbv(int x1, int x2, int y1, int y2)
    {
        return sqrt(pow((x2 - x1), 2) + pow((y2 - y1), 2));
    }

    double cbr(int *x1, int *x2, int *y1, int *y2)
    {
        return sqrt(pow((*x2 - *x1), 2) + pow((*y2 - *y1), 2));
    }

    printf("Please enter 4 numbers");

    scanf("%d", &x1);
    scanf("%d", &x2);
    scanf("%d", &y1);
    scanf("%d", &y2);

    printf("%.2f\n", cbv(x1, x2, y1, y2));
    printf("%.2f\n", cbr(&x1, &x2, &y1, &y2));

    return 0;
}

*/
