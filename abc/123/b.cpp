#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
    vector<pair<int, int>> times(5);
    for (size_t i = 0; i < 5; i++)
    {
        int time, remainder;
        cin >> time;
        remainder = time % 10;
        times[i] = make_pair(remainder, time);
    }
    sort(times.begin(), times.end());

    int ans = 0;
    bool waitFlg = false;
    for (size_t i = 0; i < 5; i++)
    {
        ans += times[i].second;
        if (times[i].first != 0)
        {
            if (waitFlg)
            {
                ans += 10 - times[i].first;
            }
            else
            {
                waitFlg = true;
            }
        }
    }

    cout << ans << endl;

    return 0;
}
