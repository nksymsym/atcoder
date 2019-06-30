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

int inf = 1e6;

int main()
{
    int n, m;
    cin >> n >> m;
    vvi g(n);
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        u--;
        v--;
        g[u].push_back(v);
    }

    int s, t;
    cin >> s >> t;
    s--;
    t--;

    vvi sg(n);
    for (int i = 0; i < n; i++)
    {
        sg[i] = vi(3, inf);
    }

    queue<pii> q;
    q.push(make_pair(s, 0));
    sg[s][0] = 0;
    while (!q.empty())
    {
        int u = q.front().first;
        int st = q.front().second;
        q.pop();
        int nst = (st + 1) % 3;
        for (int v : g[u])
        {
            if (sg[v][nst] != inf)
            {
                // あとから最短ルートが出てくることってない？
                continue;
            }
            sg[v][nst] = sg[u][st] + 1;
            q.push(make_pair(v, nst));
        }
    }

    int ans = (sg[t][0] == inf) ? -1 : sg[t][0] / 3;
    cout << ans << endl;

    return 0;
}
