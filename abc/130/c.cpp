#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>
#include <iomanip>
using namespace std;
typedef long long ll;

int main()
{
    ll w, h, x, y;
    cin >> w >> h >> x >> y;

    string s = to_string(w * h / 2);
    if (w * h % 2 != 0)
    {
        s += ".5";
    }

    int way = 0;
    if (x * 2 == w && y * 2 == h)
    {
        way = 1;
    }

    cout << s << " " << way << endl;

    return 0;
}
