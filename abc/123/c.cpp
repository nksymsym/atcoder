#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;

int main()
{
    ll n;
    vector<ll> tran(5);
    vector<pair<ll, int>> index(5);
    cin >> n;
    for (int i = 0; i < 5; i++)
    {
        cin >> tran[i];
        index[i] = make_pair(tran[i], i);
    }

    //ボトルネックから先は全員最短時間で移動できる
    //ボトルネックまでは先頭が到達してから最後が到達するまでに空で輸送されることはない
    sort(index.begin(), index.end());
    int bn = index[0].second;

    ll ans = 0;
    for (int i = 0; i < 5; i++)
    {
        if (i != bn)
        {
            ans += 1;
        }
        else
        {
            ans += (n + tran[i] - 1) / tran[i];
        }
    }

    cout << ans << endl;

    return 0;
}
