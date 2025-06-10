#include <stdio.h>

int main() {
    int arr[5] = {434, 53, 67, 3, 0};
    int temp;
    for (int i = 0; i < 5; i++) {
        for (int j = i; j < 5; j++)
        {
            if (arr[i] > arr[j])
            {
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
            
            temp = arr[i];
        }  
    }
    for (int  i = 0; i < 5; i++)
    {
        printf("%d ", arr[i]);
    }

    return 0;
}