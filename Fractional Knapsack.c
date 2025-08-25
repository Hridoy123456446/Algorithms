#include <stdio.h>

typedef struct {
    int weight;
    int value;
    double ratio;
} Item;

// Function to swap two items
void swap(Item* a, Item* b) {
    Item temp = *a;
    *a = *b;
    *b = temp;
}

// Sort items by ratio in descending order using bubble sort
void sortItems(Item arr[], int n) {
    for (int i = 0; i < n-1; i++) {
        for (int j = 0; j < n-i-1; j++) {
            if (arr[j].ratio < arr[j+1].ratio) {
                swap(&arr[j], &arr[j+1]);
            }
        }
    }
}

// Fractional Knapsack function
double fractionalKnapsack(int W, Item arr[], int n) {
    sortItems(arr, n);
    double totalValue = 0.0;
    int remainingCapacity = W;

    for (int i = 0; i < n; i++) {
        if (arr[i].weight <= remainingCapacity) {
            totalValue += arr[i].value;
            remainingCapacity -= arr[i].weight;
        } else {
            double fraction = (double)remainingCapacity / arr[i].weight;
            totalValue += arr[i].value * fraction;
            break;  // Knapsack is full
        }
    }

    return totalValue;
}

int main() {
    int n, W;
    printf("Enter number of items: ");
    scanf("%d", &n);

    Item arr[n];

    printf("Enter values of items: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i].value);
    }

    printf("Enter weights of items: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i].weight);
        arr[i].ratio = (double)arr[i].value / arr[i].weight;
    }

    printf("Enter knapsack capacity: ");
    scanf("%d", &W);

    double maxValue = fractionalKnapsack(W, arr, n);
    printf("\nMaximum value in Knapsack = %.2lf\n", maxValue);

    return 0;
}

