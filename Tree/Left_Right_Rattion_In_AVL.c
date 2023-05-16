#include <stdio.h>
#include <stdlib.h>
struct avl
{
    int data;
    int height;
    struct avl *right;
    struct avl *left;
};

struct avl *createNode(int key)
{
    struct avl *node = (struct avl *)malloc(sizeof(struct avl));
    node->data = key;
    node->height = 1;
    node->right = NULL;
    node->left = NULL;
    return node;
}

// For get Height of an node ---------------------
int height(struct avl *node)
{
    if (node == NULL)
    {
        return 0;
    }
    return node->height;
}

// BF = balance Factor -----------------------
int balanceFactor(struct avl *node)
{
    if (node == NULL)
    {
        return 0;
    }
    return height(node->left) - height(node->right);
}

// Get max among two -----------------------
int max(int a, int b)
{
    return (a > b) ? a : b; // "condition" ? "if true" : "else"
}

//  ///////////////////////////////
struct avl *leftRotation(struct avl *x)
{
    // Which had
    struct avl *y = x->right;
    struct avl *T2 = y->left;

    // What happen after transform::
    y->left = x;
    x->right = T2;

    //  for the Balance Factor Correct the height ----
    x->height = max(height(x->right), height(x->left)) + 1;
    y->height = max(height(y->right), height(y->left)) + 1;
    return y;
}

// ////////////////////////////////
struct avl *rightRotation(struct avl *y)
{
    // What had
    struct avl *x = y->left;
    struct avl *T2 = x->right;

    // What Will Happen after transform
    x->right = y;
    y->left = T2;

    // Correction The height
    x->height = max(height(x->left), height(x->right)) + 1;
    y->height = max(height(y->right), height(y->left)) + 1;
    return x;
}

struct avl *nodeInsertion(struct avl *root, int key)
{
    if (root == NULL)
    {
        return createNode(key);
    }
    if (key > root->data)
        root->right = nodeInsertion(root->right, key);
    else if (key < root->data)
        root->left = nodeInsertion(root->left, key);

    root->height = max(height(root->left), height(root->right)) + 1;
    // Checking the Balance factor of Root after Add;
    int bf = balanceFactor(root);

    // then Have 4 case of rotation------
    //  1. Right rotation ------  left left case----------------
    if (bf > 1 && key < root->left->data)
    {
        return rightRotation(root);
    }

    //  2.Left rotation -- right right case-------
    if (bf < -1 && key > root->right->data)
    {
        return leftRotation(root);
    }

    //  3. Left right rotation ------ left right  case---------
    if (bf > 1 && key > root->left->data)
    {
        root->left = leftRotation(root->left);
        return rightRotation(root);
    }

    //  4. right left Rotation -- ----- -right left case --------
    if (bf < -1 && key < root->right->data)
    {
        root->right = rightRotation(root->right);
        return leftRotation(root);
    }

    return root;
}

void preOrderTraves(struct avl* root){  // root -> left part -> right part
    if (root!= NULL)
    {
        printf("%d ",root->data);
        preOrderTraves(root->left);
        preOrderTraves(root->right);

    }
    
}



int main()
{
 struct avl* root = NULL;
 
    root = nodeInsertion(root, 1);
    root = nodeInsertion(root, 2);
    root = nodeInsertion(root, 4);
    root = nodeInsertion(root, 5);
    root = nodeInsertion(root, 6);
    root = nodeInsertion(root, 3);
    preOrderTraves(root);
    return 0;
}

 /*     
     y                               x
    / \     Right Rotation          /  \
   x   T3   - - - - - - - >        T1   y 
  / \       < - - - - - - -            / \
 T1  T2     Left Rotation            T2  T3
 */