#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

void selectionsort(int arr[],int size){
    for (int i = 0; i < size; i++)
    {
       int min = arr[i];
       for (int j = 0; j < size; j++)
       {
        if (min > arr[j])
        {
            min = arr[j];
        }
       }
       int c = arr[i];
       arr[i] = min;
       min = c;
    } 
}

int main()
{
    int arr[5] = {2,10,0,7,90};
    selectionsort(arr,5);
    for (int i = 0; i < 5; i++)
    {
        printf(" %d ",arr[i]);
    }
    
    return 0;
}