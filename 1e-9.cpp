//C++ program to check if 2 double numbers are equal
//comparing with 1e-9.
//read stdin with while loop 
//then print these numbers with 4 digits after coma
//compare 2 inittial numbers by checking if absolute
//value of their subtraction is less than 1e.9(0.0000000001)

#include <bits/stdc++.h>
using namespace std;

int main(){
    double x,y; 
    while (cin >> x && cin >> y){
        printf("%.4f\n",x);
        printf("%.4f\n",y);
        if( abs(x-y) < 1e-9 ){cout << "OK" << "\n"; break;}
    }
    return 0;
    //code

}
