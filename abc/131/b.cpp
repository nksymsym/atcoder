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
    int n, l;
    cin >> n >> l;

    int sum = 0;
    int min = 10000;
    for (int i = 1; i <= n; i++)
    {
        int t = l + i - 1;
        if (abs(min) > abs(t))
        {
            min = t;
        }
        sum += t;
    }

    sum -= min;
    cout << sum << endl;

    return 0;
}