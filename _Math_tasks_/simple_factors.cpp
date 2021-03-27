#include <iostream>
#include <cmath>
#include <iterator>
#include <algorithm>
#include <vector>
using namespace std;

vector<unsigned long long> factors (unsigned long long num)
{
    vector <unsigned long long> factors;
    while (num % 2 == 0)
    {
        factors.push_back(2);
        num = num / 2;
    }

    for (unsigned long long i=3; i<sqrt(num); i += 2)
    {
        while (num % i == 0)
        {
            factors.push_back(i);
            num /= i;
        }
    }

    if (num > 2) { factors.push_back(num); }
    return factors;
}

int main(int argc, char* argv[])
{
    unsigned long long num = 0;
    cout << "Enter the number: ";
    cin >> num;

    auto x = factors(num);
    copy(begin(x), end(x) ,ostream_iterator<unsigned long long>(cout, " "));
}
