#include <stdio.h>

int main() {
    int arr[5] = {34, 634, 3, 64, 0};
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 4 - i; j++)
        {
            if (arr[j] > arr[j+1])
            {
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
    
    for (int i = 0; i < 5; i++)
    {
        printf("%d ", arr[i]);
    }
    
    return 0;
}