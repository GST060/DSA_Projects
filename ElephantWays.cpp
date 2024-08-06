#include <bits/stdc++.h>
using namespace std;

int ElephantWays(int i, int j)
{
    // base case
    if (i == 0 and j == 0)
    {
        return 1;
    }
    if (i < 0 || j < 0)
    {
        return 0;
    }

    // Recursive case
    int ans = 0;
    for (int k = 0; k < i; k++)
    {
        ans += ElephantWays(k, j);
    }
    for (int k = 0; k < j; k++)
    {
        ans += ElephantWays(i, k);
    }
    return ans;
}

int main()
{
    int n, m;
    cin >> n >> m;
    cout << ElephantWays(n, m) << endl;

    return 0;
}
