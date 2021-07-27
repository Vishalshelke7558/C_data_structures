#include <stdio.h>
void linear_search(int array[], int size)
{
    for (int i = 0; i < size; i++)
    {
        if (array[i] == 6)
        {
            printf("the index of the given number is %d\n", i);
        }
    }
}
void binary_search(int array[], int size, int element)
{
    int low = 0;
    int high = 5;
    int mid = (high + low) / 2;
    while (low <= high)
    {
        // start searching
        if (array[mid] == element)
        {
            printf("the index of the given array is %d", mid);
            break;
        }
        if (array[mid] > element)
        {
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
        //searching end
    }
    
}

int main()
{
    // search by using the linear search which do not required any sorted list
    int array[] = {2, 3, 4, 5, 6, 7};
    int size = sizeof(array) / sizeof(int);
    linear_search(array, size);

    // search by using the binary search
    
    int element = 4;
    binary_search(array,size,element);

    return 0;
}