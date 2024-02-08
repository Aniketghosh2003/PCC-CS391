#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int a[50], b[50];

int merge(int *arr, int s, int e)
{

    int mid = s + (e - s) / 2;
    int len1 = mid - s + 1;
    int len2 = e - mid;
    int mainindex = s;

    for (int i = 0; i < len1; i++)
    {
        a[i] = arr[mainindex++];
    }

    mainindex = mid + 1;
    for (int i = 0; i < len2; i++)
    {
        b[i] = arr[mainindex++];
    }

    int i1 = 0;
    int i2 = 0;
    mainindex = s;

    while (i1 < len1 && i2 < len2)
    {
        if (a[i1] < b[i2])
        {
            arr[mainindex++] = a[i1++];
        }
        else
        {
            arr[mainindex++] = b[i2++];
        }
    }

    while (i1 < len1)
    {
        arr[mainindex++] = a[i1++];
    }
    while (i2 < len2)
    {
        arr[mainindex++] = b[i2++];
    }
}

void mergesort(int *arr, int s, int e)
{
    if (s >= e)
    {
        return;
    }
    int mid = s + (e - s) / 2;
    mergesort(arr, s, mid);
    mergesort(arr, mid + 1, e);
    merge(arr, s, e);
}

int main()
{
    int arr[5] = {2, -1, 0, 7, 90};
    mergesort(arr, 0, 4);
    for (int i = 0; i < 5; i++)
    {
        printf(" %d ", arr[i]);
    }
    return 0;
}