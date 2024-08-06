#include <bits/stdc++.h>
using namespace std;

int NStairs(int n)
{
    // base case
    if (n == 0)
    {
        return 1;
    }
    if (n < 0)
    {
        return 0;
    }

    // Recursive case
    return NStairs(n - 1) + NStairs(n - 2) + NStairs(n - 3);
}

int nStairs(int n, int k)
{
    // base case
    if (n == 0)
    {
        return 1;
    }
    if (n < 0)
    {
        return 0;
    }

    // Recursive Case
    int ans = 0;
    for (int i = 1; i <= k; i++)
    {
        ans += nStairs(n - i, k);
    }
    return ans;
}

int main()
{
    // cout << "n:0 ---> " << NStairs(0) << endl;
    // cout << "n:1 ---> " << NStairs(1) << endl;
    // cout << "n:2 ---> " << NStairs(2) << endl;
    // cout << "n:3 ---> " << NStairs(3) << endl;
    // cout << "n:4 ---> " << NStairs(4) << endl;
    cout << "n:5 ---> " << NStairs(5) << endl;
    cout << nStairs(5, 3) << endl;

    return 0;
}
