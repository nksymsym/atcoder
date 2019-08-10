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
    int a, b;
    cin >> a >> b;
    int ans = a + b;
    int tmp = a - b;
    ans = max(ans, tmp);
    tmp = a * b;
    ans = max(ans, tmp);
    cout << ans << endl;
    return 0;
}
