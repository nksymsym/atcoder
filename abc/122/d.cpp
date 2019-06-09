#include <iostream>
#include <string>
#include <vector>
#include <map>
using namespace std;

int n;
map<string, bool> memo;
vector<map<string, long long>> cnt;
long long m = 1e9 + 7;

bool isOk(string src)
{
    if (memo.find(src) != memo.end())
    {
        return memo[src];
    }

    for (size_t i = 0; i < src.length() - 1; i++)
    {
        if (src.find("AGC") != string::npos)
        {
            return memo[src] = false;
        }

        string alt = src;
        alt[i] = src[i + 1];
        alt[i + 1] = src[i];
        if (alt.find("AGC") != string::npos)
        {
            return memo[src] = false;
        }
    }

    return memo[src] = true;
}

long long dfs(int pos, string base)
{
    if (pos == n)
    {
        return 1LL;
    }

    if (cnt[pos].find(base) != cnt[pos].end())
    {
        return cnt[pos][base];
    }

    long long tmp = 0;
    for (int i = 0; i < 4; i++)
    {
        char nx = "ACGT"[i];
        if (isOk(base + nx))
        {
            tmp += dfs(pos + 1, base.substr(1) + nx);
            tmp %= m;
        }
    }
    return cnt[pos][base] = tmp;
}

int main()
{
    cin >> n;
    cnt.resize(n + 1);
    cout << dfs(0, "***") << endl;

    return 0;
}
