# include <stdio.h>
# include <stdlib.h>

struct queue
{
    int size;
    int f;
    int r;
    int *a;
    int *arr;
};

int isfull(struct queue*q)
{
    if(q->r == q -> size-1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int isempty(struct queue*q)
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

void dequeue(struct queue*q)
{
    
    if(isempty(q))
    {
        printf("we cant remove the item \n");
        
    }
    else
    {
        
        
        q ->a = q-> arr[q->f+1];
        printf("%d\n",q ->a);
        q -> f = q -> f+1;
        free(q->a);
        
    }
}

void enqueue(struct queue * q, int data)
{
    if(isfull(q))
    {
        printf("array overflow\n");
    }
    else
    {
        q -> r = q ->r+1;
        q->arr[q ->r] = data;
    }
}

int main()
{
    struct queue * q;
    q = (struct queue* )malloc(sizeof(struct queue));
    q -> size  = 3;
    q-> f = -1;
    q -> r  = -1;
    q -> arr  = (int*)malloc(q->size*sizeof(int));
    enqueue(q,12);
    enqueue(q,14);
    
    printf("%d\n",isfull(q));
    printf("%d\n",isempty(q));

    dequeue(q);
    dequeue(q);

    printf("%d\n",isfull(q));
    printf("%d\n",isempty(q));
    
    return 0;
}