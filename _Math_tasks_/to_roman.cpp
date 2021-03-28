#include <vector>
#include <utility>
#include <iostream>
using namespace std;

string to_roman(signed long long num)
{
    string result;
    vector<pair<unsigned int, const char*>>roman {
        {1000, "M"}, {900, "CM"}, {500, "D"}, {400, "CD"},
        {100, "C"}, {90, "XC"}, {50, "L"}, {40, "XL"},
        {10 , "X"}, {9, "IX"}, {5, "V"}, {4, "IV"}, {1, "I"}
    };

    for (auto &x : roman)
    {
        while ( num >= x.first)
        {
            result += x.second;
            num -= x.first;
        }
    }
    return result;

}

int main(int argc, char* agrv[])
{
    signed long long num; cin >> num;
    cout << to_roman(num) << "\n";
}
