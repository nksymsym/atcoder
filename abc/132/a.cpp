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

    char c1 = s[0];
    char c2 = '*';
    int cnt1 = 1;
    int cnt2 = 0;
    for (int i = 1; i < 4; i++)
    {
        char c = s[i];
        if (c1 == c)
        {
            cnt1++;
        }
        else if (c2 == c)
        {
            cnt2++;
        }
        else
        {
            c2 = c;
            cnt2 = 1;
        }
    }

    if (cnt1 == 2 && cnt2 == 2)
    {
        cout << "Yes" << endl;
    }
    else
    {
        cout << "No" << endl;
    }

    return 0;
}
