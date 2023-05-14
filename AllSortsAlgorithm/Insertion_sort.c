#include <stdio.h>

int main()
{
    int arr[10], n;
    printf("how many number you annt to put: ");
    scanf("%d", &n);

    // INPUT SECTION
    printf("addd numbers ;-----");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    // PRINTING THE UNSORTED ARRAY---------------------
    printf("\n UNSORTED ARRAY: ");
    for (int i = 0; i < n; i++)
    {
        printf(" %d ", arr[i]);
    }

    // SOLTING ALGORIDAM
    for (int i = 1; i < n; i++)
    {
        int key = arr[i],j;
        for (j = i - 1; j >= 0 && arr[j] > key; j--) // if previous number is bigger then enter the loop
        {
            arr[j + 1] = arr[j];
        }
        arr[j + 1] = key;
    }

    // PRINTING SORTED ARRAY THE AFTER SOTING----------------------
    printf("\n SORTED ARRAY: ");
    for (int i = 0; i < n; i++)
    {
        printf(" %d ", arr[i]);
    }

    return 0;
}