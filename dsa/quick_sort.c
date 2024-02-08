#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int partition(int *arr, int s, int e)
{

    int pivot = arr[s];
    int cnt = 0;
    for (int i = s + 1; i <= e; i++)
    {
        if (arr[i] < pivot)
        {
            cnt++;
        }
    }

    int pivotindex = s + cnt;
    int c = arr[pivotindex];
    arr[pivotindex] = arr[s];
    arr[s] = c;

    int i = s;
    int j = e;

    while (i < pivotindex && j > pivotindex)
    {
        while (arr[i] < pivot)
        {
            i++;
        }
        while (arr[j] >= pivot)
        {
            j--;
        }
        if (i < pivotindex && j > pivotindex)
        {
            int c = arr[i];
            arr[i] = arr[j];
            arr[j] = c;
            i++;
            j--;
        }
    }

    return pivotindex;
}

void quicksort(int *arr, int s, int e)
{
    if (s >= e)
    {
        return;
    }
    int p = partition(arr, s, e);

    quicksort(arr, s, p);
    quicksort(arr, p + 1, e);
}

int main()
{
    int arr[5] = {2, 10, 0, 90, 90};
    quicksort(arr, 0, 4);
    for (int i = 0; i < 5; i++)
    {
        printf(" %d ", arr[i]);
    }
    return 0;
}