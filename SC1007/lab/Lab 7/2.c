#include <stdio.h>
#include <stdlib.h>

int nQueens(int **board, int N, int col);
int isSafe(int **board, int N, int row, int col);
void printSolution(int **board, int N);

int main()
{
    int **board;
    int BSize;

    int i, j;

    printf("Enter the size of chessBoard:\n");
    scanf("%d", &BSize);

    board = (int **)malloc(BSize * sizeof(int *));
    for (i = 0; i < BSize; i++)
        board[i] = (int *)malloc(BSize * sizeof(int));

    for (i = 0; i < BSize; i++)
        for (j = 0; j < BSize; j++)
            board[i][j] = 0;

    if (!nQueens(board, BSize, 0))
        printf("Solution does not exist");

    return 0;
}

int nQueens(int **board, int BSize, int col)
{
    // write your code here
    if (col >= BSize)
    {
        printSolution(board, BSize);
        return 1;
    }
    else
    {
        int i, flag = 0;
        for (i = 0; i < BSize; i++)
        {
            // printSolution(board, BSize);
            if (isSafe(board, BSize, i, col))
            {
                board[i][col] = 1;
                if (flag == 0)
                    flag = nQueens(board, BSize, col + 1);
                else
                    nQueens(board, BSize, col + 1);
                board[i][col] = 0;
                //  return 1;
            }
        }
        return flag;
    }
}

// Safe checking
int isSafe(int **board, int BSize, int row, int col)
{
    int i, j;

    // Horicatal check
    for (i = 0; i < col; i++)
        if (board[row][i])
            return 0;

    // Upper left diagonal check
    for (i = row, j = col; i >= 0 && j >= 0; i--, j--)
        if (board[i][j])
            return 0;

    // Lower left diagonal check
    for (i = row, j = col; j >= 0 && i < BSize; i++, j--)
        if (board[i][j])
            return 0;

    return 1;
}

void printSolution(int **board, int BSize)
{
    int i, j;
    for (i = 0; i < BSize; i++)
    {
        for (j = 0; j < BSize; j++)
        {
            if (board[i][j] == 1)
                printf(" Q ");
            else
                printf(" + ");
        }
        printf("\n");
    }
    printf("\n");
}
