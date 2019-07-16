#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>
#include <map>
using namespace std;
typedef pair<const int, int> pr;
typedef map<int, int> mp;

int main()
{
    int n;
    cin >> n;
    mp cnt;
    int idxCnt = 0;
    for (int i = 0; i < n; i++)
    {
        int a;
        cin >> a;
        if (cnt.find(a) == cnt.end())
        {
            cnt[a] = 1;
            idxCnt++;
        }
        else
        {
            cnt[a]++;
        }
    }

    string ans = "No";
    if (idxCnt == 3)
    {
        vector<pr> elm;
        for (auto c : cnt)
        {
            elm.push_back(pr(c.first, c.second));
        }
        if ((elm[0].first ^ elm[1].first) == elm[2].first &&
            elm[0].second == elm[1].second &&
            elm[0].second == elm[2].second)
        {
            ans = "Yes";
        }
    }
    else if (idxCnt == 2)
    {
        vector<pr> elm;
        for (auto c : cnt)
        {
            elm.push_back(pr(c.first, c.second));
        }
        if ((elm[0].first ^ elm[1].first) == elm[1].first &&
            elm[0].second * 2 == elm[1].second)
        {
            ans = "Yes";
        }
        if ((elm[0].first ^ elm[1].first) == elm[0].first &&
            elm[0].second == elm[1].second * 2)
        {
            ans = "Yes";
        }
    }
    else if (idxCnt == 1)
    {
        for (auto c : cnt)
        {
            if (c.first == 0)
            {
                ans = "Yes";
            }
        }
    }

    cout << ans << endl;

    return 0;
}
