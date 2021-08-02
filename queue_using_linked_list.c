# include <stdio.h>
# include <stdlib.h>

struct node *f;
struct node *r;

struct node
{
    int data;
    struct node *next;
};

void trav(struct node*ptr)
{
    while(ptr != NULL)
    {
        printf("%d\n", ptr -> data);
        ptr = ptr -> next;
    }
}

void enqueue( int data)
{
    struct node *n = (struct node*)malloc(sizeof(struct node));
    if(n == NULL)
    {
        printf("queue is full\n");
    }
    else
    {
        n -> data = data;
        n -> next = NULL;
        if(f == NULL)
        {
            f = r = n;
        }
        else
        {
            r ->next = n;
            r = n;
        }
    }

}

void dequeue()
{
    int val = -1;
    struct node*p;
    p = f;
    if(f == NULL)
    {
        printf("queue is empty\n");
    }
    else
    {
       
        f = f -> next;
        val = p -> data;
        free(p);
        printf("%d\n",val);


    }
}

int main()
{
    
    f == NULL;
    r == NULL;

    enqueue(5);
    enqueue(10);
    enqueue(15);
    

    printf("the element which are enqueue is\n");
    trav(f);

    printf("the element which are dequeue is\n");
    dequeue();
    dequeue();
    dequeue();
    dequeue();
    

    return 0;
}