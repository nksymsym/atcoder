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
    ll a, b, n;
    cin >> a >> b;
    n = 1;
    for (ll i = 2; i <= a || i <= b; i++)
    {
        while (a % i == 0 || b % i == 0)
        {
            n *= i;
            if (a % i == 0)
            {
                a /= i;
            }
            if (b % i == 0)
            {
                b /= i;
            }
        }
    }
    cout << n << endl;

    return 0;
}