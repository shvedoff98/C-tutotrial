//#include <bits/stdc++.h>
#include <iostream>
#include <vector>

using namespace std;
//#define F first()
//#define S second()
#define PB push_back
#define MP make_pair
#define REP(i,a,b) for (int i = a; i <= b; i++)


typedef vector <int> vi;
typedef pair <int,int> pi;


int main()
{   vi x;
    int a=0,b=1,sum=0;
    REP(i,1,10)
    {   
        x.PB(a++);
        //cout << x[i].F << " " << x[i].S << " " << sum << "\n";
    }

    for(auto it = x.begin(); it != x.end(); ++it)
    {
        cout << *it << " ";
    }
    cout << "\n";
    return 0;
}
