#include <stdio.h>

int a[10], top=0;

void Printsa()
{
    for (int i = 0; i <top; i++)
    {
        printf(" %d ", a[i]);
    }
}

void Insertion(int value)
{

    if (top == 10)
    {
        printf("Stack Overflow!");
    }
    else
    {
        a[top] = value;
        top++;
    }
}

int deletation()
{ 
    top--;
    int val = a[top];
    return val;
}
int main()
{
    // struct stack s;
    Insertion(5);
    Insertion(15);
    Insertion(25);
    Insertion(35);
    Printsa();
    printf("\nDeleted value is :%d\n-->", deletation());
    Printsa();
    return 0;
}