#include <iostream>
using namespace std;
typedef unsigned long long ull;
ull sum_of_natural(unsigned int x)
{
    ull sum = 0;
    for (int i=0; i<=x; ++i)
    { 
        if (i % 3 ==0 || i % 5 == 0) { sum += i; }
    }

    return sum;
}

int main(int argc, char* argv[])
{
    for (int x; cin >> x; )
    {
        cout << "Sum of all natural"
                "numbers % 3 and 5: " 
            << sum_of_natural(x) << "\n";
    }
    cout << "\n";
}
