#include <stdio.h>
#include <stdlib.h>

// Function to print permutation
void printPermutation(int *perm, int n) {
    for (int i = 0; i < n; i++)
        printf("%d ", perm[i]);
    printf("\n");
}

// Find largest mobile element
int getMobile(int *perm, int *dir, int n) {
    int mobile = 0, mobileIndex = -1;

    for (int i = 0; i < n; i++) {
        int nextIndex = i + dir[perm[i] - 1];

        if (nextIndex >= 0 && nextIndex < n) {
            if (perm[i] > perm[nextIndex] && perm[i] > mobile) {
                mobile = perm[i];
                mobileIndex = i;
            }
        }
    }
    return mobile;
}

// Find index of a given value
int findIndex(int *perm, int n, int value) {
    for (int i = 0; i < n; i++) {
        if (perm[i] == value)
            return i;
    }
    return -1;
}

void generatePermutations(int n) {
    int *perm = (int*)malloc(n * sizeof(int));
    int *dir = (int*)malloc(n * sizeof(int));

    // Initialize permutation and directions
    for (int i = 0; i < n; i++) {
        perm[i] = i + 1;
        dir[i] = -1; // all pointing left initially
    }
    printPermutation(perm, n);

    while (1) {
        int mobile = getMobile(perm, dir, n);

        if (mobile == 0)
            break;

        int pos = findIndex(perm, n, mobile);
        int swapWith = pos + dir[mobile - 1];

        // Swap
        int temp = perm[pos];
        perm[pos] = perm[swapWith];
        perm[swapWith] = temp;

        // Update position
        pos = swapWith;

        // Reverse directions of all elements greater than mobile
        for (int i = 0; i < n; i++) {
            if (perm[i] > mobile) {
                dir[perm[i] - 1] *= -1;
            }
        }

        printPermutation(perm, n);
    }

    free(perm);
    free(dir);
}

int main() {
    int n;
    printf("Enter the number to find Permutaion = ");
    scanf("%d",&n);
    generatePermutations(n);
    return 0;
}
