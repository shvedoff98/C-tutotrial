// Simple hand-made algorithm of how to print
// Pascal's triangle in C++ with  O(n^2) speed.
// The actual formula is
// (n/k) =  n! / k! * (n-k)!

// You can run this code on youw computer just by compiling it with C++11 or higher


#include <iostream>
#include <iomanip>
#include <vector>
using namespace std;

vector<vector<int>> pascal(int num)
{
    int temp, temp2;

    vector <vector<int>> result {{1,1}};
    vector <int> vec2, vec {1,1};

    for (int i=0; i<num; ++i)
    {
        vec2.push_back(vec[0]);
        for (int j = 0; j < vec.size(); ++j)
        {
            if (j == vec.size()-1) { break; }
            temp = vec[j] + vec[j+1];
            vec2.push_back(temp);
        }
        vec2.push_back(vec.at(vec.size()-1));
        result.push_back(vec2);
        vec.resize(vec2.size());
        vec = vec2; vec2 = {};
    }

    for (auto x : vec2) { cout << x << " "; }
    cout << "\n";
    return result;

}

int main(int argc, char* argv[])
{
    cout << "Enter the number of raws of Pascal's triangle to print:  ";
    int num,count,n=0; cin >> num;
    count = num+10;
    vector <vector<int>> result = pascal(num);

    for (auto it = begin(result); it != end(result); ++it)
    {
        ++n;
        if (n % 12 == 0) { cout << setw(count); }
        if (n % 5 == 0) { cout << setw(--count); }
        if (n % 10 == 0) { cout << setw(count -= 2); }
        else { cout << setw(count); }

        for (auto jt = it->begin(); jt != it->end(); ++jt)
        {
            cout << *jt << " ";
        }
        --count;
        cout << "\n";
    }
}

