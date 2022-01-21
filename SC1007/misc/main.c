#include <stdio.h>
#include <stdlib.h>

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

ListNode* findNode(ListNode *cur, int i){
    int j = 0;
    if(cur==NULL){
        return NULL;
    }
    for(j = 0; j < i; j++){
        cur = cur->next;
        if(cur==NULL){
            return NULL;
        }
    }
    return cur;
}

int insertNode(ListNode **ptrHead, int i, int item){
    ListNode *insertable = malloc(sizeof(ListNode));
    ListNode *fromNode = malloc(sizeof(ListNode));
    insertable->item = item;
    if((fromNode = findNode(*ptrHead, i)) != NULL){
        insertable->next = fromNode->next;
        fromNode->next = insertable;
        return 1;
    }
    return 0;
}

int removeNode(ListNode **ptrHead, int i){
    ListNode *removeNode = malloc(sizeof(ListNode));
    ListNode *befRemoveNode = malloc(sizeof(ListNode));
    if(i == 0){
        **ptrHead = *((*ptrHead)->next);
        return 1;
    }
    else if((removeNode = findNode(*ptrHead, i)) != NULL){
        befRemoveNode = findNode(*ptrHead, i-1);
        befRemoveNode->next = removeNode->next;
        return 1;
    }
    return 0;
}

int sizeList(ListNode *ptrHead){
    int size = 0;
    while(ptrHead != NULL){
        size++;
        ptrHead = ptrHead->next;
    }
    return size;
}

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
    printList(head);
    scanf("%c", &misc);
    printf("Please enter an index. (to FIND)\n");
    scanf("%d", &i);
    printf("%d", findNode(head, i)->item);
    printf("Please enter an index, followed by a value (to ADD).\n");
    scanf("%d %d", &i, &j);
    insertNode(&head, i, j);
    printList(head);
    scanf("%c", &misc);
    printf("Please enter an index (to REMOVE).\n");
    scanf("%d", &i);
    removeNode(&head, i);
    printList(head);
    printf("\nThe total size of your list is: %d.", sizeList(head));
    return 0;
}

