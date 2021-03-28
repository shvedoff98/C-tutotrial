#include <iostream>
#include <vector>
using namespace std;

pair<unsigned long long, long> collatz(unsigned long long const limit)
{
    long length = 0;
    unsigned long long number = 0;
    vector <int> cache(limit + 1, 0);

    for (unsigned long long i = 2; i <= limit; i++)
    {
        auto n = i;
        long steps = 0;
        while ( n != 1 && n >= i )
        {
            if (( n % 2 ) == 0) { n = n / 2; }
            else n = n * 3 + 1;
            steps++;
        }

        cache[i] = steps + cache[n];

        if ( cache[i] > length )
        {
            length = cache[i];
            number = i;
        }
    }
    cout << number << " " << length << "\n";
    return make_pair(number, length);
}


int main(int argc, char* argv[])
{
    cout << "Enter the limit: ";
    unsigned long long limit;
    cin >> limit;
    collatz(limit);
}
