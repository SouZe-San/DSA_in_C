#include <stdio.h>
#include <stdlib.h>

struct linklist
{
    int data;
    struct linklist *prev;
    struct linklist *next;
};

void traversalInForward(struct linklist *head)
{
    struct linklist *ptr = head;
    while (ptr != NULL)
    {
        printf("The Element is : %d\n", ptr->data);
        ptr = ptr->next;
    }
}

void traversalInBackward(struct linklist *head)
{
    struct linklist *ptr = head;
    while (ptr->next != NULL)
    {
        ptr = ptr->next;
    }
    while (ptr != NULL)
    {
        printf("The Element is : %d\n", ptr->data);
        ptr = ptr->prev;
    }
}

int main()
{
    struct linklist *head = (struct linklist *)malloc(sizeof(struct linklist));
    struct linklist *node1 = (struct linklist *)malloc(sizeof(struct linklist));
    struct linklist *node2 = (struct linklist *)malloc(sizeof(struct linklist));
    struct linklist *node3 = (struct linklist *)malloc(sizeof(struct linklist));

    head->data = 4;
    head->next = node1;
    head->prev = NULL;

    node1->prev = head;
    node1->data = 20;
    node1->next = node2;

    node2->prev = node1;
    node2->data = 30;
    node2->next = node3;

    node3->prev = node2;
    node3->data = 50;
    node3->next = NULL;

    printf("Display In Forward Manner\n");
    traversalInForward(head);
    printf("\nDisplay In Backward Manner\n");
    traversalInBackward(head);
    return 0;
}







// Do Other operation in your ideas
