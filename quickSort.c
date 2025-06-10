#include <stdio.h>

void quickSort(int arr[],int low, int high) {
    if (low >= high) {
        return;
    }
    int pivot = arr[low];
    int i = low, j = high; 
    while (i < j)
    {
        while (arr[i] <= pivot && i<=high-1) { i++; }
        while (arr[j] > pivot && j>=low+1) { j--; }
        if (i < j)
        {
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }
    int temp = arr[low];
    arr[low] = arr[j];
    arr[j] = temp;
    quickSort(arr, low, j-1);
    quickSort(arr, j+1, high);
}

int main() {

    int arr[] = {23, 90, 17, 66, 8, 92, 90};
    quickSort(arr, 0, 6);
    for (int i = 0; i < 7; i++)
    {
        printf("%d ", arr[i]);
    }
    return 0;
}