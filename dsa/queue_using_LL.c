#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

typedef struct
{
    int data;
    struct node *next;
} qu;

qu *front = NULL;
qu *rear = NULL;

void enqueue(int val)
{
    qu *new = (qu *)malloc(sizeof(qu));
    new->data = val;
    if (front == NULL && rear == NULL)
    {
        front = rear = new;
    }
    else
    {
        rear->next = new;
        rear = new;
        rear->next = NULL;
    }
}

void dequeue()
{

    if (front == NULL && rear == NULL)
    {
        printf("\nUnderflow \n");
    }
    else
    {
        qu *pop = front;
        printf("\nDeleted elemenyt is %d\n", front->data);
        front = front->next;
        free(pop);
    }
}

void display()
{
    if (front == NULL && rear == NULL)
    {
        printf("\nUnderflow \n");
    }
    else
    {
        qu *temp;
        temp = front;
        while (temp)
        {
            printf("\t%d", temp->data);
            temp = temp->next;
        }
    }
}

int main()
{
    enqueue(3);
    enqueue(4);
    enqueue(6);
    display();
    dequeue();
    display();
    return 0;
}