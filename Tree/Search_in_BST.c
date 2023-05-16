#include <stdio.h>
#include <stdlib.h>
struct trees
{
    int data;
    struct trees *left;
    struct trees *right;
};
struct trees *childCreate(int value)
{
    struct trees *ptr = (struct trees *)malloc(sizeof(struct trees)); // Creat A Child and Allocate meamory in heap
    ptr->data = value;
    ptr->left = NULL;
    ptr->right = NULL;
}

void inOrederTraverdsal(struct trees *root)
{
    if (root != NULL)
    {
        inOrederTraverdsal(root->left);
        printf("%d ", root->data);
        inOrederTraverdsal(root->right);
    }
}

struct trees *searchInBTS(struct trees *root, int val)
{
    if (root == NULL) // if null tree khali then return NULL -----> it will excegute whent the value dont present in BTS
    {
        return NULL;
        // printf("Don't present");
    }
    if (root->data > val) // val root er thke choto thrm go left in this  way continue
    {
        return searchInBTS(root->left, val);
    }
    else if (root->data < val)
    {
        return searchInBTS(root->right, val);
    }
    else
    {
        return root;
        // printf("Yes the %d number present in this BST",val);------> this Should Work But Dont know why not work!!!
    }
}

// ONE ITRATIVE METHODE FOR THIS SEARCH OPERATON IN BTS:::: ----> another way for searching element in bst <----
struct trees *itretiveSearch(struct trees *root, int val)
{
    while (root != NULL)
    {
        if (val < root->data){
            root = root->left;
        }
        else if (val > root->data) {
            root = root->right;
        }
        else{
            return root;
        }
    }
    return NULL;
}
int main()
{
    // creating bts....
    struct trees *root = (struct trees *)malloc(sizeof(struct trees));
    root->data = 12;
    struct trees *child1 = childCreate(8);
    struct trees *child2 = childCreate(20);
    root->left = child1;
    root->right = child2;
    struct trees *child1_1 = childCreate(5);
    struct trees *child1_2 = childCreate(10);
    struct trees *child2_2 = childCreate(25);
    child1->left = child1_1;
    child1->right = child1_2;
    child2->right = child2_2;

    struct trees *n = searchInBTS(root, 12);
    if (n != NULL)
    {
        printf("\n Yes! The %d number present in this BST", n->data);
    }
    else
    {
        printf("\n Don't present");
    }
    
    struct trees *p=itretiveSearch(root,3);
    if (p != NULL)
    {
        printf("\n Yes! The %d number present in this BST", p->data);
    }
    else
    {
        printf("\n Don't present");
    }

    return 0;
}