#include <iostream>
#include <functional>
#include <algorithm>


// implementing recursion of compilation time
// ----->  goes to calling of oberloaded functions

template <typename T>
T minimum(T const a, T const  b) { return ( a < b ) ? a : b; }

template <typename T1, typename... T>
T1 minimum(T1 a, T... argc)
{
    return minimum(a, minimum(argc...));
}

template <class Compare, typename T>
T minimuc(Compare comp, T const a, T const b)
{ return comp(a, b) ?  a : b; }

template <class Compare, typename T1, typename... T>
T1 minimuc(Compare comp, T1 a, T... argc)
{
    return minimuc(comp, a, minimuc(comp, argc... ));
}

int main (int argc, char* argv[])
{
    auto x = minimuc(std::less<>(), 5 ,4, 2, 3);
    std::cout << x << "\n";
}
