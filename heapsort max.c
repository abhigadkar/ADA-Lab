#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct Node {
    int data;
    struct Node* left;
    struct Node* right;
} Node;

Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

Node* buildTree(int arr[], int i, int n) {
    if (i >= n) return NULL;

    Node* root = createNode(arr[i]);
    root->left = buildTree(arr, 2*i + 1, n);
    root->right = buildTree(arr, 2*i + 2, n);

    return root;
}

void heapify(Node* root) {
    if (root == NULL) return;

    Node* largest = root;

    if (root->left && root->left->data > largest->data)
        largest = root->left;

    if (root->right && root->right->data > largest->data)
        largest = root->right;

    if (largest != root) {
        int temp = root->data;
        root->data = largest->data;
        largest->data = temp;

        heapify(largest);
    }
}

void buildMaxHeap(Node* root) {
    if (root == NULL) return;

    buildMaxHeap(root->left);
    buildMaxHeap(root->right);
    heapify(root);
}

int countNodes(Node* root) {
    if (!root) return 0;
    return 1 + countNodes(root->left) + countNodes(root->right);
}


void heapSortTree(Node* root, int arr[], int n) {
    for (int i = n - 1; i >= 0; i--) {
        buildMaxHeap(root);

        arr[i] = root->data;

        Node* temp = root;
        Node* parent = NULL;
        Node* last = root;

        Node* queue[1000];
        int front = 0, rear = 0;
        queue[rear++] = root;

        while (front < rear) {
            last = queue[front++];
            if (last->left) {
                parent = last;
                queue[rear++] = last->left;
            }
            if (last->right) {
                parent = last;
                queue[rear++] = last->right;
            }
        }

        root->data = last->data;

        if (parent) {
            if (parent->right == last)
                parent->right = NULL;
            else
                parent->left = NULL;
        }
        free(last);
    }
}

int main() {
    int n;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    int arr[n];

    printf("Enter elements:\n");
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    Node* root = buildTree(arr, 0, n);

    clock_t start = clock();

    heapSortTree(root, arr, n);

    clock_t end = clock();

    printf("Sorted array:\n");
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);

    double time_taken = (double)(end - start) / CLOCKS_PER_SEC;
    printf("\nTime taken: %f seconds\n", time_taken);

    return 0;
}
