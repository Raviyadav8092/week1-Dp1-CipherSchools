#include <bits/stdc++.h>
using namespace std;

int solve(int i, int j, int n, int m, vector<vector<int>> &dp)
{
    if (i == n - 1 && j == m - 1)
    {
        return 1;
    }
    if (i >= n || j >= m)
        return 0;
    if (dp[i][j] != -1)
        return dp[i][j];
    int ans = solve(i + 1, j, n, m, dp);
    ans += solve(i, j + 1, n, m, dp);
    return dp[i][j] = ans;
}

int uniquePaths(int m, int n)
{
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, -1));
    return solve(0, 0, m, n, dp);
}

int main()
{
    cout << "Enter number of rows and columns :";
    int n, m;
    cin >> n >> m;

    cout << "The number of possible ways is:\n"
         << uniquePaths(n, m);
    return 0;
}