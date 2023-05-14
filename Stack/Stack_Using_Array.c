
// ========================== HERE HAVE ALL OPERATION of STACK aS ARRYA, LIKE- push,pop,peek,stackTop,StackBottom..... 

#include <stdio.h>
#include <stdlib.h>

struct stack
{
    int max_size;
    int top;
    int *arr;
};

// function for define is it empty ?
int isEmpty(struct stack *ptr)
{
    if (ptr->top == -1)
    {
        printf("the Satack Is EMPTY\n");
        return 1;
    }
    else
    {
        printf("the STACK is not empty\n");
        return 0;
    }
}

// function for define is it Full or have some space for further push  ?
void isFull(struct stack *ptr)
{
    if (ptr->top == ptr->max_size - 1)
    {
        printf("the Satack Is now FULL\n");
    }
    else
    {
        printf("the STACK is not full\n");
    }
}

// PUSH OPERATIION------------------
void push(struct stack *ptr, int val)
{
    if (ptr->top == ptr->max_size - 1)
    {
        printf("PUSH not possible,Stack Overflow!!\n");
    }
    else
    {
        ptr->top++;
        ptr->arr[ptr->top] = val;
    }
}

// PoP OPERATION---------------------
int popUp(struct stack *ptr)
{
    if (ptr->top == -1)
    {
        printf("POp operation not possible, stack Underflow!!\n");
        return -1;
    }
    else
    {
        int val = ptr->arr[ptr->top];
        ptr->top = ptr->top - 1;
        return val;
    }
}

// PEEK OPERATION -------------------------------
int peek(struct stack *ptr, int index)
{
    int position = ptr->top - index + 1;
    if (position < 0)
    {
        printf("You have put wrong index,");
    }
    else
    {
        return ptr->arr[position];
    }
}

// function for search STACK-TOP element------------------
int SatckTop(struct stack *ptr){
    if (ptr->top == -1)
    {
        printf("The stack is now empty, so no Top element");
        return -1;
    } 
    else{
        int ele = ptr->arr[ptr->top];
        return ele;
        }  
}

// Function for find Bottom element from stack-------------
int StackBottom(struct stack *ptr){
     if (ptr->top == -1)
    {
        printf("The stack is now empty, Bottom Element Dosen't Exsit");
        return -1;
    } 
    else{
        return ptr->arr[0];
        }  
}

int main()
{
    struct stack *st = (struct stack *)malloc(sizeof(struct stack));  // here we allocate memory in mallock and recive pointr or address of that space/memory 
    st->max_size = 8; // capcaity of the array
    st->top = -1;     // location or index of stack data
    st->arr = (int *)malloc(st->max_size * sizeof(int));

    // Upper code can be right like this also
    // struct stack s;
    // s.size = 80;
    // s.top = -1;
    // s.arr = (int *) malloc(s.size * sizeof(int));
    // -------------//IF WE USE this DECLEARTION 
    // push(&st, 23); --- MEANING insteed of pointer declear normaly------  Then have to pass the adderss of that stack type variable...

    push(st, 23); //first element---  INDEX-1
    push(st, 99); //---: INDEX : 2 
    push(st, 75); //---: INDEX : 3  
    push(st, 3); //----:INDEX : 4
    push(st, 64); //---: INDEX : 5 
    push(st, 57); //---: INDEX :  6
    push(st, 54); //---: INDEX :  7
    push(st, 51); //---: INDEX :  8 --> last pushed element(top element)
    push(st, 52); //---: INDEX :  9 *** its overflow the stack can't pused in stack

    // isEmpty(st);
    // isFull(st);
    printf("\n3rd Element of this Stack is %d\n",peek(st,3));
    printf("\nlast element %d \n", st->arr[st->top]); //------------ Normaly find the last insert element.
    printf("\nPopped %d from the stack\n", popUp(st));
    printf("\n-----Top Element From the stack:%d\n",SatckTop(st)); ///  Last pushed or toppest elment of stack.
    printf("\n===BOTTOM ELEMENT From the stack:%d\n",StackBottom(st)); //-----------> First insert element

    isEmpty(st);
    isFull(st);
    return 0;
}