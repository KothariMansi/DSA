#include <stdio.h>

void mergeSort(int arr[], int low, int high);
void merge(int arr[], int low, int mid, int high);

int main() {
    int arr[] = {23, 90, 17, 66, 8, 92, 90};
    mergeSort(arr, 0, 6);
   
    for (int i = 0; i < 7; i++)
    {
        printf("%d ", arr[i]);
    }

    return 0;
}

void mergeSort(int arr[], int low, int high) {
    if (low == high)
    {
        return;
    }
    
    int mid = (high + low) / 2;
    mergeSort(arr, low, mid);
    mergeSort(arr, mid+1, high);
    merge(arr, low, mid, high);
}

void merge(int arr[], int low, int mid, int high) {
    int temp[high];
    int i = low;
    int left = low;
    int right = mid+1;
    while (left <= mid && right <= high)
    {
        if (arr[left] < arr[right])
        {
            temp[i] = arr[left];
            left++;
        } else{
            temp[i] = arr[right];
            right++;
        }
        i++;
    }
    while (left <= mid )
    {
        temp[i] = arr[left];
        left++;
        i++;
    }
    while (right <= high)
    {
        temp[i] = arr[right];
        right++;
        i++;
    }
    for (i = low; i <= high; i++)
    {
        arr[i] = temp[i];
    }
}