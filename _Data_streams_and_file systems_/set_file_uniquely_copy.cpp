/* Program of how to uniquely copy the conten of the input file
   into another by using container std::set
   and istream(ostream)_iterator<T> */
#include <iostream>
#include <set>
#include <fstream>
#include <iterator>
using namespace std;

int main(int argc, char* argv[])
{
    string from, to;
    cin >> from >> to; // type in the input file and output

    ifstream is{from}; // redirect them into the input file stream
    ofstream os{to}; // and output file stream

    set <string> b {istream_iterator<string>{is},
                   istream_iterator<string>{} }; // fill set with the content of the input file stream

    copy(b.begin(), b.end(), ostream_iterator<string>{os, " "}); // copy the set<string>n into the output
                                                                 // file by using ostream_iterator<T>,
                                                                 // output file os and
                                                                // delimeter " "
}
