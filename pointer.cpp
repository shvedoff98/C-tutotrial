#include <iostream>
#include <vector>
using namespace std;

void test(void)
{
    int x = 17;
    int* pi =  &x;

    double e = 2.71828;
    double* exp = &e;
    
    *exp = *pi;
    cout << *pi << "\n";
    cout << *exp << "\n";
    vector<int> v(1000);

    cout << "Размер vector<int>(1000) = "
        << sizeof (v) << "\n";
}


void pointer_arr(int n)
{
    double* arr = new double[n];
    //double temp = *arr; 
    //double temp2 = arr[2]; 
    *arr = 7.7; arr[2] = 9.9; 
    cout << *arr << " " << arr[2] << "\n";
    //temp  = arr[3];
    arr[3] = 4.4;
    cout << arr[3] << "\n";

    double* p4 = new double[5] {0,1,2,3,4};
    for (int i=0; i<5; ++i)
    {
        cout << p4[i] << " ";
    }
    cout << "\n";
}

void sizes(char ch ,  int i, int* pi, double f) 
{ 
    cout  << "размер типа char равен " << sizeof(char) 
        << " " << sizeof(ch) << "\n";
    cout  << "размер типа int равен " << sizeof (int)
        << " " << sizeof (i) << "\n" ; 
    cout << "размер типа int* равен " << sizeof(int*)
        << " " << sizeof(pi) << "\n" ;
    cout << "размер типа double павен " << sizeof (double)
        << " " << sizeof(f) << "\n";
}

int main(int argc, char* argv[])
{

    char ch = 'a';int i = 5;
    int y = 3 ;int* dp = &y;
    double f = 93.3;

    //sizes(ch,i,dp,f);
    //test();
    pointer_arr(5);

}
