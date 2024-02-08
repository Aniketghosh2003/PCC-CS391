#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#define max 5

int arr[max];
int front = -1;
int rear = -1;

void enqueue(int val){
    if(((front == 0 )&&(rear == max - 1)) || (rear == front - 1)){
        printf("\n overflow \n");
    }
    else
    {
        if(rear == max - 1 && front != 0){
            rear = 0;
        }
        else if(front == -1){
            front = rear = 0;
        }
        else
        {
            rear++;
        }
        arr[rear] = val;
    }
    
}

void dequeue(){
     if(front == -1){
        printf("\n underflow \n");
     }
     else
     {
        printf("\nDeleted element is %d\n",arr[front]);
        if(front == rear){
            front = rear = -1;
        }
        else if(front == max -1 && rear != 0){
            front = 0;
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
        printf("\n Underflow \n");
    }
    else
    {
        if (front <= rear)
        {
            for (int i = front; i <= rear; i++)
            {
                printf("%d\t",arr[i]);
            }
            
        }
        else
        {
            for (int i = front; i < max; i++)
            {
                printf("%d\t",arr[i]);
            }
            for (int i = 0; i <= rear; i++)
            {
                 printf("%d\t",arr[i]);
            }
            
        } 
    }
}

int main()
{
    enqueue(6);
    enqueue(2);
    enqueue(1);
    display();
    
    
    return 0;
}