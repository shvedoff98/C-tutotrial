#include <iostream>
#include <iomanip>
#include <numeric>
#include <vector>
using namespace std;

void  excess_number(const int num)
{

    cout << "| excess_num" << " | | " << "Sum_of_div |" << " \n";
    int x = 1;
    vector <int> result;

    while(x<=num)
    {
        for (int i=1; i<=x/2; ++i)
        {
            if ( x % i == 0 ) { result.push_back(i); }
        }


        if (accumulate(result.begin(), result.end(),0) > x)
        {
            auto y = accumulate(result.begin(), result.end(), 0);
            cout << setw(7) << x << setw(12) << y << "-"
                << x <<  " = " << (y-x) << "\n";
        }
        result.clear();
        ++x;
    }
}

int main(int argc, char* argv[])
{
    cout << "Enter the number to derive all excess numbers up to it: ";
    int x; cin >> x;
    excess_number(x);
}
