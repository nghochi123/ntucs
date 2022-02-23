#include <stdio.h>
#include <stdlib.h>

typedef struct _btnode
{
    int item;
    struct _btnode *left;
    struct _btnode *right;
} BTNode;

BTNode *insertBSTNode(BTNode *cur, int item);
void printBTNode(BTNode *root, int space, int left);
void deleteTree(BTNode **root);
int removeBSTNode(BTNode **nodePtr, int item);
BTNode *findBSTNode(BTNode **root, int val);

int main()
{
    BTNode *root = NULL;
    int item;

    printf("Enter a list of numbers for a Binary Tree, terminated by any non-digit character: \n");
    while (scanf("%d", &item))
        root = insertBSTNode(root, item);
    scanf("%*s");

    printf("The Binary Search Tree:\n");
    printBTNode(root, 0, 0);

    printf("Enter an integer to be removed from the tree:\n");
    scanf("%d", &item);

    if (removeBSTNode(&root, item))
        printf("%d was removed\n", item);

    else
        printf("%d is not in the tree.\n", item);

    printf("The Binary Search Tree:\n");
    printBTNode(root, 0, 0);

    deleteTree(&root);
    root = NULL;
    return 0;
}

BTNode *insertBSTNode(BTNode *cur, int item)
{
    if (cur == NULL)
    {
        BTNode *node = (BTNode *)malloc(sizeof(BTNode));
        node->item = item;
        node->left = node->right = NULL;
        return node;
    }
    if (item < cur->item)
        cur->left = insertBSTNode(cur->left, item);
    else if (item > cur->item)
        cur->right = insertBSTNode(cur->right, item);
    else
        printf("Duplicated Item: %d\n", item);

    return cur;
}

void printBTNode(BTNode *root, int space, int left)
{
    if (root != NULL)
    {

        int i;
        for (i = 0; i < space - 1; i++)
            printf("|\t");

        if (i < space)
        {
            if (left == 1)
                printf("|---");
            else
                printf("|___");
        }

        printf("%d\n", root->item);

        space++;
        printBTNode(root->left, space, 1);
        printBTNode(root->right, space, 0);
    }
}

void deleteTree(BTNode **root)
{
    if (*root != NULL)
    {
        deleteTree(&((*root)->left));
        deleteTree(&((*root)->right));
        free(*root);
        *root = NULL;
    }
}

int removeBSTNode(BTNode **nodePtr, int item)
{
    // Write Your Code Here
    BTNode *prev = NULL, *cur = *nodePtr;
    int side = -1; // Left 0 right 1
    while (cur->item != item)
    {
        if (item > cur->item)
        {
            if (cur->right == NULL)
            {
                cur = NULL;
                break;
            }
            prev = cur;
            cur = cur->right;
            side = 1;
        }
        else if (item < cur->item)
        {
            if (cur->left == NULL)
            {
                cur = NULL;
                break;
            }
            prev = cur;
            cur = cur->left;
            side = 0;
        }
        else
        {
            break;
        }
    }
    if (cur == NULL)
    {
        return 0;
    }
    else
    {
        if (cur->left == NULL && cur->right == NULL)
        {
            if (prev == NULL)
            {
                *nodePtr = NULL;
            }
            else if (side == 0)
            {
                prev->left = NULL;
            }
            else
            {
                prev->right = NULL;
            }
        }
        else if (cur->left != NULL && cur->right == NULL)
        {
            if (prev == NULL)
            {
                *nodePtr = cur->left;
            }
            else if (side == 0)
            {
                prev->left = cur->left;
            }
            else
            {

                prev->right = cur->left;
            }
        }
        else if (cur->left == NULL && cur->right != NULL)
        {
            if (prev == NULL)
            {
                *nodePtr = cur->right;
            }
            else if (side == 0)
            {
                prev->left = cur->right;
            }
            else
            {

                prev->right = cur->right;
            }
        }
        else if (cur->left != NULL && cur->right != NULL)
        {
            BTNode *p = cur, *c = cur->left;
            while (c->left != NULL)
            {
                p = c;
                c = c->left;
            }
            if (prev == NULL)
            {
                *nodePtr = c;
                c->left = cur->left;
                c->right = cur->right;
                p->left = NULL;
            }
            else if (side == 0)
            {
                p->left = NULL;
                prev->left = c;
                c->left = cur->left;
                c->right = cur->right;
            }
            else
            {
                p->left = NULL;
                prev->right = c;
                c->left = cur->left;
                c->right = cur->right;
            }
        }
        return 1;
    }
}
