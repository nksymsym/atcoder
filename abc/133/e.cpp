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

ll mod = 1000000007;
ll ans = 1;
ll k;

void dfs(vvi &g, vi &p, vi &ccnt, vi &visited, ll v)
{
    if (visited[v] == 1)
    {
        return;
    }
    visited[v] = 1;

    if (ans < 0)
    {
        ans = 0;
        return;
    }

    if (p[v] == -1)
    {
        ans *= k;
    }
    else if (p[p[v]] == -1)
    {
        ans *= k - ccnt[p[v]] - 1;
    }
    else
    {
        ans *= k - ccnt[p[v]] - 2;
    }
    ans %= mod;

    for (ll u : g[v])
    {
        if (u == p[v])
        {
            continue;
        }
        p[u] = v;
        dfs(g, p, ccnt, visited, u);
        ccnt[v]++;
    }
}

int main()
{
    int n;
    cin >> n >> k;
    vvi g(n);
    for (int i = 0; i < n - 1; i++)
    {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    vi p(n, 0);
    vi ccnt(n, 0);
    vi visited(n, 0);
    p[0] = -1;
    dfs(g, p, ccnt, visited, 0);
    cout << ans << endl;

    return 0;
}
