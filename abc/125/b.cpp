#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int n;
    cin >> n;

    vector<int> values(n);
    vector<int> costs(n);
    for (size_t i = 0; i < n; i++)
    {
        cin >> values[i];
    }
    for (size_t i = 0; i < n; i++)
    {
        cin >> costs[i];
    }

    int max = 0;
    for (size_t i = 0; i < n; i++)
    {
        if (values[i] > costs[i])
        {
            max += values[i] - costs[i];
        }
    }

    cout << max << endl;
}
