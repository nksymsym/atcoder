#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>
using namespace std;
typedef pair<int, int> pr;
typedef vector<pr> vpr;

int main()
{
    int n;
    cin >> n;

    vpr p(n);
    for (int i = 0; i < n; i++)
    {
        int pi;
        cin >> pi;
        p[i] = pr(pi, i);
    }

    sort(p.begin(), p.end());

    int cnt = 0;
    for (int i = 0; i < n; i++)
    {
        if (p[i].second != i)
        {
            cnt++;
        }
    }

    string ans;
    if (cnt == 0 || cnt == 2)
    {
        ans = "YES";
    }
    else
    {
        ans = "NO";
    }
    cout << ans << endl;

    return 0;
}
