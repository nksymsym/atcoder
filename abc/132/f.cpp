#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>
#include <set>
using namespace std;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef long long ll;
typedef vector<ll> vll;
typedef vector<vector<ll>> vvll;
typedef pair<int, int> pii;
typedef vector<pair<int, int>> vpii;

ll mod = 1e9 + 7;

int main()
{
    int n, k;
    cin >> n >> k;

    set<int, greater<int>> s;
    for (int i = 1; i * i <= n; i++)
    {
        s.insert(i);
        s.insert(n / i);
    }

    int prev = 0;
    int sz = s.size();
    vpii gr(sz);
    int idx = 0;
    for (auto v : s)
    {
        gr[idx] = pii(sz - idx - 1, n / v - prev);
        prev = n / v;
        idx++;
    }

    vvll dp(2);
    dp[0] = vll(gr.size(), 0);
    dp[1] = vll(gr.size(), 0);
    int curr = 0;
    for (int i = 0; i < gr.size(); i++)
    {
        int num = gr[i].first;
        int cnt = gr[i].second;
        dp[curr][i] = cnt;
    }

    for (int i = 1; i < k; i++)
    {
        int next = curr ^ 1;
        dp[next] = vll(gr.size(), 0);

        vll sum = vll(gr.size(), 0);
        sum[0] = dp[curr][0] * gr[0].second;
        for (int j = 1; j < gr.size(); j++)
        {
            sum[j] = sum[j - 1] + dp[curr][j];
            sum[j] %= mod;
        }

        for (int j = 0; j < gr.size(); j++)
        {
            int num = gr[j].first;
            int cnt = gr[j].second;
            dp[next][j] = sum[num] * cnt;
            dp[next][j] %= mod;
        }
        curr = next;
    }

    ll sum = 0;
    for (int i = 0; i < gr.size(); i++)
    {
        sum += dp[curr][i];
        sum %= mod;
    }

    cout << sum << endl;

    return 0;
}
