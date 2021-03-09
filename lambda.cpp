#include <iostream>
#include <string>

using namespace std;

auto l = [] { cout << "Hello lambda" << "\n"; };
auto k = [] (const string& s ) -> string { cout << s << "\n"; return s; };

int main()
{
    int x = 0, y = 42;
    auto qqq = [x, &y] { cout << "x: " << x << "\n";
                         cout << "y: " << y << "\n";
                         ++y;
                       };
    x = y = 77;
    qqq();
    qqq();
    cout << "final y: " << y << "\n";

    k("Fucking fuck");
    l();
    return 0;

}
