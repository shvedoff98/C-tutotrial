#include <iostream>


template <int T>
struct Factorial
{
	static const int value = T * Factorial <T-1>::value;
};

template <>
struct Factorial <0>	
{
	static const int value = 1;
};

int main(int argc, char* argv[])
{
	int x = Factorial<4>::value;
	std::cout << x << "\n";
}
