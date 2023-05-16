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

void preOrederTravael(struct trees* root){  // root -> left part -> right part
    if (root!= NULL)
    {
        printf("%d ",root->data);
        preOrederTravael(root->left);
        preOrederTravael(root->right);

    }
    
}

void inOrederTraverdsal(struct trees *root){
    if (root!=NULL)
    {
        inOrederTraverdsal(root->left);
        printf("%d ",root->data);
        inOrederTraverdsal(root->right);
    }
    
}

int main()
{
    struct trees *root = (struct trees *)malloc(sizeof(struct trees));
    root->data = 4;
    struct trees *child1 = child(23);
    struct trees *child2 = child(20);
    root->left = child1;
    root->right = child2;
    struct trees *child1_1 = child(34);
    struct trees *child2_2 = child(40);
    child1->left = child1_1;
    child2->right = child2_2;
    preOrederTravael(root);
    printf("\n");
    inOrederTraverdsal(root);
    return 0;
}
/*

                  4  --> root
              /       \
            23           20 
          /  \         /   \
        34   null    null  40
       / \                / \
    null null          null null
    
*/