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
    int s;
    cin >> s;

    int former = s / 100;
    int latter = s % 100;

    string ans;
    if (1 <= former && former <= 12)
    {
        if (1 <= latter && latter <= 12)
        {
            ans = "AMBIGUOUS";
        }
        else
        {
            ans = "MMYY";
        }
    }
    else
    {
        if (1 <= latter && latter <= 12)
        {
            ans = "YYMM";
        }
        else
        {
            ans = "NA";
        }
    }

    cout << ans << endl;

    return 0;
}