#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *left;
    struct node *right;
};

struct node *creat_node(int data)
{
    struct node *n; // creating a node pointer
    n = (struct node *)malloc(sizeof(struct node));
    n->data = data;
    n->left = NULL;
    n->right = NULL;
    return n;
}

// code for preorder trav
void preorder(struct node *root)
{
    if (root != NULL)
    {
        printf("%d ", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

// code for postorder trav
void postorder(struct node *root)
{
    if (root != NULL)
    {
        postorder(root -> left);
        postorder(root -> right);
        printf("%d ", root -> data);
    }
}

// code for inorder trav
void inorder(struct node *root)
{
    if (root != NULL)
    {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

int main()
{

    //          2
    //       /      \
    //       6        4
    //     /   \     /  \
    //    8    10   12  14  


    // constructing the root node
    struct node *p = creat_node(2);
    struct node *p1 = creat_node(4);
    struct node *p2 = creat_node(6);

    struct node *p1_1 = creat_node(8);
    struct node *p1_2 = creat_node(10);

    struct node *p2_1 = creat_node(12);
    struct node *p2_2 = creat_node(14);

    p->left = p1;
    p->right = p2;

    p1->left = p1_1;
    p1->right = p1_2;

    p2->left = p2_1;
    p2->right = p2_2;

    printf("trav in tree by preorder traversal is\n");
    preorder(p);
    printf("\n");

    printf("trav in tree by preorder traversal is\n");
    postorder(p);
    printf("\n");

    printf("trav in tree by inorder traversal is\n");
    inorder(p);
    printf("\n");

    return 0;
}