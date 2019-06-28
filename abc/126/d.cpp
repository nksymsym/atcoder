#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>
using namespace std;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef pair<int, int> pii;
typedef vector<vector<pii>> vvpii;

void dfs(vvpii &g, vi &col, int v)
{
    for (auto i : g[v])
    {
        int u = i.first;
        int w = i.second;
        if (col[u] == -1)
        {
            col[u] = col[v] ^ w;
            dfs(g, col, u);
        }
    }
}

int main()
{
    int n;
    cin >> n;

    vvpii g(n);
    for (int i = 0; i < n - 1; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        u--;
        v--;
        w %= 2;
        g[u].push_back(make_pair(v, w));
        g[v].push_back(make_pair(u, w));
    }

    vi col(n);
    fill(col.begin(), col.end(), -1);
    col[0] = 0;
    dfs(g, col, 0);

    for (int i = 0; i < n; i++)
    {
        cout << col[i] << endl;
    }

    return 0;
}