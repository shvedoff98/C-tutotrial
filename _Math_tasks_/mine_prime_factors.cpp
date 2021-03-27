#include <iostream>
#include <vector>
#include <iterator>
#include <cmath>
using namespace std;

vector<int>factors(unsigned long long n)
{
    vector<int>factors;
    while (n % 2 == 0)
    {
        factors.push_back(2);
        n /= 2;
    }

    for (int i=3; i<sqrt(n); i+=2)
    {
        while (n % i == 0)
        {
            factors.push_back(i);
            n /= i;
        }
    }

    if ( n > 2 ){ factors.push_back(n); }
    return factors;
}

int main(int argc, char* argv[])
{
    cout << " Enter the number: ";
    unsigned long long num; cin >> num;

    auto prime = factors(num);
    ostream_iterator<int> out (cout, ", ");

    copy (begin(prime), end(prime), out);
}
