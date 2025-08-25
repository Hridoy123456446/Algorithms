#include <stdio.h>
int max(int a, int b) {
    if (a > b)
    return a;
else
    return b;
}
int rodCutting(int price[], int n) {
    int dp[n+1];
    dp[0] = 0;

    for (int i = 1; i <= n; i++) {
        dp[i] = 0;
        for (int j = 1; j <= i; j++) {
            dp[i] = max(dp[i], price[j] + dp[i - j]);
        }
    }
    return dp[n];
}
int main() {
    int rod_length;

    printf("Enter the length of the rod: ");
    scanf("%d", &rod_length);

    int price[rod_length + 1];

    printf("Enter prices for each length: ");
    for (int i = 1; i <= rod_length; i++) {
        scanf("%d", &price[i]);
    }

    int max_profit = rodCutting(price, rod_length);
    printf("\nMaximum Profit for rod length %d is: %d\n", rod_length, max_profit);

    return 0;
}
