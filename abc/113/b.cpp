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
    int n, t, a;
    cin >> n >> t >> a;

    int ans = 0;
    double min = 1e9;
    for (int i = 0; i < n; i++)
    {
        int h;
        cin >> h;
        double d = t - h * 0.006 - a;
        if (d < 0)
        {
            d *= -1;
        }
        if (min > d)
        {
            min = d;
            ans = i + 1;
        }
    }

    cout << ans << endl;

    return 0;
}
