#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;
typedef long long ll;

int main()
{
    int n, k;
    cin >> n >> k;

    string s;
    cin >> s;

    ll mx = 0;
    queue<ll> q;
    q.push(0);
    for (ll i = 0; i < n; i++)
    {
        //0から1に変わるiをpush
        while (i < n && s[i] == '0')
        {
            i++;
        }
        if (i != 0)
        {
            q.push(i);
        }

        //1から0に変わるiについて、最大値を確認
        while (i < n && s[i] == '1')
        {
            i++;
        }
        if (q.size() > k + 1)
        {
            //k回しか処理できないので、先頭を捨てる
            q.pop();
        }
        ll first = q.front();
        ll length = i - first;
        mx = max(length, mx);
    }

    cout << mx << endl;

    return 0;
}
