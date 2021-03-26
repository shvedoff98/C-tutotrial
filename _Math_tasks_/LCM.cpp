#include <iostream>
using namespace std;

unsigned int gcd(int const a, int const b)
{
    return b == 0 ? a : gcd(b, a % b);
}

int lcm(int const a, int const b)
{
    int h = gcd(a,b);
    return h ? (a* (b / h)) : 0;
}

int main(int argc, char* argv[])
{
    int a,b; cin >> a >> b;
    cout << "Lcm of two numbers is: ";
    cout << lcm(a,b) << "\n";
}
