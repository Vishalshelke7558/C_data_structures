# include <stdio.h>
# include <stdlib.h>

struct stack
{
    int size;
    int top;
    int *arr;
};

int isfull(struct stack *ptr)
{
    if(ptr -> top >= ptr -> size-1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int isempty(struct stack * ptr)
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

void push(struct stack *ptr, int val)
{
    if(isfull(ptr))
    {
        printf("stack overflow\n");
    }
    else
    {
        ptr -> top = ptr -> top + 1;
        ptr ->arr[ptr -> top] = val;

    }
}

void pop(struct stack *ptr)
{
    if(isempty(ptr))
    {
        printf("stack is underflow\n");
        
    }
    else
    {
        int val = ptr -> arr[ptr -> top];
        ptr -> top = ptr -> top -1;
        printf("%d\n",val);
    }
}

int top(struct stack *ptr)
{
    return ptr -> arr[ptr -> top];
}

int bottom(struct stack *ptr)
{
    return ptr -> arr[0];
}

int main()
{
    struct stack *s;
    s = (struct stack*)malloc(sizeof(struct stack));
    s -> size = 6;
    s -> top = -1;
    s -> arr = (int*)malloc(s->size*sizeof(int));

    printf("%d \n", isfull(s));
    printf("%d \n", isempty(s));

    push(s,5);
    push(s,10);
    push(s,15);
    push(s,20);
    push(s,25);
    push(s,30);

    printf("%d \n", top(s));
    printf("%d \n", bottom(s));

    return 0;
}