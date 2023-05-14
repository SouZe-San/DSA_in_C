#include <stdio.h>
#include <stdlib.h>

struct linklist
{
    int data;
    struct linklist *next;
};
// for happy/useable use make global variable...
struct linklist *front = NULL; // Both are pointer of node.
struct linklist *last = NULL;

void TraversalInLinklikst(struct linklist *nodePtr)
{
    if (nodePtr == NULL)
    {
        printf("Nothing Have here\n");
    }
    else
    {
        while (nodePtr != NULL)
        {
            printf("%d ", nodePtr->data);
            nodePtr = nodePtr->next;
        }
        printf("\n");
    }
}

void enQueue(int val)
{

    // this is linklist so until the memory exhusted insertion can be donr,Mean which new node create that can't be null....
    struct linklist *newPlace = (struct linklist *)malloc(sizeof(struct linklist));
    if (newPlace == NULL)
    {
        printf("All Places are booked!\n");
    }
    else
    {
        newPlace->data = val;
        newPlace->next = NULL;
        if (front == NULL) //-->Normally 'first' and 'last' enitially Equally to NULL
        {
            front = last = newPlace; // then both forward and point to the next node..... like its Run Only At first....when queue isEmpty;
        }
        else
        {
            last->next = newPlace;
            last = newPlace;
        }
    }
}
int deQueue()
{
    struct linklist *ptr = front; // at first first elemnt k point kore rakha holo;
    if (front == NULL)
    {
        printf("No place for Clean, NOW IT NULL\n");
    }
    else
    {
        front = ptr->next;
        int val = ptr->data;
        return val;
        free(ptr);
    }
}

int main()
{
    TraversalInLinklikst(front);
    // deQueue();
    enQueue(43);
    enQueue(3);
    enQueue(57);
    enQueue(6);
    enQueue(437);
    enQueue(97);
    TraversalInLinklikst(front);
    printf("Dequeuing element %d\n", deQueue());
    printf("Dequeuing element %d\n", deQueue());    
    TraversalInLinklikst(front);
    return 0;
}