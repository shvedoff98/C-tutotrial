#include <iostream>
#include <cctype>
#include <numeric>
#include <vector>
#include <string_view>
#include <algorithm>
using namespace std;

bool ISBN_validator(string_view isbn)
{
    vector<int>digits;
    bool valid = false;
    if (isbn.size() == 10 && count_if(begin(isbn), end(isbn), static_cast<int(*)(int)>(isdigit)) == 10 )
    {
        auto w = 10;
        auto sum = accumulate(begin(isbn), end(isbn), 0, [&w]
                (int const total, char const c) 
                { return total + w-- * (c - '0'); });
        valid = !(sum % 11);
    }
    return valid;
}

int main(int argc, char* argv[])
{
    cout << "Enter the ISBN to validate: ";
    string isbn; cin >> isbn;
    cout << ISBN_validator(isbn) << "\n";
}

