//   ----------- ARRAY AS ADTs AND SOME OPERATION --------------

#include <stdio.h>
#include <stdlib.h>

struct Array         //---------- CREATING A DYNAMIC ARRAY :---
{
    int reserved_memory;
    int fill_memory;
    int *ptr;
};

void MemoryAlocation(struct Array*a, int f_memory, int r_memory)
{
    (*a).fill_memory = f_memory;
    a->reserved_memory = r_memory;
    a->ptr = (int *)malloc(r_memory * sizeof(int));
}

void GetElement(struct Array*a){
    // int num;
    for (int i = 0; i < a->fill_memory; i++)
    {
      printf("PLs Enter The number %d: ",i);
    //   (a->ptr)[i]=num;
        scanf("%d",&(a->ptr)[i]);

    }    
}

void display(struct Array*a){
    for (int i = 0; i < a->fill_memory; i++)
    {
       printf("[%d] ", ((*a).ptr)[i]);
    }  
}

int main()
{
    struct Array balanse;
    MemoryAlocation(&balanse,5,10);
    GetElement(&balanse);
    display(&balanse);
    // free(MemoryAlocation);
    // free(&balanse);
    
    return 0;
}