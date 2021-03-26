/*90% of the time you should use std::fill instead of memset.
This is because std::fill will work correctly with classes,
and it will also work when setting arrays of non-byte types to a non-zero value.
For example, you can memset an array of ints to 0 but
you can't memset an array of ints to 0x12345678. With std::fill you can.
Good compilers can optimize std::fill to a memset where suitable.
In the cases they don't, any performance impact is likely to be negligible.
Using std::fill when a memset would be faster isn't dangerous.
Using memset where std::fill should have been used is dangerous. Default to std::fill.
Ditto for memcpy and std::copy*/

#include <iostream>
#include <string>
#include <algorithm>
#include <cstring>
#include <cstdint>

using namespace std;

void test_func(void)
{
    char prime[] = "WOW MOTHERFUCKER";
    memset(prime,'-',sizeof(prime));
    for(auto i=0; i<sizeof(prime); ++i)
    {
        cout << prime[i] << " ";
    }
    cout << "\n";
}

void test_fill(uint64_t n)
{
    string prime = "WOW MOTHERFUCKER";
    fill(prime.begin(),prime.begin()+n,'-');
    for (auto x : prime){cout << x << " ";}
    cout << "\n";

}

int main(int argc, char** argv)
{
    uint64_t x; cin >> x;
    test_func();
    test_fill(x);
    return 0;
}
