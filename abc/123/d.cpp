#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
typedef long long ll;

int main()
{
    int x, y, z, k;
    cin >> x >> y >> z >> k;

    vector<ll> a(x);
    vector<ll> b(y);
    vector<ll> c(z);
    for (int i = 0; i < x; i++)
    {
        cin >> a[i];
    }
    for (int i = 0; i < y; i++)
    {
        cin >> b[i];
    }
    for (int i = 0; i < z; i++)
    {
        cin >> c[i];
    }

    sort(a.begin(), a.end(), greater<ll>());
    sort(b.begin(), b.end(), greater<ll>());
    sort(c.begin(), c.end(), greater<ll>());

    priority_queue<ll, vector<ll>, greater<ll>> q;
    for (ll ai = 0; ai < x; ai++)
    {
        for (ll bi = 0; bi < y; bi++)
        {
            for (ll ci = 0; ci < z; ci++)
            {
                ll val = (a[ai] + b[bi] + c[ci]);
                if (q.size() >= k)
                {
                    if (q.top() > val)
                    {
                        break;
                    }
                    else
                    {
                        q.pop();
                        q.push(val);
                    }
                }
                else
                {
                    q.push(val);
                }
            }
        }
    }

    vector<ll> ans(k);
    for (int i = 0; i < k; i++)
    {
        ans[i] = q.top();
        q.pop();
    }

    for (int i = k - 1; i >= 0; i--)
    {
        cout << ans[i] << endl;
    }

    return 0;
}
