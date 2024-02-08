#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

typedef struct node
{

    int data;
    struct node *left;
    struct node *right;

} bst;

bst *createNode(int value)
{
    bst *newNode = (bst *)malloc(sizeof(bst));
    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;

    return newNode;
}

bst *insertbst(bst *root, int val)
{

    if (root == NULL)
    {
        root = createNode(val);
        return root;
    }
    else if (root->data > val)
    {
        root->left = insertbst(root->left, val);
    }
    else
    {
        root->right = insertbst(root->right, val);
    }
    return root;
}

void inorder(bst *root)
{
    if (root == NULL)
    {
        return;
    }
    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}

bst *deletenode(bst *root, int val)
{

    if (root == NULL)
    {
        printf("\nNothing to delete");
    }
    else if (root->data == val)
    {

        if (root->left == NULL && root->right == NULL)
        {
            free(root);
            return NULL;
        }

        if (root->left != NULL && root->right == NULL)
        {
            bst *temp = root->left;
            free(root);
            return temp;
        }
        if (root->left == NULL && root->right != NULL)
        {
            bst *temp = root->right;
            free(root);
            return temp;
        }

        if (root->left == NULL && root->right == NULL)
        {
            int mini = minnode(root->right);
            root->data = mini;
            root->right = deletenode(root->right, mini);
            return root;
        }
    }
    else if (root->data > val)
    {
        deletenode(root->left, val);
        return root;
    }
    else if (root->data < val)
    {
        deletenode(root->right, val);
        return root;
    }
}

int minnode(bst *root)
{
    bst *temp = root;
    while (temp != NULL)
    {
        temp = temp->left;
    }
    return temp->data;
}

int main()
{
    bst *root = NULL;
    root = insertbst(root, 5);
    root = insertbst(root, 3);
    root = insertbst(root, 2);
    root = insertbst(root, 4);
    root = insertbst(root, 7);
    root = insertbst(root, 6);
    root = insertbst(root, 8);

    inorder(root);

    deletenode(root, 3);
    printf("\n");
    inorder(root);
    return 0;
}