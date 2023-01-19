#include <stdio.h>
#include <stdlib.h>

void printLast(int **last, int f, int b) {
    int m = last[f][b];
    if (m == 0) {
        printf("%d %d", f, b);
        return;
    }

    printf("( ");
    printLast(last, f, m);
    printf(" ) ( ");
    printLast(last, m, b);
    printf(" )");
}

int matrixCost(int *d, int n) {
    int **cost = (int **) malloc(sizeof(int *) * (n + 1));
    int **last = (int **) malloc(sizeof(int *) * (n + 1));

    int i;
    //array initialisation
    for (i = 0; i <= n; i++) {
        cost[i] = (int *) calloc(n+1, sizeof(int));
        last[i] = (int *) calloc(n+1, sizeof(int));
    }

    //looping
    int cur, j, k, base, min;
    for (cur = n - 2; cur >= 0; cur--) {
        for (i = 0; i <= cur; i++) {
            j = i + n - cur;
            
            min = -1;
            for (k = i + 1; k < j; k++) {
                base = d[i] * d[k] * d[j] + cost[i][k] + cost[k][j];
                if (min < 0 || base < min) {
                    min = base;
                    last[i][j] = k;
                }
            }

            cost[i][j] = min;
        }
    }

    min = cost[0][n];

    printLast(last, 0, n);
    printf("\n");

    for (i = 0; i <= n; i++) {
        free(cost[i]);
        free(last[i]);
    }

    free(cost);
    free(last);

    return min;
}

int main() {
    int d[] = {30, 1, 40, 10, 25};

    printf("minimum cost: %d\n", matrixCost(d, 4));
    return 0;
}