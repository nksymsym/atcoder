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
typedef pair<ll, ll> pll;
typedef vector<pll> vpll;

int main()
{
    ll n;
    cin >> n;

    vpll task(n);
    for (ll i = 0; i < n; i++)
    {
        ll a, b;
        cin >> a >> b;
        pll p = make_pair(b, a);
        task[i] = p;
    }

    sort(task.begin(), task.end());

    string ans = "Yes";
    ll time = 0;
    for (ll i = 0; i < n; i++)
    {
        time += task[i].second;
        if (time > task[i].first)
        {
            ans = "No";
            break;
        }
    }
    cout << ans << endl;

    return 0;
}