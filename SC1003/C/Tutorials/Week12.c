/*
1.

#include <stdio.h>
#include <math.h>

struct circle
{
    double radius;
    double x;
    double y;
};

int intersect(struct circle c1, struct circle c2);
int contain(struct circle *c1, struct circle *c2);
int main()
{
    struct circle circle1 =
        {
            10,
            0,
            0};
    struct circle circle2 =
        {
            5,
            0,
            0};
    printf("%d\n", intersect(circle1, circle2));
    printf("%d\n", contain(&circle1, &circle2));
}
int intersect(struct circle c1, struct circle c2)
{
    float radiisum = c1.radius + c2.radius;
    float distance = sqrt(pow(c1.x - c2.x, 2) + pow(c1.y - c2.y, 2));
    return distance <= radiisum ? 1 : 0;
}
int contain(struct circle *c1, struct circle *c2)
{
    float sumRadiiCenterDist = c2->radius + sqrt(pow(c1->x - c2->x, 2) + pow(c1->y - c2->y, 2));
    return c1->radius >= sumRadiiCenterDist ? 1 : 0;
}

2.

#include <stdio.h>
#include <math.h>

typedef struct
{
    float operand1, operand2;
    char op; // operator '+', '-', '*', '/'
} bexpression;

float compute1(bexpression expr);
float compute2(bexpression *expr);

int main()
{
    bexpression something =
        {
            6,
            5,
            '+'};
    printf("%.2f\n", compute1(something));
    printf("%.2f\n", compute2(&something));
}
float compute1(bexpression expr)
{
    float o1 = expr.operand1;
    float o2 = expr.operand2;
    char op = expr.op;
    return op == '+' ? (o1 + o2) : op == '-' ? (o1 - o2)
                               : op == '*'   ? (o1 * o2)
                               : op == '/'   ? (o1 / o2)
                                             : 0;
}
float compute2(bexpression *expr)
{
    float o1 = expr->operand1;
    float o2 = expr->operand2;
    char op = expr->op;
    return op == '+' ? (o1 + o2) : op == '-' ? (o1 - o2)
                               : op == '*'   ? (o1 * o2)
                               : op == '/'   ? (o1 / o2)
                                             : 0;
}

3.
#include <stdio.h>
#include <math.h>

typedef struct
{
    int id;
    int totalLeave;
    int leaveTaken;
} leaveRecord;

void getInput(leaveRecord list[], int *n);
int mayTakeLeave(leaveRecord list[], int id, int leave, int n);
void printList(leaveRecord list[], int n);
int n = 0, choice = 0, id = 0, leave = 0, result;
leaveRecord list[999];
int main()
{
    printf("Enter your choice.\n1. getInput()\n2. mayTakeLeave()\n3. printList()\n");
    scanf("%d", &choice);
    do
    {
        switch (choice)
        {
        case 1:
            getInput(list, &n);
            break;
        case 2:
            printf("Enter employee id\n");
            scanf("%d", &id);
            printf("Enter number of leave\n");
            scanf("%d", &leave);
            result = mayTakeLeave(list, id, leave, n);
            printf("%d\n", result);
            break;
        case 3:
            printList(list, n);
            break;
        }
        printf("Enter your choice.\n1. getInput()\n2. mayTakeLeave()\n3. printList()\n");
        scanf("%d", &choice);
    } while (choice < 4);
}

void getInput(leaveRecord list[], int *n)
{
    printf("How many slaves do you have?\n");
    scanf("%d", n);
    for (int i = 0; i < *n; i++)
    {
        printf("Enter details.\n", i + 1);
        scanf("%d", &list[i].id);
        scanf("%d", &list[i].totalLeave);
        scanf("%d", &list[i].leaveTaken);
    }
}
int mayTakeLeave(leaveRecord list[], int id, int leave, int n)
{
    for (int i = 0; i < n; i++)
    {
        if (list[i].id == id)
        {
            if (leave + list[i].leaveTaken <= list[i].totalLeave)
            {
                return 1;
            }
            else
            {
                return 0;
            }
        }
    }
    return -1;
}
void printList(leaveRecord list[], int n)
{
    printf("These are the leave records:\n");
    for (int i = 0; i < n; i++)
    {
        printf("Staff id: %d\n", list[i].id);
        printf("\tTotal Leave: %d\n", list[i].totalLeave);
        printf("\tLeave Taken: %d\n", list[i].leaveTaken);
    }
    printf("Done.\n");
}
*/
