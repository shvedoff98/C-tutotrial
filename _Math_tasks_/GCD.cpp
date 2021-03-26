#include <iostream>
using namespace std;
typedef unsigned long long ull;

unsigned int gcd(ull const a, ull const b)
{
    return b == 0 ? a : gcd(b, a % b);
}

int main(int argc, char* argv[])
{
    ll a = 105, b = 30;
    cout << gcd(a,b);
    cout << "\n";
}
