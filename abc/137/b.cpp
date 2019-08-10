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
    int k, x;
    cin >> k >> x;

    int mn = x - k + 1;
    int mx = x + k - 1;

    for (int i = mn; i < mx; i++)
    {
        cout << i << " ";
    }
    cout << mx << endl;

    return 0;
}
