#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>
#include <map>
using namespace std;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef long long ll;
typedef vector<ll> vll;
typedef vector<vector<ll>> vvll;

ll mod = 1000000007;

ll pat(int n)
{
    if (n < 1)
    {
        return 1;
    }

    vll ari(n);
    vll nashi(n);
    ari[0] = 1;
    nashi[0] = 1;
    for (int i = 1; i < n; i++)
    {
        ari[i] = nashi[i - 1];
        nashi[i] = ari[i - 1] + nashi[i - 1];
    }

    return ari[n - 1] + nashi[n - 1];
}

int main()
{
    int h, w, k;
    cin >> h >> w >> k;

    vvll dp(h + 1);
    dp[0] = vll(w + 2, 0);
    dp[0][1] = 1;

    map<int, ll> p;
    for (int i = -7; i < 8; i++)
    {
        p[i] = pat(i);
    }

    for (int i = 1; i <= h; i++)
    {
        dp[i] = vll(w + 2, 0);
        for (int j = 1; j <= w; j++)
        {
            dp[i][j] += dp[i - 1][j] * p[j - 2] * p[w - j - 1];
            dp[i][j] += dp[i - 1][j - 1] * p[j - 3] * p[w - j - 1];
            dp[i][j] += dp[i - 1][j + 1] * p[j - 2] * p[w - j - 2];
            dp[i][j] %= mod;
        }
    }

    cout << dp[h][k] << endl;

    return 0;
}
