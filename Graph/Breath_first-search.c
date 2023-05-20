// ---------------------------------    THIS TRAVERSAL TECHNIQUE NEED QUEUE IMPLEMENTATION---------------------

#include <stdio.h>
#include <stdlib.h>
struct queue
{
    int size;
    int front;
    int rear;
    int *arr;
};

int isEmpty(struct queue *q)
{
    if (q->front == q->rear)
    {
        return 1;
    }
    return 0;
}

int isFull(struct queue *q)
{
    if (q->rear == q->size - 1)
    {
        return 1;
    }
    return 0;
}

void enqueue(struct queue *q, int data)
{
    if (isFull(q))
    {
        printf("Queue is full\n");
        return;
    }
    q->arr[q->rear] = data;
    q->rear++;
}

int dequeue(struct queue *q)
{
    if (isEmpty(q))
    {  printf("Underflow !");}
    int val = q->arr[q->front];
    q->front++;
    return val;
}


int main()
{
    // Initialisation of Queue
    struct queue *q = (struct queue *)malloc(sizeof(struct queue));
    q->size = 10;
    q->front =  q->rear = 0;
    q->arr = (int *)malloc(q->size * sizeof(int));


    // BFS Implementation
    int i = 1, vertex;
    int visited[7] = {0, 0, 0, 0, 0, 0, 0};
    // >> Adjacency matrix representation of that graph
    int a[7][7] = {
        {0, 1, 1, 1, 0, 0, 0},
        {1, 0, 1, 0, 0, 0, 0},
        {1, 1, 0, 1, 1, 0, 0},
        {1, 0, 1, 0, 1, 0, 0},
        {0, 0, 1, 1, 0, 1, 1},
        {0, 0, 0, 0, 1, 0, 0},
        {0, 0, 0, 0, 1, 0, 0}};

    // BFS Algorithm start
    printf("%d",i);
    visited[i] =1;
    enqueue(q, i); // ------> enqueued the first vertex for exploration other vertex which are connected
    while (!isEmpty(q))
    {
        vertex = dequeue(q); //->> chosen the vertex for finding other connected vertex 
        for (int j = 0; j < 7; j++)
        {
            if (visited[j] == 0 && a[vertex][j] == 1) // ->> check which vertex are not visited and connected
            {
                printf("%d", j);
                visited[j] = 1; // marker as visited
                enqueue(q, j); // which are not explore those goes to queue
            }
        }
        
    }
    return 0;
}