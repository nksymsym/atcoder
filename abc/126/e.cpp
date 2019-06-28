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

void visit(vvi &g, vi &visited, int v)
{
    visited[v] = true;
    for (int u : g[v])
    {
        if (!visited[u])
        {
            visit(g, visited, u);
        }
    }
}

int main()
{
    int n, m;
    cin >> n >> m;

    vvi g(n);
    for (int i = 0; i < m; i++)
    {
        int x, y, z;
        cin >> x >> y >> z;
        x--;
        y--;
        g[x].push_back(y);
        g[y].push_back(x);
    }

    vi visited(n);
    fill(visited.begin(), visited.end(), 0);
    int cnt = 0;
    for (int i = 0; i < n; i++)
    {
        if (visited[i])
        {
            continue;
        }
        cnt++;
        visit(g, visited, i);
    }

    cout << cnt << endl;
    return 0;
}