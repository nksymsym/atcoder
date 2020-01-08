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

int main()
{
    ll n;
    cin >> n;

    ll ans = 0;
    if (n % 2 == 1)
    {
        ans = 0;
    }
    else
    {
        vll cnt(100, 0);
        vll cycle(100, 0);

        ll i = 1;
        ll tmpCycle = 10;
        while (tmpCycle <= n)
        {
            cnt[i] = cnt[i - 1] * 5 + 1;
            cycle[i] = tmpCycle;
            //cout << "debug(1):" << i << "," << cnt[i] << "," << cycle[i] << endl;
            i++;
            tmpCycle *= 5;
        }

        i--;
        while (i > 0)
        {
            while (cycle[i] <= n)
            {
                //cout << "debug(2):" << i << "," << n << "," << cycle[i] << endl;
                ans += cnt[i];
                n -= cycle[i];
            }
            i--;
        }
    }

    cout << ans << endl;

    return 0;
}