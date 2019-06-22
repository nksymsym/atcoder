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
    int n, k;
    cin >> n >> k;

    int mx = (n - 1) * (n - 2) / 2;
    if (mx < k)
    {
        cout << -1 << endl;
    }
    else
    {
        vector<int> from;
        vector<int> to;
        for (int i = 2; i <= n; i++)
        {
            from.push_back(1);
            to.push_back(i);
        }

        bool flg = false;
        for (int i = 2; i <= n; i++)
        {
            if (flg)
            {
                break;
            }
            for (int j = i + 1; j <= n; j++)
            {
                if (mx == k)
                {
                    flg = true;
                    break;
                }
                mx--;
                from.push_back(i);
                to.push_back(j);
            }
        }

        cout << from.size() << endl;
        for (size_t i = 0; i < from.size(); i++)
        {
            cout << from[i] << " " << to[i] << endl;
        }
    }

    return 0;
}