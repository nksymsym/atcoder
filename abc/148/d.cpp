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
    vi a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    int next = 1;
    int del = 0;
    for (int i = 0; i < n; i++)
    {
        if (a[i] == next)
        {
            next++;
        }
        else
        {
            del++;
        }
    }

    if (del == n)
    {
        del = -1;
    }

    cout << del << endl;

    return 0;
}