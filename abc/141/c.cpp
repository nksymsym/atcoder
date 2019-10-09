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
    int n, k, q;
    cin >> n >> k >> q;
    vi p(n, 0);
    for (int i = 0; i < q; i++)
    {
        int a;
        cin >> a;
        a--;
        p[a]++;
    }

    for (int i = 0; i < n; i++)
    {
        if (k - (q - p[i]) > 0)
        {
            cout << "Yes" << endl;
        }
        else
        {
            cout << "No" << endl;
        }
    }

    return 0;
}