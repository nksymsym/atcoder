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
    vi a(n + 1);
    for (int i = 1; i < n + 1; i++)
    {
        scanf("%d", &a[i]);
    }

    int cnt = 0;
    vi ans(n + 1, 0);
    for (int i = n; i >= 1; i--)
    {
        int j = i;
        ans[i] = a[i];
        j += i;
        while (j <= n)
        {
            ans[i] ^= ans[j];
            j += i;
        }
        if (ans[i] == 1)
        {
            cnt++;
        }
    }

    cout << cnt << endl;
    for (int i = 1; i < n + 1; i++)
    {
        if (ans[i] == 1)
        {
            printf("%d ", i);
        }
    }
    printf("\n");

    return 0;
}
