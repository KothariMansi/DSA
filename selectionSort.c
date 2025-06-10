#include <stdio.h>

int main() {
    int arr[5] = {34, 634, 3, 64, 0};
    for (int i = 0; i < 5; i++)
    {
        int pos = i;
        for (int j = i; j < 5; j++)
        {
            if (arr[pos] > arr[j])
            {
                pos = j;
            }
        }
        int temp = arr[i];
        arr[i] = arr[pos]; 
        arr[pos] = temp;
    }

    for (int i = 0; i < 5; i++)
    {
        printf("%d ", arr[i]);
    }

    return 0;
}