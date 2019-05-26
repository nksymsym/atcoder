#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void subBin(string str, int n);
bool contains(vector<int> vec, int number);

vector<string> perm;
int idx;

int main()
{
    int n, m;
    cin >> n >> m;

    vector<int> k(m);
    vector<vector<int>> s(m);
    for (size_t i = 0; i < m; i++)
    {
        cin >> k[i];

        vector<int> si(k[i]);
        for (size_t j = 0; j < k[i]; j++)
        {
            cin >> si[j];
        }
        s[i] = si;
    }

    vector<int> p(m);
    for (size_t i = 0; i < m; i++)
    {
        cin >> p[i];
    }

    //n個のスイッチについて、on(1)/off(0)の組み合わせ
    vector<string> tmp(2 << (n - 1));
    perm = tmp;
    idx = 0;
    subBin("", n);

    int cnt = 0;
    for (size_t i = 0; i < 2 << (n - 1); i++)
    {
        bool light = true;
        for (size_t j = 0; j < m; j++)
        {
            int scnt = 0;
            for (size_t k = 0; k < perm.size(); k++)
            {
                if (contains(s[j], k + 1) && perm[i][k] == '1')
                {
                    scnt++;
                }
            }
            if (scnt % 2 != p[j])
            {
                //cout << j << " " << p[j] << " " << perm[i] << endl;
                light = false;
                break;
            }
        }
        if (light)
        {
            //cout << perm[i] << endl;
            cnt++;
        }
    }

    cout << cnt << endl;

    return 0;
}

bool contains(vector<int> vec, int number)
{
    auto itr = find(vec.begin(), vec.end(), number);
    size_t index = distance(vec.begin(), itr);
    if (index != vec.size())
    {
        return true;
    }
    else
    {
        return false;
    }
}

void subBin(string str, int n)
{
    if (n == 0)
    {
        //cout << str << endl;
        perm[idx] = str;
        idx++;
    }
    if (n > 0)
    {
        subBin(str + "0", n - 1);
        subBin(str + "1", n - 1);
    }
}
