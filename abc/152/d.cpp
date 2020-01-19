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

    vvll cnt(10);
    for (size_t i = 0; i <= 9; i++)
    {
        cnt[i] = vll(10, 0);
    }

    for (int i = 1; i <= n; i++)
    {
        string str = to_string(i);
        int st = str[0] - '0';
        int ed = str[str.length() - 1] - '0';
        cnt[st][ed]++;
    }

    ll ans = 0;
    for (size_t st = 1; st <= 9; st++)
    {
        for (size_t ed = 1; ed <= 9; ed++)
        {
            ans += (cnt[st][ed] * cnt[ed][st]);
        }
    }

    cout << ans << endl;

    return 0;
}
