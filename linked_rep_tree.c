# include <stdio.h>
# include <stdlib.h>

struct node
{
    int data;
    struct node*left;
    struct node*right;

};


int main()
{
    // constructing the root node
    struct node*p;
    p = (struct node*)malloc(sizeof(struct node));
    p -> data = 2;
    p -> left = NULL;
    p -> right = NULL;

    

    // contrsucting the first child node of root node
    struct node*p1;
    p1 = (struct node*)malloc(sizeof(struct node));
    p1 -> data = 4;
    p1 -> left = NULL;
    p1 -> right = NULL;

    // contrsucting the first child node of root node
    struct node*p2;
    p2 = (struct node*)malloc(sizeof(struct node));
    p -> data = 8;
    p2 -> left = NULL;
    p2 -> right = NULL;

    // linking the root node with child node  (in left and right);
    p -> left = p1;
    p -> right = p2;

    return 0;
}