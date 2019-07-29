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

    vll a(n + 1);
    for (int i = 0; i < n + 1; i++)
    {
        scanf("%lld", &a[i]);
    }

    vll b(n);
    for (int i = 0; i < n; i++)
    {
        scanf("%lld", &b[i]);
    }

    ll sum = 0;
    ll rest = a[0];
    for (int i = 0; i < n; i++)
    {
        if (rest <= b[i])
        {
            sum += rest;
            if (a[i + 1] <= b[i] - rest)
            {
                sum += a[i + 1];
                rest = 0;
            }
            else
            {
                sum += b[i] - rest;
                rest = a[i + 1] - (b[i] - rest);
            }
        }
        else
        {
            sum += b[i];
            rest = a[i + 1];
        }
    }
    cout << sum << endl;

    return 0;
}
