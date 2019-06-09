#include <iostream>
#include <string>
using namespace std;

int main()
{
    string b;
    cin >> b;

    for (size_t i = 0; i < b.length(); i++)
    {

        char in = b[i];
        if (in == 'A')
        {
            cout << 'T';
        }
        else if (in == 'C')
        {
            cout << 'G';
        }
        else if (in == 'G')
        {
            cout << 'C';
        }
        else if (in == 'T')
        {
            cout << 'A';
        }
    }
    cout << endl;

    return 0;
}
