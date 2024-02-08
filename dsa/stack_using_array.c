#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#define max 50

int arr[max];
int top = -1;

int peek(){
   if (top == -1)
   {
      printf("Stack is empty");
   }
   return arr[top];
   
}

void pop(){
    if (top == -1)
   {
      printf("Stack is empty");
   }
   else
   {
    printf("Deleted element is %d",arr[top]);
    top--;
   }
}

void push(int element){
if (top == max -1)
{
    printf("Stack overflow");

}

arr[++top] = element;
}



int main()
{
    push(3);
    push(2);
    push(8);
    push(9);
    push(10);
    pop();
    return 0;
}