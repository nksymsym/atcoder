#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>
using namespace std;
typedef pair<int, int> pr;
typedef vector<vector<pr>> vv;
typedef long long ll;

int main()
{
    int n, m;
    cin >> n >> m;

    vv city(n + 1);
    for (int i = 0; i < m; i++)
    {
        int p, y;
        scanf("%d %d", &p, &y);
        city[p].push_back(pr(y, i));
    }

    vector<ll> ans(m);
    for (int i = 0; i < n + 1; i++)
    {
        auto c = city[i];
        sort(c.begin(), c.end());
        for (int j = 0; j < c.size(); j++)
        {
            ans[c[j].second] = i * 1000000LL + j + 1;
        }
    }

    for (auto no : ans)
    {
        printf("%012lld\n", no);
    }

    return 0;
}
