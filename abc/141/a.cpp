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
    string ans = "";
    if (s == "Sunny")
    {
        ans = "Cloudy";
    }
    else if (s == "Cloudy")
    {
        ans = "Rainy";
    }
    else
    {
        ans = "Sunny";
    }
    cout << ans << endl;
    return 0;
}