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
    string s;
    cin >> s;
    string ans = "Yes";
    for (int i = 0; i < s.length(); i++)
    {
        if (i % 2 == 0 && s[i] == 'L')
        {
            ans = "No";
            break;
        }
        if (i % 2 == 1 && s[i] == 'R')
        {
            ans = "No";
            break;
        }
    }
    cout << ans << endl;
    return 0;
}