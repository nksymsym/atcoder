#include <iostream>
#include <vector>
#include <numeric>
using namespace std;

int gcd(int a, int b)
{
    if (a < b)
    {
        swap(a, b);
    }

    if (b == 0)
    {
        return a;
    }

    return gcd(b, a % b);
}

int main()
{
    int n;
    cin >> n;

    vector<int> numbers(n);
    for (size_t i = 0; i < n; i++)
    {
        cin >> numbers[i];
    }

    //自身を含めて左側、右側の数の最大公約数
    vector<int> left(n);
    vector<int> right(n);
    left[0] = numbers[0];
    right[n - 1] = numbers[n - 1];
    for (size_t i = 1; i < n; i++)
    {
        left[i] = gcd(left[i - 1], numbers[i]);
        right[n - i - 1] = gcd(right[n - i], numbers[n - i - 1]);
    }

    //自身を除いた左側、右側の数の最大公約数の最大公約数
    int m = 0;
    for (size_t i = 0; i < n; i++)
    {
        int g;
        if (i == 0)
        {
            g = right[i + 1];
        }
        else if (i == n - 1)
        {
            g = left[i - 1];
        }
        else
        {
            g = gcd(right[i + 1], left[i - 1]);
        }

        m = max(m, g);
    }

    cout << m << endl;
}
