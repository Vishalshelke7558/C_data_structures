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

int isBST(struct node*root)
{
    static struct node*prev = NULL;
    if(root != NULL)
    {
        if(!isBST(root -> left))
        {
            return 0;
        }
        if(prev != NULL && root -> data <= prev -> data)
        {
            return 0;
        }
        prev = root;
        return isBST(root -> right);
    }
    else
    {
        return 1;
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
    struct node*p1 = createnode(2); // extre statement for checking true or false
    //struct node*p1 = createnode(12);
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

    printf("%d", isBST(p));


    return 0;
}