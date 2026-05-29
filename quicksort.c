
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Swap function
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Partition using first element as pivot
int partition(int arr[], int low, int high) {
    int pivot = arr[low];
    int i = low + 1;
    int j = high;

    while (1) {
        // Move i right while elements are <= pivot
        while (i <= high && arr[i] <= pivot)
            i++;

        // Move j left while elements are > pivot
        while (arr[j] > pivot)
            j--;

        if (i < j)
            swap(&arr[i], &arr[j]);
        else
            break;
    }

    // Place pivot at correct position
    swap(&arr[low], &arr[j]);
    return j;
}

// Quick Sort
void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

int main() {
    int n;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    // Dynamic memory allocation
    int *arr = (int *)malloc(n * sizeof(int));

    if (arr == NULL) {
        printf("Memory allocation failed!\n");
        return 1;
    }

    // Seed random numbers
    srand(time(NULL));

    // Fill array
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % 100000;
    }

    // Time calculation
    clock_t start, end;
    start = clock();

    quickSort(arr, 0, n - 1);

    end = clock();

    double time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;

    printf("Time taken to sort %d elements: %f seconds\n", n, time_taken);

    free(arr);
    return 0;
}
