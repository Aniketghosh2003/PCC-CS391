#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

void swap(int a, int b)
{
    int c = a;
    a = b;
    b = c;
}

void heapify(int *arr, int size, int i)
{
    int largrest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < size && arr[left] > arr[largrest])
    {
        largrest = left;
    }
    else if (right < size && arr[right] > arr[largrest])
    {
        largrest = right;
    }
    if (largrest != i)
    {
        swap(arr[largrest], arr[i]);
        heapify(arr, size, largrest);
    }
}

void heapsort(int *arr, int size)
{
    while (size > 0)
    {
        swap(arr[0], arr[size]);
        size--;

        heapify(arr, size, 0);
    }
}
int main()
{
    int arr[] = {2, 10, 0, 7, 90};

    heapsort(arr, 5);
    for (int i = 0; i < 5; i++)
    {
        printf(" %d ", arr[i]);
    }

    return 0;
}