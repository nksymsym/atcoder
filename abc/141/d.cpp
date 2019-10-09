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
typedef priority_queue<int> pq;

int main()
{
    int n, m;
    cin >> n >> m;
    pq q;
    for (int i = 0; i < n; i++)
    {
        int a;
        cin >> a;
        q.push(a);
    }

    for (int i = 0; i < m; i++)
    {
        int mx = q.top();
        q.pop();
        mx /= 2;
        q.push(mx);
    }

    long sum = 0;
    for (int i = 0; i < n; i++)
    {
        int mx = q.top();
        q.pop();
        sum += mx;
    }

    cout << sum << endl;

    return 0;
}