#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>
#include <map>
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
    map<string, ll> mp;
    for (int i = 0; i < n; i++)
    {
        string s;
        cin >> s;

        vector<char> sorted(s.length());
        for (size_t j = 0; j < s.length(); j++)
        {
            sorted[j] = s[j];
        }
        sort(sorted.begin(), sorted.end());

        string key = "";
        for (size_t j = 0; j < s.length(); j++)
        {
            key = key + sorted[j];
        }

        if (mp.find(key) != mp.end())
        {
            mp[key]++;
        }
        else
        {
            mp[key] = 1;
        }
    }

    ll ans = 0;
    for (auto v : mp)
    {
        ll cnt = v.second;
        ans += (cnt * (cnt - 1) / 2);
    }
    cout << ans << endl;

    return 0;
}
