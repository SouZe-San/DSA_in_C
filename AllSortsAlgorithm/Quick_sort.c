#include <stdio.h>

void DisplayArray(int *A, int n)
{
    for (int i = 0; i < n; i++)
    {
        printf(" %d ", A[i]);
    }
    printf("\n");
}

// for Divite array into Two Array  Base on ONe PIVOT"S-Index and return That's index........
int Partition(int a[], int low, int high)
{
    int pivot = a[low]; //---> Based on this element In Left will be going all Lower Values and IN Right goes All Higher VAlue Than this pivot.......
    int i = low + 1;    // ------> Check Where geting learger/higher number
    int j = high;       //------> Check Where find the Lower the number
    int temp;
    do
    {
        while (pivot >= a[i]) //--> If it little or Equle ENTER in
        {
            i++; //----> Keep increasing i UNTILL we reach an element greater than the pivot (>=)
        }
        while (pivot < a[j]) //--> As we find lower value so condition will be opposit of that .. it Greater then ENTER in
        {
            j--; // -----> keep decreasing j UNTILL we reach an element smaller or equal to the pivot.(<)
        }
        // now Swap the element Between the I-th  and  J-th position
        if (i<j)
        {
            temp = a[i];
        a[i] = a[j];
        a[j] = temp;
        }
        
    } while (i < j); ///------> The loop will be run UNtilll the I & J cross each other......

    // After that When i & j Cross
    // Excange the position of jth eliment Which is Lower value than Pivot . and the pivot at low index..
    // And we return the Jth Index that will be the pivot's Index
    temp = a[low];
    a[low] = a[j];
    a[j] = temp;

    return j;
}

// QUICK SORT fUNCTOION ----------->

void QuickSort(int A[], int low, int high)
{
    int partitionIndex; // _---> index of Pivot After every PArtition

    if (low < high)
    {
        partitionIndex = Partition(A, low, high);
        QuickSort(A, partitionIndex + 1, high); // Sort The Right PArt
        QuickSort(A, low, partitionIndex - 1);  // Sort The Left PArt
    }
}
int main()
{
    int Arr[] = {5, 3, 4, 4, 23, 6, 87, 98, 35, 67};
    int n = 10;
    DisplayArray(Arr, n);
    QuickSort(Arr, 0, n - 1);
    DisplayArray(Arr, n);
    return 0;
}