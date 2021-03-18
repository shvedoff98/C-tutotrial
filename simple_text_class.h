#include <iostream>
using namespace std;


struct X {
    int val;

    void out(const string&s, int nv)
    {
        cerr << this << "->" << s << ": "
            << val << " (" << nv << ")\n";
    }

    X() { out("X()", 0); val=0; }
    X(int v) { val=v; out( "X(int)", v); }

    X(const X& x) { val=x.val; out("X(X&) ", x.val); }
    X& operator=(const X& a)
    {
        out("X::operator=()", a.val);
        val=a.val; return *this;
    }

    ~X() { out("~X()", 0); }
};



