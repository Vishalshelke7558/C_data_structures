# include <stdio.h>
# include <stdlib.h>

int trav(int *arr, int n)
{
    for (int i = 0; i < n; i++)
    {
       printf("%d ", arr[i]);
    }
    printf("\n");
    
}

void bubblesort(int *arr,int n)
{
    int temp;
    for (int i = 0; i < n-1; i++) // for number of pass
    {
        printf("the number of passes is %d\n", i+1);
        int sorted = 1; // if array is already sorted then we can check it in one pass

        
        for (int j = 0; j < n-1-i; j++) // for deal with each swap
        {
            
            if (arr[j] > arr[j+1])
            {
                temp = arr[j+1];
                arr[j+1] = arr[j];
                arr[j] = temp;
                sorted = 0;
            }
            
        }
        if (sorted)
        {
            return;
        }
        
        
    }
    
}

int main()
{
    int arr[] = {1,5,4,3,6,2};
    // int arr[] = {1,2,3,4,5,6};

    printf("the array before bubble sorting is \n");
    trav(arr,6);

    bubblesort(arr,6);

    printf("the array after bubble sorting is \n");
    trav(arr,6);

    return 0;
}