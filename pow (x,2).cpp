#include <bits/stdc++.h>
using namespace std;

double solve(double x, long n)
{
    if (n < 0)
        return 1 / solve(x, abs(n));
    if (n == 0)
        return 1;
    if (x == 1)
        return 1;
    double ans = solve(x, n / 2);
    ans *= ans;
    if (n & 1)
        ans *= x;
    return ans;
}

double myPow(double x, int n)
{
    if (n >= 0)
        return solve(x, n);
    return 1.0 / solve(x, abs(n));
}

int main()
{
    double n;
    int m;
    cout << "Enter the value of x and n:";
    cin >> n >> m;
    cout << "The value of " << n << " raised to " << m << " is :" << myPow(n, m) << endl;
    return 0;
}