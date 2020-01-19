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
    int n;
    cin >> n;
    vi p(n);
    for (int i = 0; i < n; i++)
    {
        cin >> p[i];
    }

    int mn = 2 * 100000 + 1;
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        if (mn >= p[i])
        {
            mn = p[i];
            ans++;
        }
    }

    cout << ans << endl;

    return 0;
}
