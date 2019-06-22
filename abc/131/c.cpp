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

ll gcd(ll x, ll y)
{
    if (x < y)
    {
        ll tmp = x;
        x = y;
        y = tmp;
    }

    ll m = x % y;
    if (m == 0)
    {
        return y;
    }

    return gcd(y, m);
}

ll lcm(ll x, ll y)
{
    return x * y / gcd(x, y);
}

int main()
{
    ll a, b, c, d;
    cin >> a >> b >> c >> d;

    ll e = lcm(c, d);

    a -= 1;
    ll all = b - a;

    // a-1以下
    ll ca = a / c;
    ll da = a / d;
    ll ea = a / e;

    // b以下
    ll cb = b / c;
    ll db = b / d;
    ll eb = b / e;

    cout << (all - ((cb - ca) + (db - da) - (eb - ea))) << endl;
    return 0;
}