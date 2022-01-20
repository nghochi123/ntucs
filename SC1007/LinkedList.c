#include <stdio.h>
#include <stdlib.h>

struct _listnode{
    int data;
    struct _listnode *next;
};

typedef struct _listnode ListNode;

int main(void){
    ListNode *head = NULL, *temp;
    int i = 0;

    while (scanf("%d", &i)){
        if (head == NULL){
            head = malloc(sizeof(ListNode));
            temp = head;
        }
        else {
            temp->next = malloc(sizeof(ListNOde));
            temp = temp->next;
        }
        temp->item = i;
    }
    temp->next=  NULL;

    return 0;
}
