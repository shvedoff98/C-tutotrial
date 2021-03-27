#include <iostream>
#include <vector>
#include <iomanip>
#include  <string>
#include <cmath>
using namespace std;

void armstrong_number(int const limit)
{
    vector<int>digits;
    cout << setw(2) << "| ARM_NUMBER |" << setw(10) << "| DIGITS |" << "\n";
    for (int i=2; i<=limit; ++i)
    {
        string str = to_string(i); // convert to string
        int len_str = str.size(); // get the length of the str
        int sum_digits = 0; 
        for (int j=0; j<len_str; ++j)
        {
            int temp = stoi(string(1, str[j]));
            auto x = pow(temp,len_str);
            digits.push_back(x);
            sum_digits += x;
        }
        if (sum_digits == i)
        {
            cout << setw(7) << i << setw(10);
            for (int k=0; k<len_str; ++k)
            {
                cout << str[k] << "^" << len_str << " ";
            }
            cout << "\n";
        }
        digits.clear();
        
    }
}

int main(int argc, char* argv[])
{
    cout << "Enter the limit: ";
    int limit; cin >> limit; cout << "\n";
    armstrong_number(limit);
}
