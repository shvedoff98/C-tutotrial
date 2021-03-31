#include <iostream>
#include <list>
using namespace std;

template<typename Iter>

Iter high(Iter first, Iter last)
{
    Iter high = first;
    for (Iter p = first; p != last; ++p)
    {
        if ( *high < *p ) { high = p; }
    }
    return high;
}

void f()
{
    list<double> lst; for (double x; cin >> x;) 
    { 
        lst.push_front(x); 
        if (lst.size() == 10) {break;}
    }
    list<double>::iterator p = high(lst.begin(), lst.end());
    cout << "Max: " << *p << "\n";
}

int main(int argc, char* argv[])
{
    f();
}

