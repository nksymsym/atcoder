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

ll cmb_mod(ll n, ll k)
{
    ll ret = 1;
    for (ll i = 1; i <= k; i++)
    {
        ret *= (n - i + 1);
        ret %= mod;
        ret *= pow_mod(i, mod - 2);
        ret %= mod;
    }
    return ret;
}

ll cmb_mod(ll n, ll k, ll prev)
{
    ll ret = prev;
    ret *= (n - k + 1);
    ret %= mod;
    ret *= pow_mod(k, mod - 2);
    ret %= mod;
    return ret;
}

int main()
{
    ll n, k;
    cin >> n >> k;
    ll pat1 = cmb_mod(k - 1, 1 - 1);
    ll pat2 = cmb_mod(n - k + 1, 1);
    ll pat = (pat1 * pat2) % mod;
    cout << pat << endl;
    for (ll i = 2; i <= k; i++)
    {
        pat1 = cmb_mod(k - 1, i - 1, pat1);
        pat2 = cmb_mod(n - k + 1, i, pat2);
        pat = (pat1 * pat2) % mod;
        cout << pat << endl;
    }

    return 0;
}
