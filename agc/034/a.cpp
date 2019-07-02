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
    int n, a, b, c, d;
    cin >> n >> a >> b >> c >> d;
    string s;
    cin >> s;
    a--;
    b--;
    c--;
    d--;

    string ans;
    if (c < d)
    {
        ans = "Yes";
        bool block = false;
        for (int i = a + 1; i < d; i++)
        {
            if (s[i] == '#')
            {
                if (block && (i < c || b < i))
                {
                    ans = "No";
                    break;
                }
                else
                {
                    block = true;
                }
            }
            else
            {
                block = false;
            }
        }
    }
    else
    {
        ans = "Yes";
        bool block = false;
        bool over = false;
        int cnt = 0;
        for (int i = a + 1; i < c; i++)
        {
            if (s[i] == '#')
            {
                if (block)
                {
                    ans = "No";
                    break;
                }
                else
                {
                    block = true;
                }
            }
            else
            {
                block = false;
            }

            if (b - 1 <= i && i <= d + 1)
            {
                if (s[i] == '#')
                {
                    cnt = 0;
                }
                else
                {
                    cnt++;
                    if (cnt == 3)
                    {
                        over = true;
                    }
                }
            }
        }
        if (!over)
        {
            ans = "No";
        }
    }

    cout << ans << endl;
    return 0;
}