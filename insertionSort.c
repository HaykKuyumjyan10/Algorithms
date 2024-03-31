#include <stdio.h>

void insertionSort(int arr[], int n);

int main() {
    int arr[] = {14, 23, 9, 5, 10, 8};
    int n = sizeof(arr) / sizeof(arr[0]);
    insertionSort(arr, n);
    
    for (int i = 0; i < n; i++) {
        printf("%d \n", arr[i]);
    }

    return 0;
}

void insertionSort(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;
        
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}
