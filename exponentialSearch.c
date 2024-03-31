#include <stdio.h>

int exponentialSearch(int arr[], int n, int x);
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

    int index = exponentialSearch(arr, n, x);
    if (index != -1) {
        printf("Element %d found at index %d\n", x, index);
    } else {
        printf("Element %d not found in the array\n", x);
    }
    
    return 0;
}

int exponentialSearch(int arr[], int n, int x) {
    if (arr[0] == x) {
        return 0;
    }

    int i = 1;
    while (i < n && arr[i] <= x) {
        i *= 2;
    }

    int end;
    if (i < n) {
        end = i;
    } else {
        end = n - 1;
    }
    return binarySearch(arr, i / 2, end, x);
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
    return -1; // Return -1 if element is not found
}
