# include <stdio.h>
# include <limits.h>
# include <stdlib.h>


void trav(int *arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);

    }
    printf("\n");    
}


int maximum(int arr[], int n)
{
    int max = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        if (max < arr[i])
        {
            max = arr[i];
        }
        
    }
    return max;  
}


void count_sort(int *arr, int n)
{
    int i,j;
    // find the maximum element in the a
    int max = maximum(arr, n);
    
    int * count = (int*)malloc((max+1)*sizeof(int));
    for ( i = 0; i < max+1; i++)
    {
        count[i] = 0;
    }
    
    // incriment the index value by one
    for ( i = 0; i < max+1; i++)
    {
        count[arr[i]] = count[arr[i]] + 1;
    }

    i =0; // counter for count array
    j =0; // counter for given array

    while (i <= max)
    {
        if(count[i] > 0)
        {
           arr[j] = i;
           count[i] = count[i] -1;
           j++; 
        }
        else
        {
            i++;
        }
    }
    
}


int main()
{
    int arr[] = {5,2,3,7,4,9,8};

    int n = 7;

    trav(arr,n);

    count_sort(arr,n);

    trav(arr,n);

    return 0;
}