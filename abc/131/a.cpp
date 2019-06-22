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

    string ans = "Good";
    char prev = ' ';
    for (size_t i = 0; i < s.length(); i++)
    {
        char current = s[i];
        if (prev == current)
        {
            ans = "Bad";
            break;
        }
        prev = current;
    }

    cout << ans << endl;

    return 0;
}