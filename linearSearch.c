#include <stdio.h>

int linearSearch(int arr[], int n, int x);

int main() {
    int n;
    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter %d elements: ", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    int x;
    printf("Enter the number you want to find: ");
    scanf("%d", &x);

    int index = linearSearch(arr, n, x);
    if (index != -1) {
        printf("Element %d found at index %d\n", x, index);
    } else {
        printf("Element %d not found in the array\n", x);
    }
   
    return 0;
}

int linearSearch(int arr[], int n, int x) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == x) {
            return i; 
        }
    }
    return -1; // If element is not found
}
