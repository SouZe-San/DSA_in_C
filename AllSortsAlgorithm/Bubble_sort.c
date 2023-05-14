#include <stdio.h>
// If Want make fuction type make it void type

int main()
{
    int arr[10], n;
    printf("how many number you annt to put: ");
    scanf("%d",&n);
//INPUT SECTION
    printf("addd numbers ;-----");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
        // PRINTING THE UNSORTED ARRAY
     printf("\n UNSORTED ARRAY");
     for (int i = 0; i < n; i++)
    {
        printf(" %d ", arr[i]);
    }
// SOLTING ALGORIDAM 
    for (int j = 1; j < n; j++) // ------> INTERVEL TIME
    {
      for (int i = 0; i < n-j; i++)
      {
        if (arr[i]>arr[i+1])
        {
            int t = arr[i];
            arr[i] =arr[i+1];
            arr[i+1] = t;
        }        
      }  
    }
 // PRINTING THE SORTED ARRAY AFTER SOTING

    printf("\n SORTED ARRAY");
     for (int i = 0; i < n; i++)
    {
        printf("%d  ", arr[i]);
    }
    

    return 0;
}