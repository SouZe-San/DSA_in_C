#include <stdio.h>
#include <stdlib.h>

struct bst
{
    int data;
    struct bst *right;
    struct bst *left;
};

struct bst *childCreate(int val)
{
    struct bst *ptr = (struct bst *)malloc(sizeof(struct bst)); // Creat A Child and Allocate meamory in heap
    ptr->data = val;
    ptr->left = NULL;
    ptr->right = NULL;
}

void inorderTraversal(struct bst *root)
{
    if (root != NULL)
    {
        inorderTraversal(root->left);
        printf("%d ", root->data);
        inorderTraversal(root->right);
    }
}

void insertionInTrees(struct bst *root, int val)
{
    // create a pointer that help for pount the needed root;;;;
    struct bst *previous = NULL;
    // searching the where the element will be palced.....
    while (root != NULL)
    {
        previous = root ;
        if (val == root->data)
        {
            printf("\nTree Already have %d element, So According by BST-properties Insertion can't POSSIIBLE!", val);
            return ;
        }
        else if (val > root->data)
        {
            root = root->right;
        }
        else
        {
            root = root->left;
        }
    }
    //  After compelete search.. Nxet step will be the node will be root's Left or Right....
    struct bst *newchild = childCreate(val);
    if (val > previous->data)
    {
        previous->right = newchild;
    }
    else
    {
        previous->left = newchild;
    }

}

int main()
{

    // creating bst....
    struct bst *root = (struct bst *)malloc(sizeof(struct bst));
    root->data = 12;
    struct bst *child1 = childCreate(8);
    struct bst *child2 = childCreate(20);
    root->left = child1;
    root->right = child2;
    struct bst *child1_1 = childCreate(5);
    struct bst *child1_2 = childCreate(10);
    struct bst *child2_2 = childCreate(25);
    child1->left = child1_1;
    child1->right = child1_2;
    child2->right = child2_2;
    printf("Before Insertion: --->\n");
    inorderTraversal(root);
    insertionInTrees(root, 40);
    printf("\n");
    printf("After Insertion: --->\n");    
    inorderTraversal(root);

    return 0;
}