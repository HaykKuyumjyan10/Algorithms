#include <stdio.h>

int interpolationSearch(int arr[], int n, int x);

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

    int index = interpolationSearch(arr, n, x);
    if (index != -1) {
        printf("Element %d found at index %d\n", x, index);
    } else {
        printf("Element %d not found in the array\n", x);
    }
    
    return 0;
}

int interpolationSearch(int arr[], int n, int x) {
    int l = 0;
    int h = n - 1;

    while (l <= h && x >= arr[l] && x <= arr[h]) {
        int j = l + ((double)(h - l) / (arr[h] - arr[l])) * (x - arr[l]);

        if (arr[j] == x) {
            return j;
        }
        if (arr[j] > x) {
            h = j - 1;
        }
        else {
            l = j + 1;
        }
    }
    return -1; // If element is not found
}
