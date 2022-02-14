#include <stdio.h>
#include <stdlib.h>

#define SIZE 1000 //The limit of expression length

typedef struct _stackNode{
    char item;
    struct _stackNode *next;
}StackNode;

typedef struct _stack{
   int size;
   StackNode *head;
}Stack;

void push(Stack *sPtr, char item);
int pop(Stack *sPtr);
char peek(Stack s);
int isEmptyStack(Stack s);

void in2Pre(char*, char*);

int main()
{
    char infix[SIZE];
    char prefix[SIZE];

    printf("Enter an infix expression:\n");
    scanf("%[^\n]%*c",infix);

    in2Pre(infix,prefix);
    printf("The prefix expression is \n");
    printf("%s\n",prefix);

    return 0;
}

void push(Stack *sPtr, char item){
    StackNode *newNode;
    newNode = malloc(sizeof(StackNode));
    newNode->item = item;
    newNode->next = sPtr->head;
    sPtr->head = newNode;
    sPtr->size++;
}

int pop(Stack *sPtr){
    if(sPtr == NULL || sPtr->head == NULL){
        return 0;
    }
    else{
       StackNode *temp = sPtr->head;
       sPtr->head = sPtr->head->next;
       free(temp);
       sPtr->size--;
       return 1;
    }
}

char peek(Stack s){
    return s.head->item;
}

int isEmptyStack(Stack s){
     if(s.size == 0) return 1;
     else return 0;
}

void in2Pre(char* infix, char* prefix)
{
    //Write your code here
    int i = 0, j = 0;
    Stack s;
    s.head = NULL;
    s.size = 0;
    char temp[1000] = "";
    while(*(infix + i) != '\0'){
        i++;
    }
    i--;
    while(i >= 0){
        if(*(infix + i) == ')' || *(infix + i) == '+' || *(infix + i) == '-' || *(infix + i) == '*' || *(infix + i) == '/' || *(infix + i) == '('){
            if(*(infix + i) == '*' || *(infix + i) == '/' || *(infix + i) == ')'){
                push(&s, *(infix + i));
            }
            else if(*(infix + i) == '+' || *(infix + i) == '-'){
                while(s.size != 0 && (peek(s) == '*' || peek(s) == '/')){
                    temp[j] = peek(s);
                    j++;
                    pop(&s);
                }
                push(&s, *(infix + i));
            }
            else if(*(infix + i) == '('){
                while(peek(s) != ')'){
                    temp[j] = peek(s);
                    j++;
                    pop(&s);
                }
                pop(&s);
            } 
        }
        else{
            temp[j] = *(infix + i);
            j++;
        }
        // printf("%c ", *(infix + i));
        i--;
    }
    while(s.size != 0){
        if(peek(s) != ')'){
            temp[j] = peek(s);
            j++;
        }
        pop(&s);
    }
    j--;
    i = 0;
    while(j > 0){
        *(prefix + i) = *(temp + j);
        i++;
        j--;
    }
    *(prefix + i) = *(temp + j);
    *(prefix + i + 1) = '\0';


}