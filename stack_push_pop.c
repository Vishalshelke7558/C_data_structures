# include <stdio.h>
# include <stdlib.h>
struct stack
{
    int size;
    int top;
    int *arr;
};

int isempty(struct stack*ptr)
{
    if(ptr -> top == -1)
    {
        return 1;
    }

    else
    {
        return 0;
    }
}

int isfull(struct stack * ptr)
{
    if(ptr -> top == ptr -> size-1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void push(struct stack*ptr, int val)
{
    if(isfull(ptr))
    {
        printf("the stack is full\n");
    }
    else
    {
        ptr-> top = ptr ->top+1;
        ptr -> arr[ptr -> top] = val;
    }
}

int pop(struct stack*ptr)
{
    if(isempty(ptr))
    {
        printf("we cant do the poping operation\n");
        return -1;
    }
    else
    {

        int val = ptr->arr[ptr ->top];
        ptr -> top = ptr -> top-1;
        return val;

    }

}

void display(struct stack*ptr,int top)
{
    for (int i = 0; i < top; i++)
    {
        printf("the element of the stack is %d \n",ptr ->arr[i]);
    }
    
}

int main()
{
    struct stack *s;
    s = (struct stack*)malloc(sizeof(struct stack));
    s -> size = 6;
    s -> top = -1;
    s -> arr = (int*)malloc(s->size * sizeof(int));
    printf("%d \n", isempty(s));
    printf("%d \n", isfull(s));


    push(s,5);
    push(s,10);
    push(s,15);

    printf("the element of the stack after pushing\n");
    display(s,s->top);

    printf("%d \n", isempty(s));
    printf("%d \n", isfull(s));

    printf("the poping element is %d\n", pop(s));
    printf("the poping element is %d\n", pop(s));
    printf("the poping element is %d\n", pop(s));
    printf("the element of the stack after poping\n");



    return 0;
}