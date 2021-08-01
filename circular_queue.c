# include <stdio.h>
# include <stdlib.h>

struct circularqueue
{
    int size;
    int f;
    int r;
    
    int *arr;
};

int isfull(struct circularqueue*q)
{
    if((q -> r+1)% (q-> size) ==  q -> f)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int isempty(struct circularqueue*q)
{
    if(q -> f == q -> r)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void dequeue(struct circularqueue*q)
{
    
    if(isempty(q))
    {
        printf("we cant remove the item \n");
        
    }
    else
    {
        
        int a;
        a = (q -> f+1) % (q -> size);
        printf("%d\n",q -> arr[a]);
        q -> f =  q -> f+1;
        
    }
}

void enqueue(struct circularqueue * q, int data)
{
    if(isfull(q))
    {
        printf("array overflow\n");
    }
    else
    {
        q -> r = (q ->r+1)% (q -> size);
        q->arr[q ->r] = data;
    }
}

int main()
{
    struct circularqueue * q;
    q = (struct circularqueue* )malloc(sizeof(struct circularqueue));
    q -> size  = 3;
    q-> f = 0;
    q -> r  = 0;
    q -> arr  = (int*)malloc(q->size*sizeof(int));

    printf("%d\n",isfull(q));
    printf("%d\n",isempty(q));


    enqueue(q,12);
    enqueue(q,14);
    
    
    
    dequeue(q);
    dequeue(q);

    enqueue(q,26);

    dequeue(q);
    


    printf("%d\n",isfull(q));
    printf("%d\n",isempty(q));
    
    return 0;
}