// [[[[[[[[[[[[[[[[[[[[  APPLICATION OF STACK ]]]]]]]]]]]]]]]]]]]]

#include <stdio.h>
#include <stdlib.h>

struct stack
{
    int top;
    int size;
    char *arr;
};

int isEmpty(struct stack *ptr)
{
    if (ptr->top == -1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int isFull(struct stack *ptr)
{
    if (ptr->top == ptr->size - 1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void push(struct stack *ptr, char ch)
{
    if (isFull)
    {
        printf("Cant Possible!!!!! Stack Overflow;;;;");
    }
    else
    {
        ptr->top++;
        ptr->arr[ptr->top] = ch;
    }
}

char pop(struct stack *ptr)
{
    if (isEmpty)
    {
        printf("UnderFlow!!!!!!!!!!@#&&$*^(*$!!!!!!!!!!!");
        return -1;
    }
    else
    {
        char val = ptr->arr[ptr->top];
        ptr->top--;
        return val;
    }
}

int parenthesisMAchmaker(char *string)
{
    // Create and Named A stack
    struct stack *sp;
    sp->size = 20;
    sp->top = -1;
    sp->arr = (char *)malloc(sp->size * sizeof(char));

    for (int i = 0; string[i] != '\0'; i++)
    {
        if (string[i] == '(')
        {
            push(sp, '(');
        }
        else if (string[i] == ')')
        {
            if (isEmpty)
            {
                return 0;
            }
                pop(sp);
        }
    }

    if (isEmpty)
    {
        return 1;
    }
    else
    {
       return 0;
    }
    
}

int main()
{
    char * exp ="32*(949+94)-(4/3)";

    if (parenthesisMAchmaker(exp))
    {
        printf("The parenthesis is matching");
    }
    else
    {
        printf("The parenthesis is not matching");
    }
    return 0;
}