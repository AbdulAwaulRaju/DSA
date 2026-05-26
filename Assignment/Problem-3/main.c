#include <stdio.h>

struct Activity {
    int start;
    int finish;
};

void sort(struct Activity arr[], int n) {
    for(int i = 0; i < n - 1; i++) {
        for(int j = i + 1; j < n; j++) {
            if(arr[i].finish > arr[j].finish) {
                struct Activity temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}

void activitySelection(struct Activity arr[], int n) {
    sort(arr, n);

    int last = 0;

    printf("(%d,%d) ", arr[0].start, arr[0].finish);

    for(int i = 1; i < n; i++) {
        if(arr[i].start >= arr[last].finish) {
            printf("(%d,%d) ", arr[i].start, arr[i].finish);
            last = i;
        }
    }
}

int main() {
    struct Activity arr[6];

    for(int i = 0; i < 6; i++) {
        scanf("%d %d", &arr[i].start, &arr[i].finish);
    }

    activitySelection(arr, 6);

    return 0;
}
