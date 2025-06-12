#include <stdio.h>
#include <stdlib.h>

typedef struct heap
{
    int arr[100];
    int index;
} MinHeap; 

void create(MinHeap *minHeap) {
    minHeap->index = 1;
}

void upHeap(MinHeap *minHeap, int parent, int child) {
    if (child == 1)
    {
        return;
    }
    if  (minHeap->arr[child] < minHeap->arr[parent])
    {
        int temp = minHeap->arr[child];
        minHeap->arr[child] = minHeap->arr[parent];
        minHeap->arr[parent] = temp;
        upHeap(minHeap, parent/2, parent);
    } else {
        return;
    }
}

void insert(MinHeap *minHeap, int val) {
    minHeap->arr[minHeap->index] = val;
    int i = minHeap->index;
    int pi = (minHeap->index) / 2;
    
    upHeap(minHeap, pi, i);
    minHeap->index++;
}

void downHeap(MinHeap *minHeap, int i) {
    int left = i*2;
    int right = i*2+1;
    int smallest = i;
    if (i == minHeap->index-1)
    {
        return;
    }
    if (left < minHeap->index && minHeap->arr[smallest] > minHeap->arr[left])
    {
        int temp = minHeap->arr[smallest];
        minHeap->arr[smallest] = minHeap->arr[left];
        minHeap->arr[left] = temp;
        downHeap(minHeap, left);
    } if (right < minHeap->index && minHeap->arr[smallest] > minHeap->arr[right])
    {
        int temp = minHeap->arr[i];
        minHeap->arr[smallest] = minHeap->arr[right];
        minHeap->arr[right] = temp;
        downHeap(minHeap, right);
    }
}

int removeElement(MinHeap *minHeap) {
    if (minHeap->index < 1)
    {
        printf("\nList is empty");
        return -1;
    }
    int root = minHeap->arr[1];
    minHeap->arr[1] = minHeap->arr[minHeap->index-1];
    minHeap->index--;
    downHeap(minHeap, 1); 
    return root;  
}

void display(MinHeap *minHeap) {
    for (int i = 1; i < minHeap->index; i++)
    {
        printf("%d ", minHeap->arr[i]);
    }
    printf("\n");
}

void heapSort(MinHeap *minHeap) {
    while(minHeap->index > 1)
    {
        int removedElement = removeElement(minHeap);
        printf("%d ", removedElement);
    }
    printf("\n");
}

int main() {
    MinHeap *minHeap = malloc(sizeof(MinHeap));
    if (minHeap == NULL) {
        printf("Memory allocation failed\n");
        return 1;
    }
    create(minHeap);
    insert(minHeap, 2);
    insert(minHeap, 10);
    insert(minHeap, 12);
    insert(minHeap, 3);
    insert(minHeap, 9);
    insert(minHeap, 11);
    display(minHeap);
    heapSort(minHeap);
    
    return 0;
}