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
    int n, m, c;
    cin >> n >> m >> c;

    vi b(m);
    for (int j = 0; j < m; j++)
    {
        cin >> b[j];
    }

    int cnt = 0;
    for (int i = 0; i < n; i++)
    {
        int sum = 0;
        for (int j = 0; j < m; j++)
        {
            int a;
            cin >> a;
            sum += a * b[j];
        }
        sum += c;
        if (sum > 0)
        {
            cnt++;
        }
    }

    cout << cnt << endl;
    return 0;
}