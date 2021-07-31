# include <stdio.h>
# include <stdlib.h>
# include <string.h>
struct stack
{
    int size;
    int top;
    char *arr;

};

int stack_top(struct stack *ptr)
{
    return ptr -> arr[ptr -> top];
}

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

int precedence(char ch)
{
    if(ch == '*' || ch == '/')
    {
        return 3;
    }
    else
    {
        return 1;
    }
}
int isOperator(char ch)
{
    if(ch == '+' || ch == '-' || ch == '*' || ch == '/')
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

char * in_to_po(char*infix)
{
    struct stack *s;
    s = (struct stack*)malloc(sizeof(struct stack));
    s -> size = 100;
    s -> top = -1;
    s -> arr = (char*)malloc(s->size*sizeof(char));
    char*postfix = (char*)malloc((strlen(infix +1))*sizeof(char));
    int i = 0; // for tracking infix trav
    int j = 0; // for track postfix trav
    while(infix[i] != '\0')
    {
        if(!isOperator(infix[i]))
        {
            postfix[j] = infix[i];
            j++;
            i++;

        }
        else
        {
            if(precedence(infix[i]) > precedence(stack_top(s)))
            {
                push(s,infix[i]);
                i++;
            }
            else
            {
                postfix[j] = pop(s);
                j++;
            }
        }
    }
    while (! isempty(s))
    {
        postfix[j] = pop(s);
        j++;
    }
    postfix[j] = '\0';
    

}

int main()
{

    char * infix = "a-b+t/6";
    printf("postfix is %s", in_to_po(infix));

    return 0;
}