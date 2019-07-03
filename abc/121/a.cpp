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
    int h, w, rowcnt, colcnt;
    cin >> h >> w >> rowcnt >> colcnt;

    cout << (h * w - rowcnt * w - colcnt * h + rowcnt * colcnt) << endl;
    return 0;
}