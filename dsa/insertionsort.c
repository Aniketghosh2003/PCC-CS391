#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

void insertionsort(int arr[],int size){
    for (int i = 1; i < size; i++)
    {
        int key = arr[i];
        int j = i-1;
        while(j >= 0 && key < arr[j]){
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = key;
    }
    
}

int main()
{
    int arr[5] = {2,10,0,7,90};
    insertionsort(arr,5);
    for (int i = 0; i < 5; i++)
    {
        printf(" %d ",arr[i]);
    }
    
    return 0;
}