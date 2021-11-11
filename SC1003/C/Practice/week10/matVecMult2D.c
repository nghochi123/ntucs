/*edit*/

/*custom header*/

/*end_edit*/
#include <stdio.h>
#define SIZE 3
void matVecMult(int M[SIZE][SIZE], int V[SIZE], int R[SIZE]);
int main()
{
    int A[SIZE][SIZE];
    int V[SIZE], R[SIZE];
    int i, j;

    printf("Enter matrix A (%dx%d): \n", SIZE, SIZE);
    for (i = 0; i < SIZE; i++)
        for (j = 0; j < SIZE; j++)
            scanf("%d", &A[i][j]);
    printf("Enter matrix V (%dx1): \n", SIZE);
    for (i = 0; i < SIZE; i++)
        scanf("%d", &V[i]);
    printf("matVecMult (AxV): \n");
    matVecMult(A, V, R);
    for (i = 0; i < SIZE; i++)
        printf("%d ", R[i]);
    printf("\n");
    return 0;
}
void matVecMult(int M[SIZE][SIZE], int V[SIZE], int R[SIZE])
{
    /*edit*/
    /* Write your code here */
    int i, j;
    for (i = 0; i < SIZE; i++)
    {
        R[i] = 0;
        for (j = 0; j < SIZE; j++)
        {
            R[i] += V[j] * M[i][j];
        }
    }

    /*end_edit*/
}