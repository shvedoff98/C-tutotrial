#include <iostream>
using namespace std;
typedef long long ll;

int gcd(ll a, ll b)
{
    if (b == 0) {return a;};
    return gcd(b, a % b);
}

int main(int argc, char* argv[])
{
    ll a = 105, b = 30;
    cout << gcd(a,b);
    cout << "\n";
}
