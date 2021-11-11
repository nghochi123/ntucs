/*edit*/

/*custom header*/

/*end_edit*/
#include <stdio.h>
#define SIZE 100
void compress2D(int data[SIZE][SIZE], int rowSize, int colSize);
int main()
{
    int data[SIZE][SIZE];
    int i, j;
    int rowSize, colSize;

    printf("Enter the array size (rowSize, colSize): \n");
    scanf("%d %d", &rowSize, &colSize);
    printf("Enter the matrix (%dx%d): \n", rowSize, colSize);
    for (i = 0; i < rowSize; i++)
        for (j = 0; j < colSize; j++)
            scanf("%d", &data[i][j]);
    printf("compress2D(): \n");
    compress2D(data, rowSize, colSize);
    return 0;
}
void compress2D(int data[SIZE][SIZE], int rowSize, int colSize)
{
    /*edit*/
    /* Write your code here */
    int count, value, i, j;
    for (i = 0; i < rowSize; i++)
    {
        count = 0, value = -1;
        for (j = 0; j < colSize; j++)
        {
            if (data[i][j] == 1 && value != 0)
            {
                count++;
                value = 1;
            }
            else if (data[i][j] == 0 && value != 1)
            {
                count++;
                value = 0;
            }
            else
            {
                printf("%d %d ", value, count);
                count = 1;
                value = data[i][j];
            }
        }
        printf("%d %d\n", value, count);
    }

    /*end_edit*/
}