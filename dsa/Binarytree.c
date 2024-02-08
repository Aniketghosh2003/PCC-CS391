#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

typedef struct node
{

    int data;
    struct node *left;
    struct node *right;

} bt;


bt* createNode(int value) {
  bt* newNode = (bt*)malloc(sizeof(bt));
  newNode->data = value;
  newNode->left = NULL;
  newNode->right = NULL;

  return newNode;
}

bt *bulidtree(bt *root)
{

    int d;
    printf("Enter the value :-");
    scanf("%d", &d);
    root = createNode(d);

    if (d == -1)
    {
        return NULL;
    }

    //printf("Enter the left side of data :-");
    root->left = bulidtree(root->left);
    //printf("Enter the right side of data :-");
    root->right = bulidtree(root->right);
    return root;
}



void inorder(bt* root){
    if(root == NULL)
       return ;
    inorder(root->left);
    printf("%d ->",root->data);
    inorder(root->right);   
}

void preorder(bt* root){
   if(root == NULL)
       return ;
    printf("%d ->",root->data);
    preorder(root->left);
    preorder(root->right);
}

void postorder(bt* root){
    if(root == NULL)
       return ;
    postorder(root->left);
    postorder(root->right);
    printf("%d ->",root->data);
    
}

int main()
{
    bt *root = NULL;
    bulidtree(root);
    inorder(root);
    return 0;
}