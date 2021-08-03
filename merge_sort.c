# include <stdio.h>
# include <stdlib.h>

void trav(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
    
}


void merge(int arr[], int low, int high, int mid)
{
    int i = low;
    int j = mid+1;
    int k = 0;
    int B[100];
    while (i <= mid && j <= high)
    {
        if (arr[i] <= arr[j])
        {
            B[k] = arr[i];
            i++;
            k++;
        }
        else
        {
            B[k] = arr[j];
            j++;
            k++;
        }
        
    }
    while(i <= mid)
    {
        B[k] = arr[i];
        i++;
        k++;
    }
    while (j <= high)
    {
        B[k] = arr[j];
        j++;
        k++;
    }

    for (int i = 0; i <= high; i++)
    {
        arr[i] = B[i];
    }   
}

void merge_sort(int arr[], int low, int high)
{
    int mid;
    if(low < high)
    {
        mid = (low+high)/2;

        
        merge_sort(arr,low,mid);
        merge_sort(arr,mid+1,high);

        merge(arr,low,high,mid);
    }
}

int main()
{
    int arr[] = {2,5,8,7,4,3,10,7};
    // int arr[] = {10,11,12,13,5,6,7};
    int mid = 3;
    int low = 0;
    int high = 7;
    merge_sort(arr,0,7);
    int n = 8;
    trav(arr, n);

    return 0;
}