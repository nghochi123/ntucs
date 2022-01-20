#include <stdio.h>
#include <stdlib.h>

struct person {
    char firstName[15];
    char lastName[15];
    struct{
        int age;
        float height;
        float weight;
        char firstName[15];
    }Info, *InfoPtr;
    struct person *personP;
} student1;

typedef struct person person_t;

typedef struct node {
    int item; struct node *next;
} ListNode;

typedef struct _linkedlist{
    ListNode *head;
    int size;
} LinkedList;

void printList(ListNode *cur){
    while(cur != NULL){
        printf("%d\n", cur->item);
        cur = cur->next;
    }
}

int insertNodeRecursive(ListNode **ptrHead, int i, int item){
    if(i == 0){
        ListNode *insertable = malloc(sizeof(ListNode));
        insertable->item = item;
        insertable->next = (*ptrHead)->next;
        (*ptrHead)->next = insertable;
        return 1;
    }
    else if((*ptrHead)->next != NULL){
        return insertNodeRecursive(&((*ptrHead)->next), i-1, item);
    }
    return 0;
}


person_t* studentPtr = &student1;
person_t** studentPtrPtr = &studentPtr;


int main()
{
    ListNode *head = NULL, *temp;
    char misc = 0;
    int i = 0,j = 0;

    while(scanf("%d", &i)){
        if(head == NULL){
            head = malloc(sizeof(ListNode));
            temp = head;
        }
        else{
            temp->next = malloc(sizeof(ListNode));
            temp = temp->next;
        }
        temp->item = i;
    }
    temp->next = NULL;
    printf("Age studentPtr: %d, Age studentPtrPtr: %d\n", studentPtr->Info.age, (*studentPtrPtr)->Info.age);
    printList(head);
    scanf("%c", &misc);
    printf("Please enter an index, followed by a value (to ADD).\n");
    scanf("%d %d", &i, &j);
    insertNodeRecursive(&head, i, j);
    printList(head);
    return 0;
}

// Q3. It causes the two nodes Aptr and Bptr to point to each other. i.e. a 2 node circular linked list.
