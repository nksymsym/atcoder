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

ll div_mod(ll n, ll d)
{
    return (n * pow_mod(d, mod - 2)) % mod;
}

int main()
{
    ll n;
    cin >> n;
    vll a(n);
    ll a_max = 0;
    for (ll i = 0; i < n; i++)
    {
        cin >> a[i];
        a_max = max(a_max, a[i]);
    }

    vll fc(a_max + 1, 0);
    for (ll i = 2; i <= a_max; i++)
    {
        if (fc[i] != 0)
        {
            continue;
        }
        for (ll j = i; j <= a_max; j += i)
        {
            if (fc[j] == 0)
            {
                fc[j] = i;
            }
        }
    }

    vll lcm_pf(a_max + 1, 0);
    set<ll> primes;
    for (ll i = 0; i < n; i++)
    {
        ll num = a[i];
        ll prime = fc[num];
        ll prime_cnt = 0;
        ll prev_prime = 0;
        while (num > 1)
        {
            prime_cnt++;
            num /= prime;
            prev_prime = prime;
            prime = fc[num];
            if (prev_prime != prime)
            {
                lcm_pf[prev_prime] = max(lcm_pf[prev_prime], prime_cnt);
                primes.insert(prev_prime);
                prime_cnt = 0;
            }
        }
    }

    ll lcm_mod = 1;
    for (auto itr = primes.begin(); itr != primes.end(); itr = next(itr))
    {
        ll prime = *itr;
        lcm_mod *= pow_mod(prime, lcm_pf[prime]);
        lcm_mod %= mod;
    }

    ll ans = 0;
    for (ll i = 0; i < n; i++)
    {
        ll a_mod = 1;
        ll num = a[i];
        ll prime = fc[num];
        ll prime_cnt = 0;
        ll prev_prime = 0;
        while (num > 1)
        {
            prime_cnt++;
            num /= prime;
            prev_prime = prime;
            prime = fc[num];
            if (prev_prime != prime)
            {
                a_mod *= pow_mod(prev_prime, prime_cnt);
                a_mod %= mod;
                prime_cnt = 0;
            }
        }
        ans += div_mod(lcm_mod, a_mod);
        ans %= mod;
    }

    cout << ans << endl;
}
