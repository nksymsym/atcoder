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
    int a, b;
    cin >> a >> b;

    int x, y;
    if (a < b)
    {
        x = a;
        y = b;
    }
    else
    {
        x = b;
        y = a;
    }

    for (int i = 0; i < y; i++)
    {
        cout << x;
    }
    cout << endl;

    return 0;
}
