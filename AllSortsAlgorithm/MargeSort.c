#include<stdio.h>

void DisplayArray(int *A, int n)
{
    for (int i = 0; i < n; i++)
    {
        printf(" %d ", A[i]);
    }
    printf("\n");
}

// Algorithm for marge two Sorted array in another array,
void arrayMarge(int A[],int low, int mid, int high){
    int i = low,
     j= mid+1, 
     k=low,B[50];
    while (i<=mid && j<= high)
    {
        if (A[i]<A[j])
        {
            B[k] = A[i];
            i++;
            k++;
        }
        else
        {
           B[k]=A[j];
           j++;
           k++;
        }
        
    }
    // If In ANy Array have remain Any Element then Those copy in B Array as they are.
    while (i<=mid)
    {
        B[k] = A[i];
        i++;
        k++;
    }
    while (j<=high)
    {
        B[k] = A[j];
        j++;
        k++;
    }
//  Now then All element in B Copy in A As they are...
for (int i = low; i <= high; i++)
{
    A[i]=B[i];
}

}

// ALGORITHM FOR BREAK THE ARRAY AS MAUCH, THAT AT LAST THEY HAVE ONE ELEMENT IN ONE ARRAY WITH ONE INDEX..... AND THEN MARGE THEM..

void margeSort(int A[], int low , int high){
    int mid;
    if (low<high)
    {
        mid = (low + high)/2;
        margeSort(A,low,mid);
        margeSort(A,mid+1,high);
        arrayMarge(A,low,mid,high);
    }
    
}
int main(){
    int Arr[] = {4,45,23,56,75,97,456,3,32,13,6};
    int n = 11;
    DisplayArray(Arr,n);
    margeSort(Arr,0,n-1);
    DisplayArray(Arr,n);
    return 0;
}