#include <stdio.h>
#define SIZE 8

// Like Insertion Sort
void shellSort(int *arr, int gap) {
    for (int i = 0; i < SIZE; i+=gap)
    {
        int t = arr[i];
        for (int j = i - gap;j >= 0; j-=gap)
        {
            if (arr[j] > t)
            {
                arr[j+gap] = arr[j];
                arr[j] = t;
            } else break; 
        } 
    }
    if (gap != 1)
    {
        shellSort(arr, gap/2);
    }
    return;
}

int main() {
    int arr[SIZE] = {14, 19, 27, 10, 35, 33, 42, 44};
    int gap = SIZE/2;
    shellSort(arr, gap);

    for (int i = 0; i < SIZE; i++)
    {
        printf("%d ", arr[i]);
    }

    return 0;
}