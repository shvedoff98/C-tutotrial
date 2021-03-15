#include <vector>
#include <algorithm>
#include <iterator>
#include <cassert>
#include <cstdlib>
#include <exception>
#include <ctime>
#include <iostream>
using namespace std;

int at_test(long& n)
{
    srand((unsigned)time(NULL));
    vector <int> vec(n,0);

    for (int i=0; i<vec.size(); ++i)
    {
        int temp = rand()%50+1;
        vec[i] = temp;
    }

    for (auto x : vec){cout << x << " ";}

    int i; cout << "\nEnter the index of vector to access: ";
    cin >> i;
    // IF VECTOR<T>.. IS NOT EMPTY, THEN THERE IS NO DIFFERENCE BETWEEN
    // VEC.AT(i) AND VEC[i].
    // HOWEVER IF THIS VECTOR WAS EMPTY THOUGH, EXCEPTION WOULD SHOW UP:
    // STD::OUT_OF_RANGE.
    try {
        if (i > vec.size()) throw 404;
    } catch (int e){
        cout << "ERROR_OUT_OF_BOUND" << "\n";
        return 1;
    }

    cout << vec.at(i) << "\n";
    return vec.at(i);
    // use vector<T>::at() method instead of just []
}

int assert_test(void)
{
    vector<int> v;
    v.reserve( 2 );
    // HERE BELOW WE SEE UNNECCESSERY CHECKING
    // THE CAPACITY OF VECTOR V BECAUSE STL SAYS THAT
    // CONTAINER VECTOR'S CAPACITY IS GROWING EXPONENTIALLY
    // SO THERE IS NO NEED FOR CHECKING IF VECTOR IS OF NEEDED SIZE
    
    assert(v.capacity() == 2);

    //NO NEED IN ASSERT(). IN CASE YOU
    // WRITE >= INSTEAD ==. BECAUSE VECTOR NORMALLY ADDS AUTOMATICALLY
    // THE EXTRA SIZE SO IT SHOULD BE ALWAYS DYNAMICALLY.

    v[0] = 1;
    v[1] = 2;
    
    //REMEMBER THE DIFFERENCE BETWEEN SIZE/RESIZE AND CAPACITY/RESERVE

    for(vector<int>::iterator i = v.begin(); i<v.end(); ++i)
    {
        cout << *i << "\n";
    }//PRINT NOTHING BECAUSE VECTOR IS EMPTY 
    
    v.reserve(100);
    assert(v.capacity() == 100);

    v[2] = 3;
    v[3] = 4;
    //...
    for (vector<int>::iterator i = v.begin(); i<v.end(); ++i)
    {
        cout << *i << "\n";
    }//PRINT NOTHIN BECAUSE VECTOR IS EMPTY
    
    return 0;

}

int main(int argc,char** argv)
{
    if (argc < 2)
    {
        fprintf(stderr, "Too few arguments \n");
        return 1;
    }

    long arg = strtol(argv[1], NULL, 10);
    at_test(arg);
    assert_test();
    return 0;
}
