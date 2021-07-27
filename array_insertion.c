# include <stdio.h>
void display(int array[], int n)
{   
    // diplay operation of array element.
    for (int i = 0; i < n; i++)
    {
        printf("%d\n",array[i]);
    }
    
}
int ind_insertion(int array[], int size, int element,int cap, int index)
{
    //code for insertion
    if (size >= cap)
    {
        return -1; // show insertion is not sucessful
    }
    for (int i = size-1; i >= index; i--)
    {
        array[i+1] = array[i];
    }
    array[index] = element;
    return 1;//shoe insertion is sucessful
    
    
}


int main()
{
    int array[100] = {2,3,5,8,10};
    int size = 5;
    int element = 4;
    int index = 1;
    
    printf("array before insertion:\n");
    display(array,size);
    ind_insertion(array,size,element, 100,index);
    size = size +1;
    printf("the array after insertion: \n");
    display(array,size);
    return 0;
}