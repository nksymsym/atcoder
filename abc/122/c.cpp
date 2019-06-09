#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int n, q;
    cin >> n >> q;

    string s;
    cin >> s;

    vector<int> l(q);
    vector<int> r(q);
    for (int i = 0; i < q; i++)
    {
        int lin, rin;
        cin >> lin >> rin;
        lin--;
        rin--;
        l[i] = lin;
        r[i] = rin;
    }

    vector<int> c(n);
    int cnt = 0;
    char prev = '*';
    for (int i = 0; i < n; i++)
    {
        char current = s[i];
        if (prev == 'A' && current == 'C')
        {
            cnt++;
        }
        c[i] = cnt;
        prev = current;
    }

    for (int i = 0; i < q; i++)
    {
        int ans = c[r[i]] - c[l[i]];
        cout << ans << endl;
    }

    return 0;
}
