#include <stdio.h>
#include <string.h>

// Recursive function to find LCS length
int lcs(char *X, char *Y, int m, int n)
{
    if (m == 0 || n == 0)
        return 0;
    if (X[m - 1] == Y[n - 1])
        return 1 + lcs(X, Y, m - 1, n - 1);
    else
    {
        int left = lcs(X, Y, m - 1, n);
        int right = lcs(X, Y, m, n - 1);
        if (left > right)
            return left;
        else
            return right;

    }
}

int main()
{
    char X[100], Y[100];
    printf("Enter first string: ");
    scanf("%s", X);
    printf("Enter second string: ");
    scanf("%s", Y);

    int m = strlen(X);
    int n = strlen(Y);

    int length = lcs(X, Y, m, n);

    printf("\nLength of Longest Common Subsequence: %d\n", length);

    return 0;
}
