#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#define max 5

int arr[max];
int front = -1;
int rear = -1;

void enqueue_front(int val){
    if(((front == 0 )&&(rear == max - 1)) || (rear == front - 1)){
        printf("\n overflow \n");
    }
    else
    {
        if(front == -1){
            front = rear = 0;
        }
        else if(front == 0 && rear != max - 1){
            front = max - 1;
        }
        else
        {
            front--;
        }
        arr[front] = val;
    }
}

void enqueue_rear(int val){
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

void dequeue_front(){
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

void dequeue_rear(){
     if(front == -1){
        printf("\n underflow \n");
     }
     else
     {
        printf("\nDeleted element is %d\n",arr[rear]);
        if(front == rear){
            front = rear = -1;
        }
        else if (rear == 0 && front != max - 1)
        {
            rear = max - 1;
        }
        else
        {
            rear --;
        }
      
     }  
}
void dislay(){
    if(front == -1){
        printf("\n underflow \n");
     }
    else
    {
        if (front < rear)
        {
            for (int i = front; i <= rear; i++)
            {
                printf("\t%d",arr[i]);
            }
        }
        else
        {
            for (int i = front; i < max; i++)
            {
                printf("%d\t",arr[i]);
            }
        }

         for (int i = 0; i <= rear; i++)
            {
                 printf("%d\t",arr[i]);
            }
    }
     
}

int main()
{
    enqueue_front(2);
    enqueue_front(3);
    enqueue_front(4);
    dislay();

    return 0;
}