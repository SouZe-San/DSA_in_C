// [[[[[[[[[[[[[[[[[[[[[[[8******************* CIRCULAR QUEUE USING ARRAY ********************8]]]]]]]]]]]]]]]]]]]]]]]

#include <stdio.h>
#include <stdlib.h>

struct Circularqueue
{
    int size;
    int firstPlace;
    int lastPlace;
    int *arr;
};

// IN  previous case we use linear methode...........trversal made in a circular methode or should say its kind ..the number repete it self after a crtain point..
// methode = {0,1,2,3..}%size of the array..grneraly we use the reminder as the index for traversal.....

int isFull(struct Circularqueue *ptr)
{
    if ((ptr->lastPlace + 1) % ptr->size == ptr->firstPlace) // if the next th place of current last equle of or it is the entry/firstplace then it fulll
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
int isEmpty(struct Circularqueue *ptr)
{
    if (ptr->lastPlace == ptr->firstPlace)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void enQueue(struct Circularqueue *ptr, int val){
    if (isFull(ptr)){
        printf("Counter Now Full !%d COME NEXT TIME\n",val);
    }
    else{
        ptr->lastPlace = (ptr->lastPlace + 1) % ptr->size; // previos last ka +1 .. if 3 is the previous place then 3+1=4%size = 4%8= 4 is current place.... 
        ptr->arr[ptr->lastPlace] = val;
         printf( "Latest EnQueued Number is: %d in %d index.\n",val,ptr->lastPlace);
    }
}
int deQueue(struct Circularqueue* ptr){
    if (isEmpty(ptr))
    {
        printf("SORRRRy! There noOne left to be leave;\n");
    }
    else
    {
       ptr->firstPlace = (ptr->firstPlace+1)%ptr->size;  // same as concept the first place move forward by one...
       int val = ptr->arr[ptr->firstPlace];
       printf("From index%d ,",ptr->firstPlace);
         return val;
    }
    
}
int main()
{
    struct Circularqueue* qu = (struct Circularqueue*)malloc(sizeof(struct Circularqueue)); //MEMORY ALLOCATATE IN HIP MEMORY ........
    qu->firstPlace = qu->lastPlace =0;
    qu->size =6;
    qu->arr=(int*)malloc(qu->size*sizeof(int));

    enQueue(qu,43);
    enQueue(qu,52);
    enQueue(qu,44);
    enQueue(qu,45);
    enQueue(qu,23);
    enQueue(qu,64);

    printf("Dequeuing element %d\n", deQueue(qu));
    printf("Dequeuing element %d\n", deQueue(qu));
    printf("Dequeuing element %d\n", deQueue(qu)); 

    enQueue(qu,83);
    enQueue(qu,34);

    if(isEmpty(qu)){
        printf("Queue is empty\n");
    }
   
    if(isFull(qu)){
         printf(" The Line is full , Place out\n");
    }
     else printf("\nStill not full\n");

    return 0;
}
// 22222222222222222222222222222222222222222  FULL SUCCEFUL QUEUE 7777777777777777777777777777777777777777777777