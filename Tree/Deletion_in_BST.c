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

struct bst *inPreSuccesor(struct bst *root)
{
    root = root->left; // At first root ka left  node ko root banaya then If there Left Sub tree Present then it take most right element.....
    while (root->right != NULL)
    {
        root->right = root->right;
    }
    return root;
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

struct bst *deletationInBST(struct bst *root, int value)
{
    struct bst *inPre;
    if (root == NULL)
    {
        printf("\nThe tree is Blank Now!..\n Ther No Element like this for delete...");
        return NULL;
    }
    if (root->left == NULL && root->right == NULL && root->data == value)
    { // If Have one Node in BST only delete happens
        free(root);
        return NULL;
    }
    //  Proses goes in deep If tree is long....
    if (value > root->data)
    {
        root->right = deletationInBST(root->right, value);
    }
    else if (value < root->data)
    {
        root->left = deletationInBST(root->left, value);
    }
    else
    {
        inPre = inPreSuccesor(root); //---> this root not the lead rooot
        root->data = inPre->data;
        // As we take PreSuccessor then that mean it's Value will be less than the root's value .
        root->left = deletationInBST(inPre, inPre->data);
    }

    return root;
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
    printf("Before Insertion:-> ");
    inorderTraversal(root);
    deletationInBST(root, 3);
    printf("\n");
    printf("After Insertion:-> ");
    inorderTraversal(root);

    return 0;
}