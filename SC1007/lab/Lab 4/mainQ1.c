#include <stdio.h>
#include <stdlib.h>

typedef struct _btnode
{
    int item;
    struct _btnode *left;
    struct _btnode *right;
} BTNode;

void insertBSTNode(BTNode **cur, int item);
void printBTNode(BTNode *root, int space, int left);
void deleteTree(BTNode **root);

int main()
{
    BTNode *root = NULL;
    int item;

    printf("Enter a list of numbers for a Binary Tree, terminated by any non-digit character: \n");
    while (scanf("%d", &item))
        insertBSTNode(&root, item);
    scanf("%*s");

    printf("The Binary Search Tree:\n");
    printBTNode(root, 0, 0);

    deleteTree(&root);
    root = NULL;
    return 0;
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

void insertBSTNode(BTNode **cur, int item)
{
    // Write Your Code Here
    if (*cur == NULL)
    {
        *cur = malloc(sizeof(BTNode));
        (*cur)->item = item;
        (*cur)->left = NULL;
        (*cur)->right = NULL;
        return;
    }
    BTNode *curr = *cur;
    while (0 == 0)
    {
        if (item > curr->item)
        {
            if (curr->right != NULL)
            {
                curr = curr->right;
            }
            else
            {
                curr->right = malloc(sizeof(BTNode));
                curr = curr->right;
                curr->left = NULL;
                curr->right = NULL;
                curr->item = item;
                break;
            }
        }
        else if (item < curr->item)
        {
            if (curr->left != NULL)
            {
                curr = curr->left;
            }
            else
            {
                curr->left = malloc(sizeof(BTNode));
                curr = curr->left;
                curr->left = NULL;
                curr->right = NULL;
                curr->item = item;
                break;
            }
        }
        else if (item == curr->item)
        {
            printf("Duplicated Item: %d\n", item);
            break;
        }
    }
}
