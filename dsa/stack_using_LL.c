#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

typedef struct{
    int data;
    struct node *next;
}st;

st*top = NULL;

void push(int val){
     if (top == NULL)
     {
        top = (st*)malloc(sizeof(st));
        top->next = NULL;
        top->data = val;
     }
     else
     {
        st* new = (st*)malloc(sizeof(st));
        new->next = top;
        new->data = val;
        top = new;
     }
}

void pop(){
    if(top == NULL){
        printf("\n Underflow \n");
    }
    else
    {
        st* top1 = top;
        printf("\n popped element is %d \n",top1->data);
        top1 = top1->next;
        free(top);
        top = top1;
    }
}

void peek(){
    printf(" %d\n ",top->data);
}


int main()
{
    push(4);
    push(5);
    push(6);
    peek();
    pop();
    peek();
    return 0;
}