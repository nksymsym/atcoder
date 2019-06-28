#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>
#include <cmath>
#include <iomanip>
using namespace std;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef long long ll;
typedef vector<ll> vll;
typedef vector<vector<ll>> vvll;

int main()
{
    ll n, k;
    cin >> n >> k;

    vll d(n);
    ll dmax = 0;
    for (ll i = 0; i < n; i++)
    {
        double ki = (double)k / (i + 1);
        d[i] = ceil(log2(ki));
        if (d[i] < 0)
        {
            d[i] = 0;
        }
        dmax = max(dmax, d[i]);
    }

    ll numerator = 0;
    ll denominator = pow(2LL, dmax);
    for (ll i = 0; i < n; i++)
    {
        numerator += pow(2LL, dmax - d[i]);
    }

    cout << setprecision(12) << ((double)numerator / denominator / n) << endl;

    return 0;
}