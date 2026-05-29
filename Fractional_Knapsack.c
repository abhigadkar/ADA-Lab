#include <stdio.h>

struct Item {
    int profit;
    int weight;
    float ratio;
};

void sort(struct Item item[], int n) {
    int i, j;
    struct Item temp;

    for(i = 0; i < n - 1; i++) {
        for(j = 0; j < n - i - 1; j++) {
            if(item[j].ratio < item[j + 1].ratio) {
                temp = item[j];
                item[j] = item[j + 1];
                item[j + 1] = temp;
            }
        }
    }
}

int main() {
    int n, i;
    float capacity, totalProfit = 0;

    printf("Enter number of items: ");
    scanf("%d", &n);

    struct Item item[n];

    printf("Enter profit and weight of each item:\n");

    for(i = 0; i < n; i++) {
        scanf("%d%d", &item[i].profit, &item[i].weight);

        item[i].ratio =
            (float)item[i].profit / item[i].weight;
    }

    printf("Enter knapsack capacity: ");
    scanf("%f", &capacity);

    // Sort according to ratio
    sort(item, n);

    printf("\nSelected items:\n");

    for(i = 0; i < n; i++) {

        if(item[i].weight <= capacity) {

            printf("Item with profit %d and weight %d selected fully\n",
                   item[i].profit,
                   item[i].weight);

            capacity -= item[i].weight;
            totalProfit += item[i].profit;
        }
        else {

            float fraction = capacity / item[i].weight;

            printf("Item with profit %d and weight %d selected %.2f fraction\n",
                   item[i].profit,
                   item[i].weight,
                   fraction);

            totalProfit += item[i].profit * fraction;

            break;
        }
    }

    printf("\nMaximum Profit = %.2f\n", totalProfit);

    return 0;
}
