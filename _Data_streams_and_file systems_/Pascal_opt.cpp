// This program prints Pascal's triangle up to 10 levels.

#include <cmath>
#include <iostream>
#include <string>
using namespace std;

unsigned int number_of_digits(unsigned long long const i)
{
    return i > 0 ? (int)log10((double)i) + 1 : 1;
}

void print_pascal_triangle(long long const n)
{
    for (int i=0; i < n; ++i)
    {
        auto x = 1;
        cout << string ((n - i - 1) * (n / 2), ' ');
        for (int j = 0; j <= i; ++j)
        {
            auto y = x;
            x = x * (i - j) / (j + 1);
            auto maxlen = number_of_digits(x) - 1;
            cout << y << string(n - 1 - maxlen - n%2, ' ');
        }
        cout << "\n";
    }
}


int main(int argc, char* argv[])
{
    int n = 0;
    cout << "Levels (up to 10): ";
    cin >> n;
    if (n > 10) { cout << "Number of levels too large!" << "\n"; }
    else { print_pascal_triangle(n); }
}
