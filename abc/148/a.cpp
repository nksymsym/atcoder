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
    for (int i = 1; i <= 3; i++)
    {
        if (i != a && i != b)
        {
            cout << i << endl;
        }
    }

    return 0;
}