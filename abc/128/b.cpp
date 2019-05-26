#include <iostream>
#include <string>
#include <tuple>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;

    vector<tuple<string, int>> r(n);
    vector<int> idx(n);
    for (size_t i = 0; i < n; i++)
    {
        string s;
        int p;
        cin >> s >> p;
        r[i] = make_tuple(s, p);
        idx[i] = i;
    }

    for (size_t i = 0; i < n; i++)
    {
        for (size_t j = i; j < n; j++)
        {
            if (get<0>(r[i]) > get<0>(r[j]))
            {
                tuple<string, int> tmp = r[j];
                r[j] = r[i];
                r[i] = tmp;
                int itmp = idx[j];
                idx[j] = idx[i];
                idx[i] = itmp;
            }
            else if (get<0>(r[i]) == get<0>(r[j]) &&
                     get<1>(r[i]) < get<1>(r[j]))
            {

                tuple<string, int> tmp = r[j];
                r[j] = r[i];
                r[i] = tmp;
                int itmp = idx[j];
                idx[j] = idx[i];
                idx[i] = itmp;
            }
        }
    }

    for (size_t i = 0; i < n; i++)
    {
        cout << idx[i] + 1 << endl;
    }

    return 0;
}
