#include <stdio.h>
#include <limits.h>
#include<stdlib.h>
void DisplayArray(int *A, int n)
{
    for (int i = 0; i < n; i++)
    {
        printf(" %d ", A[i]);
    }
    printf("\n");
}

//  Function for Find A Maximum Element in A Array.......
int maximum(int A[], int n)
{
    int maxInArray = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        if (A[i] > maxInArray)
        {
            maxInArray = A[i];
        }
    }
    return maxInArray;
}

void countSort(int A[], int n)
{
    int max = maximum(A, n);
    int i, j;
    // Memory Allocation in hip..... that will use to identifi the element in array in order by index..............size will be Equal with the MAX element OF The unsorted Array...
    int* countArray = (int *)malloc((max + 1) * sizeof(int));

    // next fill this Array with only 0(Zero)
    for (i = 0; i < max + 1; i++)
    {
        countArray[i] = 0;
    }
    // / Increment the corresponding index in the countarray
    // --->Unsorted Array te jei number thakbe sei Countarraay er sei index a '+1' kora hobe

    for (j = 0; j < n; j++)// MAIN array's Element is index of this Array amd they increment by 1;
    {
        countArray[A[j]] = countArray[A[j]] + 1; 
    }

    // Now will be cheaking in which index of array containte nonZero .... those index number will reprasent the number that in in previous Array...... no and now those are will bw e sorted ..........
    i = 0; //-----------> That will index for countArray
    j = 0; //--------------> that will for that MAIN Array's index

    while (i <= max) // loop run through the full countArray
    {
        if (countArray[i] > 0) // ------> if ffound non zero that mean in that index number present in MAin ARRAy for pass that number in main Array... and decreament by 1
        {
            A[j] = i;
            countArray[i] = countArray[i] - 1;
            j++;
            i++;
        }
        else
        {
            i++;
        }
    }
}


int main()
{
    int Arr[] = {4, 45, 23, 56, 75, 0, 456, 3, 32, 13, 6};
    int n = 11;
    DisplayArray(Arr, n);
    countSort(Arr,n);
    DisplayArray(Arr, n);
    return 0;
}