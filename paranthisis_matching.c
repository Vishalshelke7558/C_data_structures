# include <stdio.h>
# include <stdlib.h>
struct stack
{
    int size;
    int top;
    char *arr;

};

int isfull(struct stack*ptr)
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

int isempty(struct stack *ptr)
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

void push(struct stack *ptr, char data)
{
    if(isfull(ptr))
    {
        printf("we cant push the element\n");
        
    }
    else
    {
        ptr -> top = ptr -> top +1;
        ptr -> arr[ptr -> top] = data;

    }

}

char pop(struct stack *ptr)
{ 
    if(isempty(ptr))
    {
        printf("we cant pop the item\n");
        return -1;
    }
    else
    {
        char var = ptr->arr[ptr->top];
        ptr -> top = ptr -> top-1;
        return var;
    }
}

int para_math(char*exp)
{

    struct stack * s;
    s -> size = 100;
    s -> top = -1;
    for (int i = 0; i < '\0'; i++)
    {
        if(exp[i] = 'c')
        {
            push(s,'(');
        }
        else
        {
            if(isempty(s))
            {
                return 0;
            }
            else
            {
                pop(s);
            }

        }
    }
    if(isempty(s))
    {
        return 1;
    }
    else
    {
       return 0;
    }
    
}

int main()
{

    char*exp = "8*(9)";
    
    if(para_math(exp))
    {
        printf("the paranthis is matching\n");

    }
    else
    {
        printf("paranthis is not matching\n");
    }

    return 0;
}