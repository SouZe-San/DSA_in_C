// {{{{{{{{{{{{[((((((((((((((((((((((----  AN APPLICATON OF STACK ------))))))))))))))))))))))]}}}}}}}}}}}}

#include<stdio.h>
#include <string.h>
#include <stdlib.h>

struct stack
{
    int top; 
    int size;
    char * arr;
};

int isEmpty(struct stack *ptr){
    if (ptr-> top == -1)
    {
        return 1;
    }
    else{
        return 0;
    }
    
}
int isFull(struct stack* ptr){
    if (ptr->top == ptr->size-1) 
    {
        return 1;   
    }
    else
    {
       return 0;
    }
    
}

int stackTop(struct stack * ptr){
    return ptr->arr[ptr->top];
}

void push(struct stack *ptr, char val){
    if (isFull(ptr))
    {
       printf("STACK OVERFLOW!!\n");
    }
    else
    {
       ptr->top++;
       ptr->arr[ptr->top] = val;
    }
    
}

char pop(struct stack * ptr){
    if (isEmpty(ptr))
    {
       printf("STACK UNDERFLOW!!\n");
    }
    else
    {
       char val = ptr->arr[ptr->top];
       ptr->top--;
       return val;
    }    
}

int isOparetors(char exp){
    if (exp == '+' || exp == '-' ||exp == '*' ||exp == '/')
    {
       return 1;
    }
    else
    {
        return 0;
    }
    
}

int priority(char ch){
    if (ch == '*' || ch == '/')
    {
        return 2;   // Kind of  * and / have more precedence than + or - ........ that's 
        //  this create because less precedence oparetor can't placed upper / above of more precedence operator in STACK
    }
    else if (ch == '-' || ch == '+')
    {
       return 1;
    }
    else{
        return 0;
    }
    
}

char * InfixToPostfix(char * infix){   //------------> in return i want a char type pointer of a charecter array or STRING
    struct stack * sp = (struct stack *)malloc(sizeof(struct stack));
    sp->size = 30;
    sp->top =-1;
    sp->arr =(char *)malloc(sp->size*sizeof(char));

    char* psotfix = (char*)malloc((strlen(infix) +1)*sizeof(char)); //-------------> ULTIMATE RETURN STRING POSTEFIX
    int i=0; // Track infix traversal
    int j = 0; // Track postfix addition 

    // creating postfix by travarse infix
    while (infix[i] !='\0')
    {
       if (!isOparetors(infix[i]))
       {
        psotfix[j] = infix[i];
        i++;
        j++;
       }
       else
       {
        if (priority(infix[i]) > priority(stackTop(sp)))
        {
           push(sp, infix[i]);      // precedence besi hole stack a push kora hok..
           i++;
        }
        else
        {
            // or else stack a thaka oparetor k postfix a lekaha hok..
            psotfix[j] = pop(sp);
            j++;
        }
        
       }
       
    }
    //  After that which operator left in stack those placed at LAST IN THAT POSTFIX string
    while (!isEmpty(sp))
    {
        psotfix[j]=pop(sp);
        j++;
    }

    psotfix[j] = '\0';
    return psotfix;
}

int main(){
    char * infix = "x-y/z-k*d";
    printf("\nThe Infix Expretion : ");
    puts(infix);
    printf("The Postfix Expretion : %s ", InfixToPostfix(infix));
    return 0;
}