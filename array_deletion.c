# include <stdio.h>
void show(int array[],int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", array[i]);
    }
    printf("\n");
}
void deletion(int array[],int index,int size)
{
    for (int i = index; i < size -1; i++)
    {
        array[i] = array[i+1];
    }
    
}

int main()
{
    int array[100] = {1,2,3,4,5};
    int size = 5;
    int index = 2;
    printf("the element of the before seletion is\n");
    show(array, size);
    printf("the elemnt of the array before deletion is:\n");
    deletion(array,index,size);
    size -= 1;
    show(array,size);
    return 0;
}