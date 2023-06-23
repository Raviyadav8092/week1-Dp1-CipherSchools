#include <bits/stdc++.h>
using namespace std;

void updateAns(vector<vector<int>> &board, vector<vector<int>> &ans, int n)
{
    vector<int> temp;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            temp.push_back(board[i][j]);
        }
    }
ans.push_back(temp);
return;
}

bool isSafe(vector<vector<int>> &board, int row, int col, int n,
            unordered_map<int, bool> &rowa,
            unordered_map<int, bool> &d1,
            unordered_map<int, bool> &d2)
{

    if (rowa[row])
        return false;
    if (d1[row + col])
        return false;
    if (d2[n - 1 + col - row])
        return false;
    return true;
}

void solve(vector<vector<int>> &board, int col, int n,
           vector<vector<int>> &ans,
           unordered_map<int, bool> &rowa,
           unordered_map<int, bool> &d1,
           unordered_map<int, bool> &d2)
{
    if (col == n)
    {
        updateAns(board, ans, n);
        return;
    }
    for (int i = 0; i < n; i++)
    {
        if (isSafe(board, i, col, n, rowa, d1, d2))
        {
            board[i][col] = 1;
            rowa[i] = 1;
            d1[i + col] = 1;
            d2[n - 1 + col - i] = 1;
            solve(board, col + 1, n, ans, rowa, d1, d2);
            board[i][col] = 0;
            rowa[i] = 0;
            d1[i + col] = 0;
            d2[n - 1 + col - i] = 0;
        }
    }
}

vector<vector<int>> nQueen(int n)
{

    vector<vector<int>> board(n, vector<int>(n, 0));
    vector<vector<int>> ans;
    unordered_map<int, bool> row;
    unordered_map<int, bool> d1;
    unordered_map<int, bool> d2;
    solve(board, 0, n, ans, row, d1, d2);
    return ans;
}
int main()
{
    int n;
    cout << "Enter N:";
    cin >> n;
    if (n == 2 || n==3)
    {
        cout << "No configuration possible!!";
        return 0;
    }
    vector<vector<int>> ans = nQueen(n);
    cout << "Possible Configurations are:" << endl;
    for (int i = 0; i < ans.size(); i++)
    {
        int cnt = 0;
        for (int j = 0; j < n; j++)
        {   for (int k = 0; k < n; k++)
                cout << ans[i][cnt++]<<" ";
            cout << endl;
        }
        cout << endl
             << endl;
    }
    return 0;
}