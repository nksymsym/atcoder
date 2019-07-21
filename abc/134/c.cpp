#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>
using namespace std;
typedef vector<int> vi;
typedef pair<int, int> pr;
typedef vector<pr> vpr;
typedef long long ll;

int main()
{
    int n;
    cin >> n;
    int max1 = 0;
    int max2 = 0;
    int maxid = -1;
    for (int i = 0; i < n; i++)
    {
        int a;
        cin >> a;
        if (max1 < a)
        {
            max2 = max1;
            max1 = a;
            maxid = i;
        }
        else if (max2 < a)
        {
            max2 = a;
        }
    }

    for (int i = 0; i < n; i++)
    {
        if (i == maxid)
        {
            cout << max2 << endl;
        }
        else
        {
            cout << max1 << endl;
        }
    }

    return 0;
}
