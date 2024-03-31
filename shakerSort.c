
#include <stdio.h>

int main() {
    int arr[] = {14, 54, 23, 13, -9, -3, 12, -17, 0};
    int n = 9;
    
    int l = 0;
    int r = n - 1;
    int swap = 1;
    
    while (l < r && swap) {
        swap = 0;
        
        for (int i = l; i < r; i++) {
            if (arr[i] > arr[i + 1]) 
            {
                int temp = arr[i];
                arr[i] = arr[i + 1];
                arr[i + 1] = temp;
                swap = 1;
            }
        }
        r--;
        
        for (int i = r; i > l; i--) {
            if (arr[i] < arr[i - 1]) 
            {
                int temp = arr[i];
                arr[i] = arr[i - 1];
                arr[i - 1] = temp;
                swap = 1;
            }
        }
        l++;
    }
    
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    
    return 0;
}

