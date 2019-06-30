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
    vi p(n);
    for (int i = 0; i < n; i++)
    {
        cin >> p[i];
    }

    int cnt = 0;
    int prev = p[0];
    int curr = p[1];
    for (int i = 2; i < n; i++)
    {
        int next = p[i];
        if ((prev < curr && curr <= next) || (next < curr && curr <= prev))
        {
            cnt++;
        }
        prev = curr;
        curr = next;
    }

    cout << cnt << endl;
    return 0;
}
