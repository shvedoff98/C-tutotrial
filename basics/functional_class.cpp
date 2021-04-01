/* This is an example of how to create
 * and use functional class with operator()
 * so it should be easy to call STL algorithms
 * with third optional argument */

#include <iostream>
#include <cstring>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

struct Record {
    string name;
    char addr[24];
};

struct Cmp_by_name {
    bool operator() (const Record& a, const Record& b) const
    {
        return a.name < b.name; 
    }
};

struct Cmp_by_addr {
    bool operator() (const Record& a, const Record& b) const
    {
        return strncmp(a.addr, b.addr, 24) < 0;
    }
};

int main(int argc, char* argv[])
{
    vector <Record> vr;
    sort(vr.begin(), vr.end(), Cmp_by_name());
    sort(vr.begin(), vr.end(), Cmp_by_addr());
}
