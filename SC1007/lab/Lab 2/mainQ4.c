#include <stdio.h>
#include <stdlib.h>

#define SIZE 1000 //The limit of expression length

typedef struct _stackNode
{
    char item;
    struct _stackNode *next;
} StackNode;

typedef struct _stack
{
    int size;
    StackNode *head;
} Stack;

void push(Stack *sPtr, char item);
int pop(Stack *sPtr);
char peek(Stack s);
int isEmptyStack(Stack s);

void in2Post(char *, char *);

int main()
{
    char infix[SIZE];
    char postfix[SIZE];

    printf("Enter an infix expression:\n");
    scanf("%[^\n]%*c", infix);

    in2Post(infix, postfix);
    printf("The postfix expression is \n");
    printf("%s\n", postfix);
    return 0;
}

void push(Stack *sPtr, char item)
{
    StackNode *newNode;
    newNode = (StackNode *)malloc(sizeof(StackNode));
    newNode->item = item;
    newNode->next = sPtr->head;
    sPtr->head = newNode;
    sPtr->size++;
}

int pop(Stack *sPtr)
{
    if (sPtr == NULL || sPtr->head == NULL)
    {
        return 0;
    }
    else
    {
        StackNode *temp = sPtr->head;
        sPtr->head = sPtr->head->next;
        free(temp);
        sPtr->size--;
        return 1;
    }
}

char peek(Stack s)
{
    return s.head->item;
}

int isEmptyStack(Stack s)
{
    if (s.size == 0)
        return 1;
    else
        return 0;
}

void in2Post(char *infix, char *postfix)
{
    // Rules for the conversion from infix to postfix expression

    // Print the operand as they arrive.
    // If the stack is empty or contains a left parenthesis on top, push the incoming operator on to the stack.
    // If the incoming symbol is '(', push it on to the stack.
    // If the incoming symbol is ')', pop the stack and print the operators until the left parenthesis is found.
    // If the incoming symbol has higher precedence than the top of the stack, push it on the stack.
    // If the incoming symbol has lower precedence than the top of the stack, pop and print the top of the stack. Then test the incoming operator against the new top of the stack.
    // If the incoming operator has the same precedence with the top of the stack then use the associativity rules. If the associativity is from left to right then pop and print the top of the stack then push the incoming operator. If the associativity is from right to left then push the incoming operator.
    // At the end of the expression, pop and print all the operators of the stack.
}