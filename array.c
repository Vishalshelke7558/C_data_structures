// ADT we can hide the method from the user by passing a address of the
//perticular data
//In this program we crate array by using dynamic memory allocation


# include <stdio.h>
# include<stdlib.h>
struct my_array
{
    int total_size;
    int used_size;
    int *ptr;
};

void create_array(struct my_array* a, int tsize, int usize)
{
    a->total_size = tsize;
    a->used_size = usize;
    a->ptr = (int*)malloc(tsize*sizeof(int));
}

void show(struct my_array *a)
{
    for (int i = 0; i < a->used_size; i++)
    {
        printf("%d",(a->ptr)[i]);
    }    
}

void set(struct my_array *a)
{
    int n;
    for (int i = 0; i < a->used_size; i++)
    {
        printf("entre the element of the array:\n");
        scanf("%d\n",&n);
        (a->ptr)[i] = n;
    }    
}

int main()
{
    struct my_array marks;
    create_array(&marks,10,2);
    printf("we are running now set the value\n");
    set(&marks);
    printf("show tha value\n");
    show(&marks);
    return 0;
}