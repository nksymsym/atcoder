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
    vll a(n);
    for (int i = 0; i < n; i++)
    {
        scanf("%lld", &a[i]);
    }

    vll b(n + 1);
    b[0] = 0;
    for (int i = 1; i <= n; i++)
    {
        b[i] = a[i - 1] * 2 - b[i - 1];
    }

    ll d = b[n] - b[0];
    b[0] = d / 2;
    printf("%lld", b[0]);
    for (int i = 1; i < n; i++)
    {
        b[i] = a[i - 1] * 2 - b[i - 1];
        printf(" %lld", b[i]);
    }

    return 0;
}
