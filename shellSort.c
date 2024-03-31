#include <stdio.h>

void shellsort(int arr[], int n);

int main() {
    int arr[] = {14, 54, 23, 13, -9, -3, 12, -17, 0};
    int n = 9;
    shellsort(arr, n);
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}

void shellsort(int arr[], int n) {
    int gap, i, j, temp;
    for (gap = n / 2; gap > 0; gap /= 2) {
        for (i = gap; i < n; i++) {
            temp = arr[i];
            for (j = i; j >= gap && arr[j - gap] > temp; j -= gap) {
                arr[j] = arr[j - gap];
            }
            arr[j] = temp;
        }
    }
}
