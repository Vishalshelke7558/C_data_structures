# include <stdio.h>
# include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

void trav(struct node*top)
{
    while (top != NULL)
    {
        printf("%d \n", top -> data);
        top = top -> next;
    }
    
}

int isfull(struct node*ptr)
{
   struct node* p = (struct node*)malloc(sizeof(struct node));
   if(p == NULL)
   {
       return 1;
   }
   else
   {
       return 0;
   }
}

int isempty(struct node*ptr)
{
    if(ptr == NULL)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

struct node*push(struct node *top, int data)
{
    if(isfull(top))
    {
        printf("stack overflow\n");
    }
    else
    {
        struct node *n = (struct node*)malloc(sizeof(struct node));
        n -> data = data;
        n -> next = top;
        top = n;
        
        return top;
    }
}

void pop(struct node** top)
{
    if(isempty(*top))
    {
        printf("stack is underflow\n");
        
    }
    else
    {
        struct node * n = *top;
        int  var = n -> data;
        (*top) = (*top) -> next;
        free(n);
        printf("%d \n", var);

    }
}

int peek(int pos, struct node *top)
{
    struct node * ptr = top;
    for (int i = 0; (i < pos -1 && i != NULL); i++)
    {
        ptr = ptr -> next;
    }

    if( ptr != NULL)
    {
        return ptr -> data;
    }
    else
    {
        return -1;
    }
    
}

void stack_top(struct node* top)
{
    printf( "%d \n" , top -> data);
}

void stack_bottom(struct node* top)
{
    struct node*ptr = top;
    while (ptr -> next < NULL)
    {
        ptr = ptr -> next;
    }
    int var = ptr -> data;
    printf("%d \n",var);
    
}

int main()
{
    struct node* top =NULL;
    top = push(top, 78);
    top = push(top, 80);
    top = push(top, 82);
    top = push(top, 84);
    top = push(top, 86);
    top = push(top, 88);

    // trav(top);
    
    printf("%d \n",peek(1,top));

    stack_top(top);
    
    stack_bottom(top);
    // pop(&top);
    // pop(&top);
    // pop(&top);

    return 0;
}