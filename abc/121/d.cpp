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
    // (2n)^(2n+1)=1
    ll a, b;
    cin >> a >> b;

    ll ans = 0;
    if (a % 2 == 1)
    {
        ans ^= a;
        a++;
    }
    if (b % 2 == 0)
    {
        ans ^= b;
        b--;
    }

    if ((b - a + 1) % 4 != 0)
    {
        ans ^= 1;
    }

    cout << ans << endl;

    return 0;
}