#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>
using namespace std;
typedef long long ll;

int main()
{
    int n, x;
    cin >> n >> x;
    vector<int> l(n);
    for (int i = 0; i < n; i++)
    {
        cin >> l[i];
    }

    int cnt = 1;
    int d = 0;
    for (int i = 0; i < n; i++)
    {
        d += l[i];
        if (d <= x)
        {
            cnt++;
        }
        else
        {
            break;
        }
    }

    cout << cnt << endl;
    return 0;
}
