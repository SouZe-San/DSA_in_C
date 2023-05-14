#include <stdio.h>
#include <stdlib.h>

struct LinkList
{
    int data;              // it store the integer of that node
    struct LinkList *next; // Re-referance /----/ next is a struct type pointer that point another  'struct LinkList' type variable(meaning another node)
};

// FUNCTION FOR TRVERSAL
void TraversalInLinklikst(struct LinkList *nodePtr)
{
    while (nodePtr != NULL)
    {
        printf("%d ",nodePtr->data);
        nodePtr = nodePtr->next;
    }
}

int main()
{

    // MEMORY ALLOCATION
    struct LinkList *head; // Pointer of Head Node or starting point of linklist
    head = (struct LinkList *)malloc(sizeof(struct LinkList));
    // second node
    struct LinkList *second;
    second = (struct LinkList *)malloc(sizeof(struct LinkList));
    // THIED NODE
    struct LinkList *third;
    third = (struct LinkList *)malloc(sizeof(struct LinkList));
    //  FOURTH NONDE
    struct LinkList *fourth;
    fourth = (struct LinkList *)malloc(sizeof(struct LinkList));

    // GIVEN DATA AND LINK NEXT NODE

    head->data = 23;
    head->next = second; // connect head node to second node (head ka next point to second node)

    second->data = 24;
    second->next = third;

    third->data = 25;
    third->next = fourth;

    fourth->data = 26;
    fourth->next = NULL;

    // THRAVERSAL
    TraversalInLinklikst(head);

    return 0;
}