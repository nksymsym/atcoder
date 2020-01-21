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

ll mod = 1e9 + 7;

bool isPrime(ll n)
{
    for (int i = 3; i * i <= n; i += 2)
    {
        if (n % i == 0)
        {
            return false;
        }
    }
    return true;
}

ll pow_mod(ll n, ll p)
{
    ll ret = 1;
    ll wk_n = n;
    ll wk_p = p;
    while (wk_p > 0)
    {
        if (wk_p % 2 == 0)
        {
            wk_n *= wk_n;
            wk_p /= 2;
            wk_n %= mod;
        }
        else
        {
            ret *= wk_n;
            wk_p--;
            ret %= mod;
        }
    }
    return ret;
}

int main()
{
    ll n;
    cin >> n;
    vll a(n);
    ll mx = 0;
    for (ll i = 0; i < n; i++)
    {
        cin >> a[i];
        mx = max(mx, a[i]);
    }

    vll p(1e5);
    int cnt = 0;
    p[cnt] = 2;
    for (ll i = 3; i <= mx; i += 2)
    {
        if (isPrime(i))
        {
            cnt++;
            p[cnt] = i;
        }
    }

    ll sum = 1;
    vll pcnt(cnt + 1, 0);
    for (ll ai = 0; ai < n; ai++)
    {
        vll aipcnt(cnt + 1, 0);
        ll add = 1;
        for (int pi = 0; pi <= cnt; pi++)
        {
            while (a[ai] % p[pi] == 0)
            {
                aipcnt[pi]++;
                a[ai] /= p[pi];
            }
            if (pcnt[pi] < aipcnt[pi])
            {
                sum *= pow_mod(p[pi], aipcnt[pi] - pcnt[pi]);
                sum %= mod;
                pcnt[pi] = aipcnt[pi];
            }
            else if (aipcnt[pi] < pcnt[pi])
            {
                add *= pow_mod(p[pi], pcnt[pi] - aipcnt[pi]);
                add %= mod;
            }
        }

        sum += add;
        sum %= mod;

        if (ai == 0)
        {
            sum = 1;
        }
    }

    cout << sum << endl;

    return 0;
}
