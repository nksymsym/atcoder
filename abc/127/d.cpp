#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;

    vector<int> a(n);
    for (size_t i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    vector<pair<int, int>> cb(m);
    for (size_t i = 0; i < m; i++)
    {
        int b, c;
        cin >> b >> c;
        cb.push_back(make_pair(c, b));
    }

    sort(a.begin(), a.end());
    sort(cb.begin(), cb.end());

    auto itr = prev(cb.end());
    int alt = itr->first;
    int cnt = itr->second;
    long long sum = 0LL;
    for (size_t i = 0; i < n; i++)
    {
        if (a[i] < alt)
        {
            sum += alt;
            --cnt;
            if (alt != 0 && cnt == 0)
            {
                if (itr == cb.begin())
                {
                    alt = 0;
                }
                else
                {
                    itr = prev(itr);
                    alt = itr->first;
                    cnt = itr->second;
                }
            }
        }
        else
        {
            sum += a[i];
        }
    }

    cout << sum << endl;

    return 0;
}
