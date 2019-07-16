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
    ll n;
    cin >> n;

    double l = log2(n);
    if (l - floor(l) == 0)
    {
        cout << "No" << endl;
    }
    else
    {
        cout << "Yes" << endl;

        printf("%lld %lld\n", 1LL, 2LL);
        printf("%lld %lld\n", 2LL, 3LL);
        printf("%lld %lld\n", 3LL, 1 + n);
        printf("%lld %lld\n", 1 + n, 2 + n);
        printf("%lld %lld\n", 2 + n, 3 + n);

        for (ll i = 4; i < n; i += 2)
        {
            printf("%lld %lld\n", i, i + 1);
            printf("%lld %lld\n", i + 1, 1LL);
            printf("%lld %lld\n", 1LL, i + n);
            printf("%lld %lld\n", i + n, i + 1 + n);
        }

        if (n % 2 == 0)
        {
            ll x, y;
            for (ll i = 2; i < n; i++)
            {
                x = i;
                y = (n + 1) ^ i;
                if (1 < y && y < n)
                {
                    break;
                }
            }

            if (x % 2 == 0)
            {
                x += n;
            }
            if (y % 2 == 0)
            {
                y += n;
            }

            printf("%lld %lld\n", x, n);
            printf("%lld %lld\n", y, n + n);
        }
    }

    return 0;
}
