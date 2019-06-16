#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>
using namespace std;
typedef long long ll;

int main()
{
    ll n, k;
    cin >> n >> k;

    vector<ll> l_sum(n + 1);
    vector<ll> cnt(n + 1);
    vector<bool> flg(n + 1);
    l_sum[0] = 0;
    for (ll i = 1; i <= n; i++)
    {
        ll a;
        cin >> a;
        l_sum[i] = l_sum[i - 1] + a;
    }

    // vector<ll> r_sum(n + 1);
    // for (ll i = 1; i <= n; i++)
    // {
    //     r_sum[i] = l_sum[n] - l_sum[i - 1];
    // }

    ll c = 0;
    for (ll i = 1; i <= n; i++)
    {
        if (l_sum[n] - l_sum[i - 1] < k)
        {
            continue;
        }
        for (ll j = i; j <= n; j++)
        {
            ll sum = l_sum[j] - l_sum[i - 1];
            if (sum >= k)
            {
                c += (n - j + 1);
                break;
            }
        }
    }
    cout << c << endl;
    return 0;
}
