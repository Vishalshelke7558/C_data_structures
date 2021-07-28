# include <stdio.h>
# include <stdlib.h>
struct node
{
    int data;
    struct node*next;
};

void display(struct node*head) // code for display element of the circular linked list
{
    struct node* ptr = head;
   do
   {
       printf("%d ", ptr -> data);
       ptr = ptr -> next;
   } while (ptr != head);
   printf("\n");
   
}
struct node* insert(struct node*head, int data) // code for insertion in circular linked list
{
    struct node*ptr = (struct node*)malloc(sizeof(struct node));
    ptr -> data = data;
    struct node* p = head -> next;

    while (p -> next != head)
    {
        p = p -> next;
    }
    p -> next = ptr;
    ptr -> next = head;
    head = ptr;
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


    head -> data = 3;
    head -> next = second;

    second -> data = 5;
    second -> next = third;

    third -> data = 7;
    third -> next = fourth;

    fourth -> data = 9;
    fourth -> next = head;  // we use head as a next

    display(head);

    head = insert(head,10);
    display(head);

    return 0;
} 