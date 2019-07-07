#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <stack>
#include <cmath>
#include <queue>
using namespace std;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef long long ll;
typedef vector<ll> vll;
typedef vector<vector<ll>> vvll;

int main()
{
    int n, d;
    cin >> n >> d;

    vvi x(n);
    for (int i = 0; i < n; i++)
    {
        vi p(d);
        for (int j = 0; j < d; j++)
        {
            cin >> p[j];
        }
        x[i] = p;
    }

    int cnt = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            int d2 = 0;
            for (int k = 0; k < d; k++)
            {
                d2 += (x[i][k] - x[j][k]) * (x[i][k] - x[j][k]);
            }
            int d = sqrt(d2);
            if (d * d == d2)
            {
                cnt++;
            }
        }
    }

    cout << cnt << endl;
    return 0;
}
