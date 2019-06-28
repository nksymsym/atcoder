#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>
#include <cmath>
using namespace std;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef long long ll;
typedef vector<ll> vll;
typedef vector<vector<ll>> vvll;

int main()
{
    int m, k;
    cin >> m >> k;

    ll mx = pow(2LL, m);
    if (k == 0)
    {
        for (ll i = 0; i < mx - 1; i++)
        {
            cout << i << " " << i << " ";
        }
        cout << mx - 1 << " " << mx - 1 << endl;
    }
    else
    {
        if (m == 0 || m == 1 || mx <= k)
        {
            cout << "-1" << endl;
        }
        else
        {
            for (ll i = 0; i < mx; i++)
            {
                if (i != k)
                {
                    cout << i << " ";
                }
            }
            cout << k << " ";
            for (ll i = mx - 1; i >= 0; i--)
            {
                if (i != k)
                {
                    cout << i << " ";
                }
            }
            cout << k << endl;
        }
    }

    return 0;
}