/*edit*/

/*custom header*/

/*end_edit*/
#include <stdio.h>
typedef struct
{
    char name[20];
    int age;
} Person;
void readData(Person *p);
Person findMiddleAge(Person *p);
int main()
{
    Person man[3], middle;

    readData(man);
    middle = findMiddleAge(man);
    printf("findMiddleAge(): %s %d\n", middle.name, middle.age);
    return 0;
}
void readData(Person *p)
{
    /*edit*/
    /* Write your code here */
    int i = 0;
    for (i = 0; i < 3; i++)
    {
        printf("Enter person %d:\n", i + 1);
        scanf("%s", &(*(p + i)).name);
        scanf("%d", &(*(p + i)).age);
    }

    /*end_edit*/
}
Person findMiddleAge(Person *p)
{
    /*edit*/
    /* Write your code here */
    int i, max = p->age, min = p->age, maxI = 0, minI = 0;
    for (i = 0; i < 3; i++)
    {
        if ((p + i)->age > max)
        {
            max = (p + i)->age;
            maxI = i;
        }
        if ((p + i)->age < min)
        {
            min = (p + i)->age;
            minI = i;
        }
    }
    for (i = 0; i < 3; i++)
    {
        if (i != maxI && i != minI)
        {
            return *(p + i);
        }
    }

    /*end_edit*/
}