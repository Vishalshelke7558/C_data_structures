# include <stdio.h>
# include <stdlib.h>
struct node
{
    int data;
    struct node *next;
};
void trav(struct node*ptr)
{
    while(ptr != NULL)
    {
        printf("%d ", ptr -> data);
        ptr = ptr-> next;
    }
    printf("\n");
}
struct node *deletion_first(struct node * head)
{
    struct node *ptr = head;
    head = head -> next;
    free(ptr);
    return head;

}
struct node* deletion_index(struct node*head,int index)
{
    struct node *ptr = head;
    struct node* p = head -> next;
    for (int i = 0; i < 1; i++)
    {
        ptr = ptr -> next;
        p = p -> next; 
    }
    ptr -> next = p -> next;
    free(p);
    
    
    return head;
    
}

struct node*deletion_last(struct node*head)
{
    struct node* ptr = head;
    struct node*p = head->next;
    while (p != NULL)
    {
        ptr = ptr -> next;
        p = p -> next;
    }
    ptr -> next = NULL;
    free(p);
    return head;
}

struct node* deletion_atvalue(struct node*head,int value)
{
    struct node *ptr = head;
    struct node* p = head -> next;
    while (p -> data != value && p -> next != NULL)
    {
        ptr =  ptr -> next;
        p = p-> next;

    }
    if(ptr -> data == value)
    {
        ptr -> next = p -> next;
        free(ptr);
    }
    return head;
    
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

    head -> data = 7;
    head -> next = second;

    second -> data = 8;
    second -> next = third;

    third -> data = 10;
    third -> next = fourth;

    fourth -> data = 12;
    fourth -> next = NULL;
    
    printf("the element of the linked list before deletion\n");
    trav(head);

    printf("the element of the linked list after deletion first\n");
    head = deletion_first(head);
    trav(head);

   

    printf("the element of the linked list after deletion at index\n");;
    head = deletion_index(head,2);
    trav(head);

    printf("the element of the linked list after deletion at last\n");;
    deletion_last(head);
    trav(head);

    deletion_atvalue(head,8);
    trav(head);
    return 0;

}