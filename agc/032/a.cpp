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
    vi b(n + 1);
    b[0] = 0;
    for (int i = 1; i < n + 1; i++)
    {
        cin >> b[i];
    }

    bool flg = true;
    vi ans(n + 1);
    for (int i = n; i >= 1 && flg; i--)
    {
        for (int j = i; j >= 1; j--)
        {
            flg = false;
            if (b[j] == j)
            {
                ans[i] = j;
                b.erase(b.begin() + j);
                flg = true;
                break;
            }
        }
    }

    if (flg)
    {
        for (int i = 1; i < n + 1; i++)
        {
            cout << ans[i] << endl;
        }
    }
    else
    {
        cout << -1 << endl;
    }

    return 0;
}
