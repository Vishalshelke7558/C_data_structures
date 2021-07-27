// code for the insertion operation in liked list

# include <stdio.h>
# include <stdlib.h>
struct node
{
    int data;
    struct node *next;
};

void trav(struct node *ptr)
{
    while(ptr != NULL)
    {
        printf("%d ", ptr -> data);
        ptr = ptr -> next;
    }
    printf("\n");
}

struct node *insert_first(struct node * head,int data) // code for insertion at first
{ //this function returing new head
    struct node *ptr = (struct node*)malloc(sizeof(struct node));
    ptr -> next = head;
    ptr -> data = data;
    return ptr;

}

struct node *insert_between(struct node * head,int data,int index) //code for insertion between
{
    struct node *ptr = (struct node*)malloc(sizeof(struct node));
    struct node *p = head;
    int i = 0;

    while(i != index-1)
    {
        p  = p->next;

    }
    ptr -> next = p-> next;
    p -> next =ptr;
    ptr -> data = data;
    return head;

}

struct node *insert_end(struct node* head,int data) // code for insert at the end
{
    struct node* ptr = (struct node*)malloc(sizeof(struct node));
    struct node *p = head;
    while(p -> next != NULL)
    {
        p = p->next;
    }
    p -> next = ptr;
    ptr -> next = NULL;
    ptr -> data = data;
    return head;
    
}

struct node *insert_after_node(struct node *head,struct node *prev_node,int data) // code for insert 
{
    struct node *ptr = (struct node*)malloc(sizeof(struct node));
    ptr -> next = prev_node -> next;
    prev_node -> next = ptr;
    ptr -> data = data;
    return head;

}


int main()
{
    struct node *head;
    struct node *second;
    struct node *third;
    struct node *forth;

    head = (struct node*)malloc(sizeof(struct node));
    second = (struct node*)malloc(sizeof(struct node));
    third = (struct node*)malloc(sizeof(struct node));
    forth = (struct node*)malloc(sizeof(struct node));

    head -> data = 7;
    head -> next = second;

    second -> data = 10;
    second -> next = third;

    third -> data = 15;
    third -> next = forth;

    forth -> data = 20;
    forth -> next = NULL;

    printf("linked list before insertion at first:\n");
    trav(head);
    printf("linked list after insertion at first:\n");
    head = insert_first(head, 56); // updating head
    trav(head);

    printf("linked list after insert between:\n");
    head = insert_between(head, 55 ,1);
    trav(head);

    printf("linked list after adding a node at end:\n");
    insert_end(head,57);
    trav(head);

    printf("liked list adding afre given node\n");
    head = insert_after_node(head,third,58);
    trav(head);

    return 0;
}