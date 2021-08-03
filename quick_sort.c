#include <stdio.h>
#include <stdlib.h>

void trav(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int part(int arr[], int low, int high)
{
    int pivot = arr[low];
    int i = low + 1;
    int j = high;
    int temp;

    do
    {
        while (arr[i] <= pivot)
        {
            i++;
        }
        while (arr[j] > pivot)
        {
            j--;
        }
        if (i < j)
        {
            temp = arr[i];
            arr[i] = arr[j];
            arr[i] = temp;
        }
    } while (i < j);

    temp = arr[low];
    arr[low] = arr[j];
    arr[j] = temp;

    return j;
}
void quick_sort(int arr[], int low, int high)
{
    int part_index;

    if (low < high)
    {
        part_index = part(arr, low, high);
        quick_sort(arr, low, part_index + 1);  // sort left sub array
        quick_sort(arr, part_index + 1, high); // sort right sub array
    }
}

int main()
{
    int arr[] = {5, 1, 7, 9, 8, 4, 1};
    int n = 7;
    trav(arr, n);

    quick_sort(arr, 0, n - 1);

    trav(arr,n);
    return 0;
}