#include <iostream>
#include <numeric>
#include <vector>
using namespace std;

int sum_proper_diviser(int const num)
{
    vector<int>divisers;
    for (int i=1; i<num; ++i)
    {
        if ( num % i == 0 ) { divisers.push_back(i); } 
    }
    return accumulate(divisers.begin(), divisers.end(), 0);
}

void amicables(int const limit)
{
    for (int i=4; i< limit; ++i)
    {
        auto sum1 = sum_proper_diviser(i);
        if (sum1 < limit)
        {
            auto sum2 = sum_proper_diviser(sum1);
            if ( sum2 == i && i != sum1 )
            {
                cout << i << "," << sum1 << "\n";
            }
        }
    }
}

int main(int argc, char* argv[])
{
    int limit; cin >> limit;
    amicables(limit);
}
