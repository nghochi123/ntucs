#include <bits/stdc++.h>

using namespace std;

int max(int a, int b)
{
    return a > b ? a : b;
}

int knapsack_dynamic(int w[], int p[], int cap, int n)
{
    int dp[n + 1][cap + 1];
    for (int i = 0; i <= cap; i++)
    {
        dp[0][i] = 0;
    }
    // i indicates ith item in consideration, j indicates considering a bag of
    // capacity j at the moment.
    // dp[i][j] indicates the consideration of i + 1 items assuming the bag has
    // capacity j.
    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j <= cap; j++)
        {
            if (w[i - 1] > j)
            {
                dp[i][j] = dp[i - 1][j];
                continue;
            }
            else
            {
                dp[i][j] = max(dp[i - 1][j], p[i - 1] + dp[i][j - w[i - 1]]);
            }
        }
    }
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= cap; j++)
        {
            cout << dp[i][j] << " ";
        }
        cout << endl;
    }
    return dp[n][cap];
}

int main()
{
    int n, cap;
    cout << "Enter number of items" << endl;
    cin >> n;
    cout << "Enter capacity of knapsack" << endl;
    cin >> cap;
    int p[n], w[n];

    for (int i = 0; i < n; i++)
    {
        cout << "Enter weight of item " << i << endl;
        cin >> w[i];
        cout << "Enter profit of item " << i << endl;
        cin >> p[i];
    }
    cout << "The most profit you can get from the knapsack is " << knapsack_dynamic(w, p, cap, n) << endl;
}