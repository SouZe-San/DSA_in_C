#include<stdio.h>
#include <stdlib.h>

struct queue
{   int size;
    int firstPlace;
    int lastPlace;
    int *arr;
};

// ------------------------------ ALL OPERATIONS ------------------

int isFull(struct queue* ptr){
    if (ptr->lastPlace == ptr->size-1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
    
}
int isEmpty(struct queue* ptr){
    if (ptr->lastPlace == ptr->firstPlace)
    {
       return 1;
    }
    else
    {
       return 0;
    }
    
}

void enQueue(struct queue* ptr, int val){
    if (isFull(ptr))
    {
        printf("(*_*)  Queued is Full now ,%d element can't Enqueued.--- (.)(.) (>_<)\n",val);
    }
    else
    {
       ptr->lastPlace++;  // foreward the last place by one and placed one perrson in that placed..
       ptr->arr[ptr->lastPlace] = val;
       printf( "Latest enQueued Number is: %d\n",val);
    }
}

int deQueue(struct queue* ptr){
    if (isEmpty(ptr))
    {
        printf("SORRRRy! There no One to be leave;\n");
    }
    else
    {
       ptr->firstPlace++; // After remove the first person of the line we forward the counter by one step......
       int val = ptr->arr[ptr->firstPlace];
       return val;
    }

}



int main(){

    // Like in previous stack case we can Decleare the struct variable as normaly we call , then in function always have to pass the adderesses of this...
    // struct queue q;
    // q.size = 4;
    // q.f = q.r = 0;
    // q.arr = (int*) malloc(q.size*sizeof(int));
    //THAT'S WHY WE DECLEAR AS POINTER OF THAT STAUCT VARABLE AND THE Memory WILL BE ALLCATATE IN MALLLOC....................

    struct queue * qu = (struct queue*)malloc(sizeof(struct queue)) ;
    qu->size =5 ;
    qu->firstPlace =qu->lastPlace=0;
    qu->arr = (int*)malloc(qu->size*sizeof(int));

    enQueue(qu, 12);
    enQueue(qu, 15);
    enQueue(qu, 1); 
    printf("Dequeuing element %d\n", deQueue(qu));
    printf("Dequeuing element %d\n", deQueue(qu));
    printf("Dequeuing element %d\n", deQueue(qu)); 
    enQueue(qu, 45);
    enQueue(qu, 47);

      if(isEmpty(qu)){
        printf("Queue is empty\n");
    }
   
    if(isFull(qu)){
         printf(" The Line is full , Place out\n");
    }
     else printf("\nStill not full\n");
      
    return 0;
}

//  ********************8 {{{{[[[[[[[[[[[[[[[[[[[[[[[ DEFECT OF LINEAR QUEUE  ]]]]]]]]]]]]}}}}}}}}}8***************************************

//  This linear Queue have a big fault that is originalyy doesn't clear the space.......
// that's why even after dequeued some element the space doesn't clear  or SHOULD I SAY THE space clear but we denote or refer the array's Index by an integer,So After moving forward its doesn't back or placed backward.
// That's why after it move forward its back palce remain blank still can't used to fill any number..just because we cannot call that index..
// ONE WAY HAVE TO CALL THOSE IF WE WRITE LIKE THAT  "if firstPlace == size-1 " OR "WHEN QUEUE BECOME EMPTY AGAIN, firstplace == lastplace",THEN firstpalce = 0;  BUT FOR THAT QUEUE has to be empty.... That's mean we have to wait for it become Empty for reuse it...
//       ......FOR THAT SOLUTION CREAT A CIRCULAR QUEUE....