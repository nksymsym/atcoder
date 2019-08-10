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

int main()
{
    ll n, m;
    cin >> n >> m;

    vvll task(m + 1);
    for (ll i = 0; i < n; i++)
    {
        ll a, b;
        cin >> a >> b;
        if (a <= m)
        {
            task[a].push_back(b);
        }
    }

    priority_queue<ll> q;
    ll ans = 0;
    for (ll i = 1; i <= m; i++)
    {
        // i日前にする仕事
        for (auto b : task[i])
        {
            q.push(b);
        }
        if (!q.empty())
        {
            ans += q.top();
            q.pop();
        }
    }

    cout << ans << endl;

    return 0;
}
