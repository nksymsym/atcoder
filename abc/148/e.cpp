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
        n /= 2;
        while (n >= 5)
        {
            ans += n / 5;
            n /= 5;
        }
    }

    cout << ans << endl;

    return 0;
}