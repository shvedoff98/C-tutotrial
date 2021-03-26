#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

int main()
{
    int i,j;
    srand((unsigned)time(NULL));

    for(i=0;i<10;i++)
    {
        j = rand()%50+1;
        cout<<"Random Number : " << j <<endl;
    }

    return 0;
}
