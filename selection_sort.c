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

void selection_sort(int arr[], int n)
{
    int index_min;
    int temp;
    for (int i = 0; i < n-1; i++)
    {
        index_min = i;
        for (int j = i+1; j < n; j++)
        {
            if (arr[j] < arr[index_min])
            {
                index_min = j;
            }   
        }
        // swapping given position number with minumum number in array
        
        temp = arr[i];
        arr[i] = arr[index_min];
        arr[index_min] = temp;
        
    }
    
}
int main()
{
    int arr[] = {5,4,2,8,9,10};
    int n = sizeof(arr)/sizeof(int);

    trav(arr, n);

    selection_sort(arr,n);

    trav(arr, n);
    return 0;
}