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
    int n, m;
    cin >> n >> m;

    vector<bool> all_like(m);
    fill(all_like.begin(), all_like.end(), true);

    for (int i = 0; i < n; i++)
    {
        int k;
        cin >> k;
        vector<bool> k_like(m);
        fill(k_like.begin(), k_like.end(), false);
        for (int j = 0; j < k; j++)
        {
            int t;
            cin >> t;
            k_like[t - 1] = true;
        }
        for (int j = 0; j < m; j++)
        {
            all_like[j] = all_like[j] & k_like[j];
        }
    }

    int cnt = 0;
    for (int i = 0; i < m; i++)
    {
        if (all_like[i])
        {
            cnt++;
        }
    }
    cout << cnt << endl;

    return 0;
}