#include <iostream>
#include <ctime>

using namespace std;

typedef unsigned long ul;

void getSeconds(ul *p)
{
    *p = time(NULL);
    cout <<"Current time is: "<<*p/3600<<" hours ";
    cout<<"has passed since starting the age of programming!"<<endl;
}

int main()
{
    ul sec;
    getSeconds(&sec);
    return 0;
}

