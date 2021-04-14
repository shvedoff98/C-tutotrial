#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

struct Reading {
    int hour;
    double temperature;
};

int main(int argc, char* argv[])
{
    cout << "Enter the input file's name: ";
    string iname; cin >> iname;

    ifstream ist {iname};
    if (!ist) { perror("Error occured while opening input file..."); }

    cout << "Enter the output file's name: ";
    string oname; cin >> oname;

    ofstream ost {oname};
    if(!ost) { perror("Error ocured while opening destination file..."); }


    vector<Reading> temps;
    int hour;
    double temperature;
    while(ist >> hour >> temperature) 
    {
        if (hour < 0 || 23 < hour) perror("Error");
        temps.push_back(Reading{hour, temperature});
    }

    for (int i=0; i<temps.size(); ++i)
    {
        ost << "(" << temps[i].hour << ", "
            << temps[i].temperature << ")\n";
    }
}
