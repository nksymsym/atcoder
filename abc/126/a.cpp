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
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;

    char c = s[k - 1];
    c = c - ('A' - 'a');
    s[k - 1] = c;
    cout << s << endl;

    return 0;
}