#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>
using namespace std;
typedef long long ll;

using pr = pair<ll, ll>;

struct edge
{
    ll to;
    ll cost;
};

void dijkstra(vector<vector<edge>> &g, vector<ll> &d, ll s)
{
    // pair(距離、頂点)をpriority_queue(距離の小さい順)に入れる
    priority_queue<pr, vector<pr>, greater<pr>> q;
    fill(d.begin(), d.end(), __LONG_LONG_MAX__);
    d[s] = 0;
    q.push(pr{0, s});

    while (!q.empty())
    {
        pr p = q.top();
        q.pop();
        int v = p.second;
        if (d[v] < p.first)
        {
            // すでに計算した距離より大きければスキップ
            continue;
        }

        // 次の頂点への距離を計算
        for (edge e : g[v])
        {
            if (d[v] + e.cost < d[e.to])
            {
                // すでに計算した距離より小さければ更新
                d[e.to] = d[v] + e.cost;
                q.push(pr{d[e.to], e.to});
            }
        }
    }
}

int main()
{
    ll n, m, t;
    cin >> n >> m >> t;

    vector<ll> prize(n);
    for (ll i = 0; i < n; i++)
    {
        cin >> prize[i];
    }

    vector<vector<edge>> g_go(n);
    vector<vector<edge>> g_back(n);
    for (ll i = 0; i < m; i++)
    {
        ll a, b, c;
        cin >> a >> b >> c;
        edge e_go = {b - 1, c};
        edge e_back = {a - 1, c};
        g_go[a - 1].push_back(e_go);
        g_back[b - 1].push_back(e_back);
    }

    // 各地点への行きの最短経路(移動時間)
    vector<ll> cost_go(n);
    dijkstra(g_go, cost_go, 0);

    // 各地点からの帰りの最短経路(移動時間)
    vector<ll> cost_back(n);
    dijkstra(g_back, cost_back, 0);

    // 帰りの最短経路を考慮して、得られる賞金を計算
    ll max = 0;
    for (ll i = 0; i < n; i++)
    {
        if (cost_go[i] + cost_back[i] < 0)
        {
            continue;
        }

        ll time = t - cost_go[i] - cost_back[i];
        if (time <= 0)
        {
            continue;
        }

        ll tmp = prize[i] * (time);
        if (max < tmp)
        {
            max = tmp;
        }
    }

    cout << max << endl;
    return 0;
}