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

int mod = 2019;
int main()
{
    int l, r;
    cin >> l >> r;

    int min = mod + 1;
    if (r - l >= mod)
    {
        min = 0;
    }
    else
    {
        int im = l % mod;
        for (int i = l; i < r; i++)
        {
            int jm = (i + 1) % mod;
            for (int j = i + 1; j <= r; j++)
            {
                int tmp = (im * jm) % mod;
                if (min > tmp)
                {
                    min = tmp;
                }
                jm = (jm + 1) % mod;
            }
            im = (im + 1) % mod;
        }
    }
    cout << min << endl;

    return 0;
}
