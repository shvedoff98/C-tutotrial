#include <iostream>
#include <exception>

using namespace std;

int main()
{
    try
    {
        int * my_arr = new int[1000];
    } catch (exception& e) {
        cout << "Standard exception: " << e.what() << "\n";
    }

    try
    {
        int x,y;
        cout << "Enter the value of x and y: " << "\n";
        cin >> x >> y;
        if(x > y) throw 404;
        
    } catch (int e) {
        cout << "Standard exception: " << e << "\n";
    }
    return 0;
}
