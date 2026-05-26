#include <stdio.h>

void sort(int arr[], int n) {
    for(int i = 0; i < n - 1; i++) {
        for(int j = i + 1; j < n; j++) {
            if(arr[i] > arr[j]) {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}

int removeMedian(int arr[], int *n) {
    sort(arr, *n);

    int mid = (*n - 1) / 2;
    int median = arr[mid];

    for(int i = mid; i < *n - 1; i++) {
        arr[i] = arr[i + 1];
    }

    (*n)--;
    return median;
}

int main() {
    int arr[1000], n = 0, x;

    while(1) {
        scanf("%d", &x);

        if(x == 0) break;

        if(x == -1) {
            if(n > 0) {
                printf("%d ", removeMedian(arr, &n));
            }
        } else {
            arr[n++] = x;
        }
    }

    return 0;
}
