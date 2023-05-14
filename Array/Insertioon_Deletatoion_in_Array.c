// [[[[[[[[[[[[[[[[[[[[[[[[[[[ --------- INSERTION AND DELETON IN ARRAY ---------  ]]]]]]]]]]]]]]]]]]]]]]]]]]]
 
#include<stdio.h>

// DISPALAY FUNCTION ------------------------------------------
void Display(int a[], int s){
for (int i = 0; i < s; i++)
{
   printf(" %d " ,a[i]);
}
}

// INSERTION IN AN ARRAY --------------------------------------------
int InsertionInArray (int a[], int s, int capacity,int i, int ele ){
   if (s >= capacity)
   {
    printf("insertion can't be Done Due to Lack Of Space");
    return -1;
   }
for (int j = s-1; j >= i; j--)
{
   a[j+1]=a[j];
}
a[i]=ele; 
return 1;
}

// DELETATION IN ARRAY ---------------------------------
void Deletation(int a[],int index,int sizeOfArray){
   for (int i = index; i < sizeOfArray; i++)
   {
      a[i] = a[i+1];
   }
   
}

int main(){
    int array[50],size;
    int index,element;
printf("How many number you want to put : ");
scanf("%d",&size);
printf("Now pls put numbers In Array\n");
for (int i = 0; i < size; i++)
{
   printf("Element no.%d  ",i+1);
   scanf("%d",&array[i]);
}

Display(array,size);

printf("\nAt what index you Want to Insret: ");
scanf("%d",&index);
printf("At That indexa What number you Want to Insret: ");
scanf("%d",&element);
printf("\n");
InsertionInArray(array,size,50,index,element);
size += 1;
Display(array,size);
int indexOfDeleteElement;
printf("\nAt What index's element you want to delete: ");
scanf("%d",&indexOfDeleteElement);
Deletation(array,indexOfDeleteElement,size);
size-=1;
Display(array,size);
    return 0;
}