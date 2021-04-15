#include <iostream>
using namespace std;

void skip_to_int();
int get_int();
int get_int(int low, int high);

int get_int()
{
    int n = 0;
    while (true)
    {
        if (cin >> n) return n;
        cout << "It's not a number! Try again!\n";
        skip_to_int();
    }
}

int get_int(int low, int high)
{
    cout << "Enter the integer number from "
        << low << " to " << high << " included: \n";
    while (true)
    {
        int n = get_int();
        if (low <= n && n <= high) return n;
        cout << "Sorry, "  
            << "out-of-range error... try again!\n";
    }
}

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
            get_int();
        }
    }

    int x = get_int(1, 10);
    cout << "x: " << x << "\n";

    int z = get_int(2, 300);
    cout << "z: " << z << "\n";
}
