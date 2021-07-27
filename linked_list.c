// linked list creation and traversal

# include <stdio.h>
# include <stdlib.h>

struct Node
{
    int data;
    struct Node *next; // pointer pointing structure itself
};


void traversal(struct Node * ptr)
{
    while (ptr != NULL)
    {
    
        printf("element of linked list %d\n",ptr->data );
        ptr = ptr-> next;

    }
}


int main()
{   
    struct Node*head;
    struct Node*second;
    struct Node*third;

    // allocation of memory in heap which is poited by the head,second and third
    head = (struct Node*)malloc(sizeof(struct Node));
    second = (struct Node*)malloc(sizeof(struct Node));
    third = (struct Node*)malloc(sizeof(struct Node));

    // link first and second node
    head->data =  7;
    head->next = second;

    // link second and third node
    second->data = 11;
    second->next = third;

    //link third node to the NULL
    third->data = 15;
    third->next = NULL;
    

    traversal(head);
    return 0;
}