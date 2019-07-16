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
typedef pair<int, int> pr;
typedef set<pr> st;

vvi g(1e5);
vvi tr(1e5);
vi pt(1e5);
vi vst(1e5);
st ans;

void tree(vvi &g, int p, int v)
{
    if (p != -1)
    {
        if (vst[v] == 1)
        {
            int lt = p > v ? v : p;
            int gr = p > v ? p : v;
            auto ret = ans.insert(pr(lt, gr));
            if (ret.second)
            {
                pt[lt] ^= 1;
            }
            return;
        }
        else
        {
            tr[p].push_back(v);
        }
    }
    vst[v] = 1;

    for (int u : g[v])
    {
        if (u != p)
        {
            tree(g, v, u);
        }
    }
}

void solve(int p, int v)
{
    for (int u : tr[v])
    {
        solve(v, u);
    }

    if (p == -1)
    {
        return;
    }

    if (pt[v] == 0)
    {
        ans.insert(pr(p, v));
        pt[p] ^= 1;
    }
    else
    {
        ans.insert(pr(v, p));
        pt[v] ^= 1;
    }
}

int main()
{
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    if (m % 2 == 0)
    {
        tree(g, -1, 0);
        solve(-1, 0);

        for (auto i : ans)
        {
            cout << i.first + 1 << " " << i.second + 1 << endl;
        }
    }
    else
    {
        cout << -1 << endl;
    }

    return 0;
}
