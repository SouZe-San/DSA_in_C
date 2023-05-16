#include <stdio.h>
#include <stdlib.h>
struct trees
{
    int data;
    struct trees *left;
    struct trees *right;
};
struct trees *child(int value)
{
    struct trees *ptr = (struct trees *)malloc(sizeof(struct trees)); // Creat A Child and Allocate meamory in heap
    ptr->data = value;
    ptr->left = NULL;
    ptr->right = NULL;
}

void inOrederTraverdsal(struct trees *root){
    if (root!=NULL)
    {
        inOrederTraverdsal(root->left);
        printf("%d ",root->data);
        inOrederTraverdsal(root->right);
    }
    
}
int isThisBST(struct trees *root)
{
    static struct trees *prev = NULL;  // this will idecate the leave(child-node) node the root... root ka next hoga prev
    // static : for this after many time recusive its valu will not rest....by NULL
    if (root != NULL)
    {
        if (!isThisBST(root->left))
        {
            // if left subtrees is not an binary tree then whole tree will not be a binary tree... so return 0;
            return 0;
        }
        else if (prev!= NULL && root->data <= prev->data)
        {
            return 0;
        }
        prev = root;
        return isThisBST(root->right);
        
    }
    else
    {
        return 1; // if root is null then stil it itself an binary tree
    }
    
}
int main()
{
    // creating bts....
    struct trees *root = (struct trees *)malloc(sizeof(struct trees));
    root->data = 12;
    struct trees *child1 = child(8);
    struct trees *child2 = child(20);
    root->left = child1;
    root->right = child2;
    struct trees *child1_1 = child(5);
    struct trees *child1_2 = child(10);
    struct trees *child2_2 = child(25);
    child1->left = child1_1;
    child1->right = child1_2;
    child2->right = child2_2;
/*
    Properties of BTS:
        1. value of left node of root should be less than root AND right valu should be grrreater 
*/
    inOrederTraverdsal(root);

    if (isThisBST(root))
    {
        printf("\n this is a BST");
    }
    else{
        printf("\n Not A BST");
    }
    
    
    return 0;
}