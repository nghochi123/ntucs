#include <stdint.h>
#include <stdio.h>

// Number of vertices in the graph
#define V 4

int graphColoring(int graph[V][V], int, int, int color[]);
int isSafe(int graph[V][V], int color[]);
void printSolution(int color[]);

int main()
{
    /* Create following graph and
       test whether it is 3 colorable
      (2)---(3)
       |   / |
       |  /  |
       | /   |
      (1)---(4)
    */
    int graph[V][V] = {
        {0, 1, 1, 1},
        {1, 0, 1, 0},
        {1, 1, 0, 1},
        {1, 0, 1, 0},
    };
    int m = 3; // Number of colors

    // Initialize all color values as 0.
    int color[V];
    for (int i = 0; i < V; i++)
        color[i] = 0;

    if (!graphColoring(graph, m, 0, color))
        printf("Solution does not exist\n");

    return 0;
}

// check if the colored
// graph is safe or not
int isSafe(int graph[V][V], int color[])
{
    // check for every edge
    for (int i = 0; i < V; i++)
        for (int j = i + 1; j < V; j++)
            if (graph[i][j] && color[j] == color[i])
                return 0;
    return 1;
}

int isValid(int graph[V][V], int color[], int vertex)
{
    for (int i = 0; i < V; i++)
        if (graph[i][vertex] && color[vertex] == color[i])
            return 0;
    return 1;
}

/* This function solves the m Coloring
   problem using recursion. It returns
  0 if the m colours cannot be assigned,
  otherwise, return 1 and prints
  assignments of colours to all vertices.
*/
int graphColoring(int graph[V][V], int m, int i,
                  int color[V])
{
    // write your code here
    int j, k;
    if (i >= V)
    {
        printSolution(color);
        return 1;
    }
    else
    {
        int flag = 0;
        for (j = 1; j < m + 1; j++)
        {
            color[i] = j;
            if (isValid(graph, color, i))
            {
                flag = graphColoring(graph, m, i + 1, color);
                // return 1;
            }
        }
        if (flag == 0)
            color[i] = 0;
        return flag;
    }
}

/* A utility function to print solution */
void printSolution(int color[])
{
    printf(" Following are the assigned colors \n");
    for (int i = 0; i < V; i++)
        printf(" %d ", color[i]);
    printf("\n");
}
