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

    ll ans = 0;
    ll cnt_a = 0;
    bool flg_a = false;
    bool flg_ab = false;
    for (size_t i = 0; i < s.length(); i++)
    {
        if (s[i] == 'A')
        {
            if (flg_a)
            {
                flg_a = true;
                flg_ab = false;
                cnt_a++;
            }
            else
            {
                flg_a = true;
                flg_ab = false;
                cnt_a = 1;
            }
        }
        else if (s[i] == 'B')
        {
            if (flg_a)
            {
                flg_a = false;
                flg_ab = true;
            }
            else
            {
                flg_a = false;
                flg_ab = false;
                cnt_a = 0;
            }
        }
        else if (s[i] == 'C')
        {
            if (flg_ab)
            {
                ans += cnt_a;
                flg_a = true;
                flg_ab = false;
            }
            else
            {
                flg_a = false;
                flg_ab = false;
                cnt_a = 0;
            }
        }
    }

    cout << ans << endl;
    return 0;
}