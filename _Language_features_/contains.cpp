#include <algorithm>
#include <iterator>
#include <vector>
#include <iostream>
#include <utility>


// SIMPLE TEMPLATE FUNCTIONS TO CHECK  ABSENSE 
// AND PRESENSE OF CONTAINER'S ELEMENTS


template <class C, class T>
bool contains (C& c, T&& val)
{
    return (std::end(c) != std::find(std::begin(c), std::end(c), std::forward<T>(val)));
}

template <class C, class... Argc>
bool contains_any (C& c, Argc&&... val)
{
    return (... || contains(c, val));
}

template <class C, class... Argc>
bool contains_all (C& c, Argc&&... val)
{
    return (... && contains(c, val));
}

template <class C, class... Argc>
bool misses_all (C& c, Argc&&... val)
{
    return (... && (std::end(c) == std::find(std::begin(c), std::end(c), val)));
}

template <class C, class... Argc>
bool misses_min_one (C& c, Argc&&... val)
{
    return (... || (std::end(c) == std::find(std::begin(c), std::end(c), val)));
}



int main(int argc, char* argv[])
{
    std::vector <int> vec {1, 2, 3, 4, 5, 6, 7, 8, 9};
    std::copy(begin(vec), end(vec), std::ostream_iterator<int> (std::cout, " "));
    auto var = contains (vec, 4);
    auto var_2 = contains_any (vec, 0, 10);
    auto var_3 = contains_all (vec, 4,5,6,7,8,9 );
    auto var_4 = misses_all (vec, 11);
    auto var_5 = misses_min_one (vec, 11, 9, 12);
    std::cout << "\n\n";

    std::cout << "contains (vec, 4):  " << var << "\n";
    std::cout << "contains_any (vec, 0, 10):  " << var_2 << "\n";
    std::cout << "contains_all (vec, 4, 5, 6, 7, 8, 9):  " << var_3 << "\n";
    std::cout << "messes_all (vec, 11):  " << var_4 << "\n";
    std::cout << "misses_min_one (vec, 11, 9, 12):  " << var_5 << "\n";

    exit(EXIT_SUCCESS);
}
