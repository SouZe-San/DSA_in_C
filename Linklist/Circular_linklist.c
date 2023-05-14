#include <stdio.h>
#include <stdlib.h>
struct linklist
{
    int data;
    struct linklist *next;
};

void linklistTraversal(struct linklist * ptr){
    struct linklist * head = ptr;
    do
    {
        printf("the Eliement is : %d\n",ptr->data);
        ptr = ptr->next;
    } while (ptr != head );

    /*  UPPER WALA MERA HAI NIJE WALAVI KESEKTE HAI
    here 'head' named pointer recived hobe insteed 'ptr'
    struct linklist * ptr = head;
    do
    {
        printf("the Eliement is : %d\n",ptr->data);
        ptr = ptr->next;
    } while (ptr != head );
    */
}

struct linklist* insertionAtFirst(struct linklist* head, int val){
    struct linklist *ptr = (struct linklist *)malloc(sizeof(struct linklist)); // ----> Creating a new node
    ptr->data = val;

    struct linklist * p = head->next;
    while (p->next != head)  // porer ta head hole agertai stop hobe jate "p" last node hote pare;;;
    {
        p = p->next;
    }
    p->next = ptr;
    ptr->next =head; // bonding kora holo
    head = ptr ; // ptr node take head bole deckear koraholo.....
    return head;
}
int main()
{

    struct linklist *head;                                     // struct type pointer
    head = (struct linklist *)malloc(sizeof(struct linklist)); // store the address of the first node ....
    struct linklist *node1 = (struct linklist *)malloc(sizeof(struct linklist));
    struct linklist *node2 = (struct linklist *)malloc(sizeof(struct linklist));
    struct linklist *node3 = (struct linklist *)malloc(sizeof(struct linklist));

    head->data = 40;
    head->next = node1;
    node1->data = 45;
    node1->next = node2;
    node2->data = 50;
    node2->next = node3;
    node3->data = 55;
    node3->next = head;

 printf("BEFORE INSETION\n");
    linklistTraversal(head);
    head = insertionAtFirst(head,35);
 printf("\n After INSETION at First\n");
  linklistTraversal(head);
    return 0;
}