#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

void bubblesort(int arr[],int size){
        int temp;
        for (int i = 0; i < size; i++)
        {
            for (int j = 0; j < size - i - 1; j++)
            {
                if (arr[j+1] < arr[j])
                {
                   temp = arr[j];
                   arr[j] = arr[j+1];
                   arr[j+1] = temp;
                }
                
            }
            
        }
}

int main()
{
    int arr[5] = {2,10,0,7,90};
    bubblesort(arr,5);
    for (int i = 0; i < 5; i++)
    {
        printf(" %d ",arr[i]);
    }
    
    return 0;
}