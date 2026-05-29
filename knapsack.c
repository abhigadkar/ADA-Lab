#include <stdio.h>

// Function to find maximum
int max(int a, int b) {
    return (a > b) ? a : b;
}

int main() {

    int n, W;

    printf("Enter number of items: ");
    scanf("%d", &n);

    int weight[n], profit[n];

    // Input items
    for(int i = 0; i < n; i++) {
        printf("Enter weight and profit of item %d: ", i + 1);
        scanf("%d %d", &weight[i], &profit[i]);
    }

    printf("Enter knapsack capacity: ");
    scanf("%d", &W);

    // DP table
    int dp[n + 1][W + 1];

    // Initialize first row and column
    for(int i = 0; i <= n; i++) {
        for(int w = 0; w <= W; w++) {

            if(i == 0 || w == 0)
                dp[i][w] = 0;

            else if(weight[i - 1] <= w) {

                dp[i][w] = max(
                    profit[i - 1] + dp[i - 1][w - weight[i - 1]],
                    dp[i - 1][w]
                );
            }

            else {
                dp[i][w] = dp[i - 1][w];
            }
        }
    }

    // Print Profit Table
    printf("\nProfit Table:\n\n");

    for(int i = 0; i <= n; i++) {

        for(int w = 0; w <= W; w++) {
            printf("%4d", dp[i][w]);
        }

        printf("\n");
    }

    // Final Maximum Profit
    printf("\nMaximum Profit = %d\n", dp[n][W]);

    return 0;
}
