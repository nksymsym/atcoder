#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>
using namespace std;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef long long ll;
typedef vector<ll> vll;
typedef vector<vector<ll>> vvll;

ll mod = 1e9 + 7;

int main()
{
    string s;
    cin >> s;
    int len = s.length();
    vvll dp(len);

    {
        int i = 0;
        char si = s[len - 1 - i];
        dp[i] = vll(13, 0);
        if (si == '?')
        {
            for (int d = 0; d < 10; d++)
            {
                dp[i][d] = 1;
            }
        }
        else
        {
            int d = si - '0';
            dp[i][d] = 1;
        }
    }

    ll mb = 1;
    for (int i = 1; i < len; i++)
    {
        mb = mb * 10 % 13;
        char si = s[len - 1 - i];
        dp[i] = vll(13, 0);
        if (si == '?')
        {
            for (int d = 0; d < 10; d++)
            {
                ll m = mb * d % 13;
                for (int j = 0; j < 13; j++)
                {
                    dp[i][(j + m) % 13] += dp[i - 1][j];
                    dp[i][(j + m) % 13] %= mod;
                }
            }
        }
        else
        {
            int d = si - '0';
            ll m = mb * d % 13;
            for (int j = 0; j < 13; j++)
            {
                dp[i][(j + m) % 13] += dp[i - 1][j];
                dp[i][(j + m) % 13] %= mod;
            }
        }
    }

    cout << dp[len - 1][5] << endl;

    return 0;
}
