#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>
using namespace std;
typedef long long ll;

ll mod = 1e9 + 7;

int main()
{
    ll n, m;
    cin >> n >> m;

    ll s[n + 1];
    ll t[m + 1];
    for (ll i = 0; i < n; i++)
    {
        cin >> s[i + 1];
    }
    for (ll i = 0; i < m; i++)
    {
        cin >> t[i + 1];
    }

    ll dp[n + 1][m + 1];
    for (ll i = 0; i <= n; i++)
    {
        for (ll j = 0; j <= m; j++)
        {
            if (i == 0 || j == 0)
            {
                dp[i][j] = 1;
            }
            else
            {
                if (s[i] == t[j])
                {
                    dp[i][j] = (dp[i - 1][j] + dp[i][j - 1]) % mod;
                }
                else
                {
                    dp[i][j] = (dp[i - 1][j] + dp[i][j - 1] - dp[i - 1][j - 1]) % mod;
                    if (dp[i][j] < 0)
                    {
                        dp[i][j] += mod;
                    }
                }
            }
        }
    }

    cout << dp[n][m] << endl;

    return 0;
}
