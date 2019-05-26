#include <iostream>
using namespace std;

int main()
{
    int a, p;
    cin >> a >> p;

    int maxP = a * 3 + p;
    int max = maxP / 2;

    cout << max << endl;

    return 0;
}
