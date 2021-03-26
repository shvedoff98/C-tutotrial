#include <iostream>

using namespace std;

template<typename Type>
Type _min(Type a, Type b)
{
    return a < b ? a:b;
}

template <typename T>
void print (const T& arg)
{
    cout << arg << endl;
}
template <typename T, typename... Types>
void print (const T& firstArg, const Types&... args)
{
    cout << firstArg << endl; // print first argument
    print(args...);
// call print() for remaining arguments
}

int main(int argc, char** argv)
{
    print (7.5, "hello");
    cout << _min(1, 2) << "\n";
    cout << _min(3.1, 1.2) << "\n";
    return 0;
}
