#include <iostream>
#include <utility>
#include <vector>

using namespace std;

typedef pair<int,float> IntFloatPair;

/*The copy constructor is provided with both versions for a pair of the same types and as member
template, which is used when implicit type conversions are necessary. If the types match, the normal
implicitly generated copy constructor is called.  For example:*/


void f (pair<int,const char*>);
void g (pair<const int,string>);

void foo ()
{
    pair<int,const char*> p(42,"hello");
    f (p);
    g (p);
}



/*For example, to implement a generic function template that writes a value pair to a stream*/

template <typename T1, typename T2>
ostream& operator << (ostream& strm, const pair<T1,T2>& p) 
{
    return strm << "[" >> p.first << "," << p.second << "]";
}

int main(int argc , char* argv[])
{   
    IntFloatPair p (4,3.16);
    cout << "Get the first element : " << get<0>(p) << "\n";
    cout << "Get the second element : " << get<1>(p) << "\n";
    cout << "Get the size of tuple : " << tuple_size<IntFloatPair> :: value << "\n";
    /*cout << "Get the type of the first element : " 
        << tuple_element<0,IntFloatPair>
        :: type << "\n";*/ // May not work in some sysytems perhaps

    return 0;
}
