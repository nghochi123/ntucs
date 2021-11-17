/*edit*/

/*custom header*/

/*end_edit*/
#include <stdio.h>
#include <string.h>
struct student
{
    char name[20];    /* student name */
    double testScore; /* test score */
    double examScore; /* exam score */
    double total;     /* total = (testScore+examScore)/2 */
};
double average();
int main()
{
    printf("average(): %.2f\n", average());
    return 0;
}
double average()
{
    /*edit*/
    /* Write your program code here */
    struct student std[50];
    char dummy, *p;
    double sum = 0;
    int i = 0;
    while (1 == 1)
    {
        printf("Enter student name:\n");
        fgets((std + i)->name, 20, stdin);
        if (p = strchr((std + i)->name, '\n'))
        {
            *p = '\0';
        }
        if (strcmp((std + i)->name, "END") == 0)
        {
            break;
        }
        printf("Enter test score:\n");
        scanf("%lf", &std[i].testScore);
        printf("Enter exam score:\n");
        scanf("%lf", &std[i].examScore);
        scanf("%c", &dummy);
        std[i].total = ((std + i)->examScore + (std + i)->testScore) / 2;
        printf("Student %s total = %.2f\n", (std + i)->name, ((std + i)->total));
        sum += (std + i)->total;
        i++;
    }
    return i != 0 ? sum / i : 0;

    /*end_edit*/
}