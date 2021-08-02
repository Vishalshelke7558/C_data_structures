# include <stdio.h>
# include <stdlib.h>

void trav(int arr[], int n)
{
    for (int i = 0; i <= n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void insertion_sort(int arr[], int n)
{
    int k, j;
    for (int i = 1; i <= n-1; i++) // loop for passes
    {
         k = arr[i];
         j = i-1;
         while (j >= 0 && arr[j] > k)
         {
            arr[j+1] = arr[j];
            j--;
         }
         arr[j+1] = k;
         
    }
    
}

int main()
{
    int arr[] = {5,8,7,6,2,3,9,4};

    int n = sizeof(arr)/sizeof(int);
    trav(arr, n);

    insertion_sort(arr,n);

    trav(arr,n);

    return 0;
}