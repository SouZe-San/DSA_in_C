#include <stdio.h>
#include <stdlib.h>

struct LinkList
{
    int data;             
    struct LinkList *next; 
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

// DELETETION AT FIRST ===========
struct LinkList *DeletationAtFirst(struct LinkList * head){
   struct LinkList * ptr = head;
    head = head->next;
      free(ptr);
    return head;
}

// DELETAION AT THE END
struct LinkList *DeletationAtLast(struct LinkList * head){
   struct LinkList * ptr = head;
    struct LinkList *p = head->next; //  p pointer is for point to after the NODE which point ptr
    while (p->next != NULL)
    {
        ptr = ptr->next;
        p = p->next;
    }
    ptr->next = NULL;
      free(p);
    return head;
}

// DELETE AI AN GIVEN INDEX==============
struct LinkList *DeletationAtIndex(struct LinkList * head,int index){
   struct LinkList * ptr = head;
    struct LinkList *p = head->next;
    int i =0;
    while (i < index-1)
    {
        ptr = ptr->next;
        p = p->next;
        i++;
    }
    ptr->next = p->next;
      free(p);
    return head;
}

// Deletion THE NODE  which's this Value Belongs ==============
struct LinkList *DeletationAtGivenValue(struct LinkList * head,int value){
   struct LinkList * ptr = head;
    struct LinkList *p = head->next;
  while (p->data == value && p->next == NULL)
  {
   ptr  = ptr->next;
   p = p->next;
  }
  if (p->data == value)
  {
   ptr->next = p->next;
      free(p);
  }
  
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
     struct LinkList *fifth;
    fifth = (struct LinkList *)malloc(sizeof(struct LinkList));
     struct LinkList *sixth;
    sixth = (struct LinkList *)malloc(sizeof(struct LinkList));

    // GIVEN DATA AND LINK NEXT NODE

    head->data = 23;
    head->next = second;

    second->data = 24;
    second->next = third;

    third->data = 25;
    third->next = fourth;

    fourth->data = 26;
    fourth->next = fifth;

    fifth->data = 27;
    fifth->next = sixth;

    sixth->data = 28;
    sixth->next = NULL;


    printf("BEFORE INSETION\n");
    TraversalInLinklikst(head);

    head = DeletationAtFirst(head);
    head = DeletationAtLast(head);
    head = DeletationAtIndex(head,1);
    head = DeletationAtGivenValue(head,24);
    printf("\nAFTER INSETION\n");
    TraversalInLinklikst(head);
    return 0;
}