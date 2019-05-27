#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;

    int l, r;
    int lmax = 1;
    int rmin = n;
    for (size_t i = 0; i < m; i++)
    {
        cin >> l >> r;
        lmax = max(l, lmax);
        rmin = min(r, rmin);
    }

    int ans = rmin - lmax + 1;
    if (ans < 0)
    {
        ans = 0;
    }

    cout << ans << endl;

    return 0;
}
