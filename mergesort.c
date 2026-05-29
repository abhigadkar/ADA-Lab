#include <stdio.h>
#include <stdlib.h>
#include <time.h>
void merge(int arr[], int left, int mid, int right)
{
    int i = left, j = mid + 1, k = 0;
    int size = right - left + 1;

    int *temp = (int *)malloc(size * sizeof(int));

    while (i <= mid && j <= right)
    {
        if (arr[i] <= arr[j])
            temp[k++] = arr[i++];
        else
            temp[k++] = arr[j++];
    }

    while (i <= mid)
        temp[k++] = arr[i++];

    while (j <= right)
        temp[k++] = arr[j++];

    for (i = left, k = 0; i <= right; i++, k++)
        arr[i] = temp[k];

    free(temp);
}
void mergeSort(int arr[], int left, int right)
{
    if (left < right)
    {
        int mid = (left + right) / 2;

        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);

        merge(arr, left, mid, right);
    }
}

int main()
{
    int n;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    int *arr = (int *)malloc(n * sizeof(int));

    srand(time(NULL));

    for (int i = 0; i < n; i++)
        arr[i] = rand() % 100000000;

    clock_t start, end;

    start = clock();

    mergeSort(arr, 0, n - 1);

    end = clock();

    double time_taken = (double)(end - start) / CLOCKS_PER_SEC;

    printf("Time taken to sort %d elements: %f seconds\n", n, time_taken);

    free(arr);

    return 0;
}
