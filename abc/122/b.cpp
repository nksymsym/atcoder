#include <iostream>
#include <string>
using namespace std;

int main()
{
    string s;
    cin >> s;

    int len = 0;
    int mx = 0;

    for (size_t i = 0; i < s.length(); i++)
    {
        char ch = s[i];
        if (ch == 'A' || ch == 'C' || ch == 'G' || ch == 'T')
        {
            len++;
        }
        else
        {
            if (len > mx)
            {
                mx = len;
            }
            len = 0;
        }
    }
    if (len > mx)
    {
        mx = len;
    }

    cout << mx << endl;

    return 0;
}
