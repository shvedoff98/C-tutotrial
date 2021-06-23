#include <algorithm>
#include <iostream>
#include <iterator>
#include <vector>


template <class C, class... Argc>
void push_back (C& c, Argc&&... argc)
{
    (c.push_back(argc), ...);
}

int main(int agrc, char* argv[])
{
    std::vector <int> vec {1, 2, 3, 4, 5, 6};
    push_back(vec, 7, 8, 9);
    std::copy(vec.begin(), vec.end(), std::ostream_iterator<int> (std::cout, " "));
}
