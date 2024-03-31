#include <stdio.h>

int binarySearch(int arr[], int low, int high, int x);

int main() {
    int n;
    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter %d elements in sorted order: ", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    int x;
    printf("Enter the number you want to find: ");
    scanf("%d", &x);

    int index = binarySearch(arr, 0, n - 1, x);
    if (index != -1) {
        printf("Element %d found at index %d\n", x, index);
    } else {
        printf("Element %d not found in the array\n", x);
    }
    
    return 0;
}

int binarySearch(int arr[], int low, int high, int x) {
    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (arr[mid] == x) {
            return mid;
        }
        else if (arr[mid] < x) {
            low = mid + 1;
        }
        else {
            high = mid - 1;
        }
    }
    return -1; // Element not found
}
