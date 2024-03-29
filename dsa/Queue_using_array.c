#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#define max 50

int arr[max];
int front = -1;
int rear =  -1;


void enqueue(int val){
    if (rear == max - 1)
    {
        printf("\nQueue is full\n");
    }
    else
    {
        if (front == -1)
        {
            rear = 0;
            front = 0;
        }
        else
        {
            rear++;
        }
        arr[rear] = val;
        
    }
    
}

void dequeue(){
    if (front == -1)
    {
        printf("Queue is empty");
    }
    else
    {
        printf("\nDeleted element is %d\n",arr[front]);
        if (front == rear)
        {
            front = -1;
            rear = -1;
        }
        else
        {
            front++;
        }
    }
    
  
}

void display(){
    if (front == -1)
    {
       printf("\nNothing to display\n");
    }
    else
    {
        for (int i = front; i <= rear; i++)
        {
            printf("%d ",arr[i]);
        }
        
    }
    
}


int main()
{
    enqueue(2);
    enqueue(3);
    display();
    dequeue();
    display();
    dequeue();
    dequeue();
    
    return 0;
}