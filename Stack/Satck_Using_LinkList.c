// [[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[  Here All Stack Operation Using LINKLIST ]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]

#include <stdio.h>
#include <stdlib.h>

struct Linklist //---------------> At first insilise the linklist
{
    int data;
    struct Linklist *next;
};

struct Linklist *top = NULL; /*------>declare the top pointer globally., Declaring it globally gives its access to all our functions without passing them as a parameter.. Generally This is for Pop Operation So its dosent become comeplex..............*/

/* Two return type Function for find stack full or empty---------*/
int Isempty(struct Linklist *node)
{
    if (node == NULL)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
int IsFull(struct Linklist *node)
{
    struct Linklist *p = (struct Linklist *)malloc(sizeof(struct Linklist));
    // stack will be full if NO MORE NODE CAN BE create by using Hip ,Which kind of iposssible -- memory fully exhusted
    if (p == NULL)
    {
        return 1;
    }
    else
        return 0;
}

// TRAVERSAL IN STACK THROUGH LINKLIST:::
void StackTrsversal(struct Linklist *ptr)
{
    // int i = 0;
    if (Isempty(ptr))
    {
        printf("The Stack is Now UnderFlow;\n");
    }
    else
    {
        printf("\nTHE PRESENT ELEMENT IN STACK ARE :::::\n--> ");
        while (ptr != NULL)
        {
            printf(" %d ", ptr->data);
            ptr = ptr->next;
        }
        printf("\n");
    }
}

struct Linklist *Push(struct Linklist *node, int ele)
{
    if (IsFull(node))
    {
        printf("The Stack Is now Overflow!\n");
    }
    else
    {
        struct Linklist *p = (struct Linklist *)malloc(sizeof(struct Linklist)); //--> Make A new Node Whare New element will be stored
        p->data = ele;
        p->next = node; //------> New node ko  Last(First) Node ke sathe Connect kerdia,Then
        node = p;       // ------->previous node means top k new node k point kora holo then return 'node'
        return node;
    }
}

int pop(struct Linklist *lastNode)
{
    if (Isempty(lastNode))
    {
        printf(" NotPossible,,The Stack Is Underflow!!! ");
    }
    else
    {
        struct Linklist *delNode = lastNode; // At first made a pointer that point top node.
        top = lastNode->next;                // the 'top' become next topnode of stack
        int deletElement = delNode->data;    // store data of deleting node
        free(delNode);
        return deletElement;
    }
}

// this is littile bit compleceted becz here As parapeter uses pointer to pointer ....
// int pop(struct Node** top){
//     if(isEmpty(*top)){
//         printf("Stack Underflow\n");
//     }
//     else{
//         struct Node* n = *top;
//         *top = (*top)->next;
//         int x = n->data;
//         free(n);
//         return x;
//     }
// }

// PEEK OPERATION THROUGH LINKLIST IN STACK  :::
// INDEX::    top-> 6   5   4   (3)   2   1   0
// POSI:::         1    2   3    4
int peekInStack(int index)
{
    struct Linklist *ptr = top; //------->create a pointer for track the node(index from top) as command --- And point that pointer to the head of that stack
    for (int i = 0; i < index-1 && ptr != NULL; i++)
    {
        ptr = ptr->next;
    }
    if (ptr != NULL)
    {
        return ptr->data;
    }
    else
    {
        return -1;
    }
}


int main()
{
    top = Push(top, 78);
    top = Push(top, 7);
    top = Push(top, 8);
    top = Push(top, 28);
    top = Push(top, 71);
    top = Push(top, 84);
    top = Push(top, 48);
    top = Push(top, 54);
    top = Push(top, 32);

    StackTrsversal(top);
    printf("\nPopped element is %d\n", pop(top));
    int i;
    printf("\nAt what Position U want to look::\n--->");
    scanf("%d", &i);
    printf("\nValue at position %d is : %d\n", i, peekInStack(i));

    return 0;
}