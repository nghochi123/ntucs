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
    printf("Current List: \n");
    while(cur != NULL){
        printf("%d ", cur->item);
        cur = cur->next;
    }
    printf("\n");
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

int insertNode2(LinkedList *ll, int i, int item){
    ListNode *insertable = malloc(sizeof(ListNode));
    ListNode *fromNode = malloc(sizeof(ListNode));
    insertable->item = item;
    if((fromNode = findNode(ll->head, i)) != NULL){
        insertable->next = fromNode->next;
        fromNode->next = insertable;
        (ll->size)++;
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

int removeNode2(LinkedList *ll, int i){
    ListNode *removeNode = malloc(sizeof(ListNode));
    ListNode *befRemoveNode = malloc(sizeof(ListNode));
    if(i == 0){
        ll->head = (ll->head)->next;
        (ll->size)--;
        return 1;
    }
    else if((removeNode = findNode(ll->head, i)) != NULL){
        befRemoveNode = findNode(ll->head, i-1);
        befRemoveNode->next = removeNode->next;
        (ll->size)--;
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

int split(ListNode *cur, ListNode **ptrEvenList, ListNode **ptrOddList){
    int count = 0;
    ListNode *ptrEven;
    ListNode *ptrOdd;
    *ptrEvenList = malloc(sizeof(ListNode));
    *ptrOddList = malloc(sizeof(ListNode));
    ptrEven = *ptrEvenList;
    ptrOdd = *ptrOddList;
    while(cur != NULL){
        if(count%2 == 0){
            // even
            ptrEven->next = malloc(sizeof(ListNode));
            ptrEven = ptrEven->next;
            ptrEven->item = cur->item;
        }
        else if(count % 2 == 1){
            ptrOdd->next = malloc(sizeof(ListNode));
            ptrOdd = ptrOdd->next;
            ptrOdd->item = cur->item;
        }
        cur = cur->next;
        count++;
    }
    ptrOdd->next = NULL;
    ptrEven->next = NULL;
    (*ptrOddList) = (*ptrOddList)->next;
    (*ptrEvenList) = (*ptrEvenList)->next;
    return 1;

}

//int split(ListNode *cur, ListNode **ptrEvenList, ListNode **ptrOddList){
//    int count = 0;
//    ListNode *ptrEven = malloc(sizeof(ListNode));
//    ListNode *ptrOdd = malloc(sizeof(ListNode));
//    *ptrEvenList = ptrEven;
//    *ptrOddList = ptrOdd;
//    while(cur != NULL){
//        if(count%2 == 0){
//            // even
//            ptrEven->item = cur->item;
//            ptrEven->next = malloc(sizeof(ListNode));
//            ptrEven = ptrEven->next;
//        }
//        else if(count % 2 == 1){
//            ptrOdd->item = cur->item;
//            ptrOdd->next = malloc(sizeof(ListNode));
//            ptrOdd = ptrOdd->next;
//        }
//        cur = cur->next;
//        count++;
//    }
//    return 1;
//
//}

int main()
{
    ListNode *head = NULL, *temp;
    ListNode *evenHead = malloc(sizeof(ListNode)), *oddHead = malloc(sizeof(ListNode));
    LinkedList *ll = malloc(sizeof(LinkedList));
    ll->head = NULL;
    ll->size = 0;
    char misc = 0;
    int i = 0,j = 0;
    printf("Enter a list of numbers, terminated by any non-digit character:\n");
    while(scanf("%d", &i)){
        if(ll->head == NULL){
            ll->head = malloc(sizeof(ListNode));
            temp = ll->head;
        }
        else{
            temp->next = malloc(sizeof(ListNode));
            temp = temp->next;
        }
        temp->item = i;
        (ll->size)++;
    }
    temp->next = NULL;
    printList(ll->head);
    scanf("%c", &misc);
    printf("Please enter an index. (to FIND)\n");
    scanf("%d", &i);
    printf("%d\n", findNode(ll->head, i)->item);
    printf("Please enter an index, followed by a value (to ADD).\n");
    scanf("%d %d", &i, &j);
    insertNode2(ll, i, j);
    printList(ll->head);
    scanf("%c", &misc);
    printf("Please enter an index (to REMOVE).\n");
    scanf("%d", &i);
//    removeNode(&(ll->head), i);
    removeNode2(ll, i);
    printList(ll->head);
//    printf("\nThe total size of your list is: %d.", sizeList(ll->head));
    printf("\nThe total size of your list is: %d.\n", ll->size);
    printf("Performing split operation.\n");
    printf("Split: \n");
    split(ll->head, &evenHead, &oddHead);
    printList(ll->head);
    printList(evenHead);
    printList(oddHead);


    return 0;
}

