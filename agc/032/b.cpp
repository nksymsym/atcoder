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
    int n;
    cin >> n;
    int sb = (n % 2 == 0) ? n + 1 : n;
    vi a, b;
    for (int i = 1; i < n + 1; i++)
    {
        for (int j = i + 1; j < n + 1; j++)
        {
            if (i + j != sb)
            {
                a.push_back(i);
                b.push_back(j);
            }
        }
    }
    cout << a.size() << endl;
    for (size_t i = 0; i < a.size(); i++)
    {
        cout << a[i] << " " << b[i] << endl;
    }

    return 0;
}
