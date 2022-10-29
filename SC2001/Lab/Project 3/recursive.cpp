#include <bits/stdc++.h>

using namespace std;

int size;
int max(int a, int b)
{
    return a > b ? a : b;
}

int knapsack_recursive(int w[], int p[], int cap, int idx, int n)
{
    if (idx >= n || cap <= 0)
    {
        return 0;
    }
    if (cap - w[idx] < 0)
    {
        return knapsack_recursive(w, p, cap, idx + 1, n);
    }
    int no = knapsack_recursive(w, p, cap, idx + 1, n);
    int yes = p[idx] + knapsack_recursive(w, p, cap - w[idx], idx, n);
    return max(yes, no);
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
    cout << "The most profit you can get from the knapsack is " << knapsack_recursive(w, p, cap, 0, n) << endl;
}