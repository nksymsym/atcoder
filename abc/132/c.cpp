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
    vi d(n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d ", &d[i]);
    }

    sort(d.begin(), d.end());
    int cnt = d[n / 2] - d[n / 2 - 1];
    cnt = cnt < 0 ? 0 : cnt;
    cout << cnt << endl;

    return 0;
}
