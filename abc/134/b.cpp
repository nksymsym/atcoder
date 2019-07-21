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
    int n, d;
    cin >> n >> d;
    int dd = d * 2 + 1;
    int ans = (n + dd - 1) / dd;
    cout << ans << endl;
    return 0;
}
