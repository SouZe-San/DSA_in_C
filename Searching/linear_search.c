#include<stdio.h>

int main(){
    int arr[20];
    int n,serarch_ele,signel=0;
      int times_count = 0;

    printf("how many number you want to put?\n -->");
    scanf("%d",&n);
    // INPUT SECTION
    printf("Put numbers in array:\n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d",&arr[i]);
    }
    printf("Which number you want to search?\n");
    scanf("%d",&serarch_ele);
    // SEARCHING ALGO-----------

    for (int i = 0; i < n; i++)
    {
       if (arr[i] == serarch_ele)
       {
        signel=1;
        times_count = times_count +1;
       }
       
    }
    
    if (signel == 0)
    {
       printf("element not found, it doesn't exsit in Array");
    }
    else
    {
        printf("**Element found **.");
    }
    
    
    printf("\n --The search Element appera in array %d Times.--",times_count);
    
    
    return 0;
}