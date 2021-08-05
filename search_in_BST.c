# include <stdio.h>
# include <stdlib.h>

struct node
{
    int data;
    struct node*left;
    struct node*right;
};

struct node* createnode(int data)
{
    struct node*n;
    n = (struct node*)malloc(sizeof(struct node));
    n -> data = data;
    n -> left = NULL;
    n -> right = NULL;
    return n;
}

void inorder(struct node*root)
{
    if(root !=  NULL)
    {
        inorder(root -> left);
        printf("%d ", root -> data);
        inorder(root -> right);
    }
}

struct node*search(struct node* root, int key)
{
    if(root == NULL)
    {
        return NULL;
    }
    if(root -> data == key )
    {
        return root;
    }
    if(key > root -> data)
    {
        return search(root -> right, key);
    }
    if(key < root -> data)
    {
        return search(root -> left, key);
    }
}

int main()
{

    //           8
    //        /      \
    //       2        11
    //     /   \     /  \
    //    1     3   9   13

    // binary  search tree gives the sorted array 


    struct node*p = createnode(8);
    struct node*p1 = createnode(2);
    struct node*p2 = createnode(11);

    struct node*p1_1 = createnode(1);
    struct node*p1_2 = createnode(3);

    struct node*p2_1 = createnode(9);
    struct node*p2_2 = createnode(13);

    p -> left = p1;
    p -> right = p2;

    p1 -> left = p1_1;
    p1 -> right = p1_2;

    p2 -> left = p2_1;
    p2 -> right = p2_2;

    inorder(p);
    printf("\n");
    struct node *n = search(p,11);
    if (n != NULL)
    {
        printf("found: %d\n", n -> data);
    }
    else
    {
        printf("element not found\n");
    }
    

    
    struct node *r = search(p,5);
    if (r != NULL)
    {
        printf("found: %d\n", r -> data);
    }
    else
    {
        printf("element not found\n");
    }
    


    return 0;
}