#include <stdio.h>

int main()
{
    int arr[20], max_value, maxIndex, n;
    printf("how many number you annt to put: ");
    scanf("%d", &n);

    // INPUT SECTION
    printf("addd numbers ;-----");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    // PRITNG THE UNSORTED ARRAY
    printf("\n UNSORTED ARRAY: ");
    for (int i = 0; i < n; i++)
    {
        printf(" %d ", arr[i]);
    }

    // SELECTON ALGO --

    for (int i = 0; i < n; i++)
    {
        max_value = arr[i];
        maxIndex = i;
        for (int j = i + 1; j < n; j++)
        {
            if (max_value < arr[j])
            {
                max_value = arr[j];
                maxIndex = j;
            }
        }
        int swap = arr[i];
        arr[i] = arr[maxIndex];
        arr[maxIndex] = swap;
    }

    // PRINTING THE SORTED ARRAY  AFTER SOTING
    printf("\n SORTED ARRAY: ");
    for (int i = 0; i < n; i++)
    {
        printf(" %d ", arr[i]);
    }
    printf("the max element is : %d", arr[0]);
    return 0;
}