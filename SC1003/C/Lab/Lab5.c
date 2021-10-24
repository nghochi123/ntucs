#include <stdio.h>
#include <math.h>
#include <string.h>
#define MAX 100

typedef struct
{
    char name[20];
    int telno;
} PhoneBk;

void printPB(PhoneBk *pb, int size);
int readin(PhoneBk *pb);
void search(PhoneBk *pb, int size, char *target);
int main()
{
    PhoneBk s[MAX];
    char t[20], *p;
    int size = 0, choice;
    char dummychar;

    printf("Select one of the following options: \n");
    printf("1: readin()\n");
    printf("2: search()\n");
    printf("3: printPB()\n");
    printf("4: exit()\n");
    do
    {
        printf("Enter your choice: \n");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            scanf("%c", &dummychar);
            size = readin(s);
            break;
        case 2:
            scanf("%c", &dummychar);
            printf("Enter search name: \n");
            fgets(t, 20, stdin);
            if (p = strchr(t, '\n'))
                *p = '\0';
            search(s, size, t);
            break;
        case 3:
            printPB(s, size);
            break;
        }
    } while (choice < 4);
    return 0;
}
void printPB(PhoneBk *pb, int size)
{
    if (size == 0)
    {
        printf("Empty phonebook\n");
    }
    else
    {
        printf("Phonebook List:\n");
        for (int i = 0; i < size; i++)
        {
            printf("%d", i);
            printf("\tName: %s\n", (pb + i)->name);
            printf("\tTel: %d\n", (pb + i)->telno);
        }
    }
}
int readin(PhoneBk *pb)
{
    int size;
    printf("Enter number of people:\n");
    scanf("%d", &size);
    for (int i = 0; i < size; i++)
    {
        printf("Please enter a name\n");
        scanf("%s", &pb[i].name);
        printf("Please enter the person's number:\n");
        scanf("%d", &pb[i].telno);
    }
    printf("We are done.\n");
    return size;
}
void search(PhoneBk *pb, int size, char *target)
{
    int found = 0;
    printf("Searching...");
    for (int i = 0; i < size; i++)
    {
        if (strcmp(target, (pb + i)->name) == 0)
        {
            printf("Found! Information:\n\tName: %s\n\tTel: %d\n", (pb + i)->name, (pb + i)->telno);
            found = 1;
        }
    }
    if (found != 1)
    {
        printf("Name not found!\n");
    }
}