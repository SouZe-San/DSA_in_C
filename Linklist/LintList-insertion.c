#include <stdio.h>
#include <stdlib.h>

struct LinkList
{
    int data;
    struct LinkList *next;
};

// FUNCTION FOR TRVERSAL----------------------------------
void TraversalInLinklikst(struct LinkList *nodePtr)
{
    while (nodePtr != NULL)
    {
        printf("%d ", nodePtr->data);
        nodePtr = nodePtr->next;
    }
}

// FUNCTION FOR INSARTION------------------------------------

// INDERTION AT FIRST OF HEAD========
// called a function which return a 'struct type pointer' of new LINKLIST

 struct LinkList *InsertionAtFirst(struct LinkList*head,int ele){
    struct LinkList *ptr;
    ptr = (struct LinkList *)malloc(sizeof(struct LinkList));
    ptr->data=ele;
    ptr->next=head;
    return ptr;
 }

//INSERTION AT THE END =========
struct LinkList *InsertionAtEnd(struct LinkList *head, int ele)
{
    struct LinkList *ptr = (struct LinkList *)malloc(sizeof(struct LinkList));
    ptr->data = ele;
    struct LinkList *p = head;
    while (p->next != NULL)
    {
        p = p->next;
    }
    p->next = ptr;
    ptr->next = NULL;
    return head;
}

// INSERTION IN A MIDDEL INDEX=======
 struct LinkList *InsertionAtIndex(struct LinkList*head,int ele,int index){
    struct LinkList *ptr = (struct LinkList *)malloc(sizeof(struct LinkList));
     struct LinkList *p = head;
     int i =0;
    while (i != index-1)
    {
        p = p->next;
        i++;
    }
    ptr->data=ele;
    ptr->next = p->next; // At first 'ptr' matlab new node er next (where store address of next node) aa p node (index er ager node ta) er  next a thaka addrss store koraholo.
    p->next = ptr;// then p node er next k ptr a point koraholo.
    return head;
 }

//INSERTION AFTER A GIVEN NODE======================= 
 struct LinkList *InsertionAfterNode(struct LinkList*head,int ele,struct LinkList*node){
    struct LinkList *ptr = (struct LinkList *)malloc(sizeof(struct LinkList));
    ptr->data=ele;
    ptr->next = node->next;
    node->next = ptr;// then p node er next k ptr a point koraholo.
    return head;
 }

int main()
{

    // MEMORY ALLOCATION
    struct LinkList *head;
    head = (struct LinkList *)malloc(sizeof(struct LinkList));

    struct LinkList *second;
    second = (struct LinkList *)malloc(sizeof(struct LinkList));

    struct LinkList *third;
    third = (struct LinkList *)malloc(sizeof(struct LinkList));

    struct LinkList *fourth;
    fourth = (struct LinkList *)malloc(sizeof(struct LinkList));

    // GIVEN DATA AND LINK NEXT NODE

    head->data = 23;
    head->next = second;

    second->data = 24;
    second->next = third;

    third->data = 25;
    third->next = fourth;

    fourth->data = 26;
    fourth->next = NULL;

    printf("BEFORE INSETION\n");
    TraversalInLinklikst(head);
    head = InsertionAtFirst(head, 22);  // -----> O(1)
    head = InsertionAtEnd(head, 27);   // -----> O(n)
    head = InsertionAtIndex(head,244,2);    // -----> O(n)
    head = InsertionAfterNode(head,28,third);     // -----> O(1)
    printf("\nAFTER INSETION\n");
    TraversalInLinklikst(head);
    return 0;
}