#include <iostream>
using namespace std;

void skip_to_int()
{
    if (cin.fail())
    {
        cin.clear();
        for (char ch; cin >> ch; )
        {
            if (isdigit(ch) || ch == '-')
            {
                cin.unget();
                return;
            }
        }
    }
    perror("No input!");
}



int main(int argc, char* argv[])
{
    cout << "Enter the integer number from 1 to 10:\n";
    int n = 0;
    while (true) 
    {
        if (cin >> n) 
        {
            if (1<=n && n<=10) break;
            cout << "Out-of-range error bound...\n";
        }
        else {
            cout << "Sorry, it is not a number!\n Try again!\n";
            skip_to_int();
        }
    }
}
