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

ll calc(ll n, ll m)
{
    ll l = n > m ? n : m;
    ll s = n <= m ? n : m;
    ll mod = l % s;

    if (mod == 0)
    {
        return s;
    }
    else
    {
        return calc(s, mod);
    }
}

int main()
{
    int n;
    cin >> n;
    vll a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    ll min = a[0];
    for (int i = 1; i < n; i++)
    {
        min = calc(min, a[i]);
        if (min == 1)
        {
            break;
        }
    }

    cout << min << endl;

    return 0;
}