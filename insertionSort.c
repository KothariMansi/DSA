#include <stdio.h>


int main() {
    int arr[5] = {34, 634, 3, 64, 0};
    for (int i = 1; i < 5; i++)
    {
        int t = arr[i];
        for (int j = i - 1;j >= 0; j--)
        {
            if (arr[j] > t)
            {
                arr[j+1] = arr[j];
                arr[j] = t;
            } else break; 
        } 
    }

    for (int i = 0; i < 5; i++)
    {
        printf("%d ", arr[i]);
    }

    return 0;
}