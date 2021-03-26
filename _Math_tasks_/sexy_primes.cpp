#include <iostream>
#include <utility>
#include <cmath>
#include <map>
using namespace std;


//Check if PRIME: 

bool is_prime(int const a)
{
    for (int i=2; i<sqrt(a); ++i)
    {
        if ( a % i == 0 ) { return false; }
    }
    return true;
}

//Check the difference between 2 prime numbers. 
//If is 6 -> true;

bool dif(const int a, const int b)
{
    if ( abs(a - b) != 6) { return false; }
    return true;
}

//Algorithm how to fill map<int, int> with
//pairs of prime which differs from each other on 6;

map<int,int> sexy_prime(int const num)
{
    map<int,int> s_p;
    map<int,int>::iterator it = s_p.begin();
    int second_pr = 5;
    for (int i=5; i < num; ++i)
    {
        if (is_prime(i) && dif(i,second_pr)) 
        {
            s_p.insert(pair<int,int> (second_pr,i));
        }

        if ((i - second_pr) > 6 && is_prime(i)) {second_pr = i;}
    }

    for (it=s_p.begin(); it!=s_p.end(); ++it)
    {
        cout << it->first << " " << it->second << "\n";
    }

    return s_p;

}

//Drive code

int main(int argc, char* argv[])
{
    cout << "Enter the number to check all sexy prime numbers up to it: ";
    int num; cin >> num;
    sexy_prime(num);

}
