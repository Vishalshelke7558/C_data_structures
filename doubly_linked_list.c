# include <stdio.h>
# include <stdlib.h>

struct node
{
    int data;
    struct node* next;
    struct node* prev;

};

void display_next(struct node*head)
{
    struct node*ptr = head;
    while(ptr -> next != NULL)
    {
        printf("%d ", ptr -> data);
        ptr = ptr-> next;
    }
    printf("%d ", ptr -> data);
    printf("\n");
    
}
void display_prev(struct node*fourth)
{
    struct node*ptr = fourth;
    while(ptr -> prev != NULL)
    {
        printf("%d ", ptr -> data);
        ptr = ptr-> prev;
    }
    printf("%d ", ptr -> data);
    
}

int main()
{
    struct node*head;
    struct node*second;
    struct node*third;
    struct node*fourth;

    head = (struct node*)malloc(sizeof(struct node));
    second = (struct node*)malloc(sizeof(struct node));
    third = (struct node*)malloc(sizeof(struct node));
    fourth = (struct node*)malloc(sizeof(struct node));

    head -> data = 2;
    head -> next = second;
    head -> prev = NULL;

    second -> data = 4;
    second -> next = third;
    second -> prev = head;

    third -> data = 6;
    third -> next = fourth;
    third -> prev = second;

    fourth -> data = 8;
    fourth -> next = NULL;
    fourth -> prev = third;

    display_next(head);
    display_prev(fourth);

    return 0;
}