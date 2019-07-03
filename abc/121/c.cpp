#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>
using namespace std;
typedef long long ll;
typedef vector<ll> vll;
typedef pair<ll, ll> pr;
typedef priority_queue<pr> pq;

int main()
{
    ll n, m;
    cin >> n >> m;

    vll a(n), b(n);
    pq q;
    for (ll i = 0; i < n; i++)
    {
        cin >> a[i] >> b[i];
        q.push(pr(-a[i], i));
    }

    ll money = 0;
    ll rest = m;
    while (rest > 0)
    {
        ll i = q.top().second;
        q.pop();

        ll price = a[i];
        ll amount = b[i];

        if (rest < amount)
        {
            amount = rest;
        }

        money += price * amount;
        rest -= amount;
    }

    cout << money << endl;

    return 0;
}