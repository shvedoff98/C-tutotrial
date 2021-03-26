#include <iostream>
#include <cmath>
using namespace std;

bool is_prime(const int a)
{
    for (int i=2; i<=sqrt(a); ++i)
    {
        if ( a % i == 0 ) 
        {
            return false;
        }
    }
    return true;
}


int prime(int const a)
{
    int highest = 0;
    for (int i=2; i<a; ++i)
    {
        if (is_prime(i) && i > highest) { highest = i; }
    }
    

    return highest;
}


int main(int argc, char* argv[])
{
    int a; cin >> a;
    cout << prime(a) << "\n";
}
