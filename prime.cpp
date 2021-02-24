#include <cmath>
#include <iostream>
using namespace std;
bool isPrime(int a){
    if(a == 1) return false;
    for(int i=2;i<=sqrt(a);++i){
        if(a%i ==0){
            return false;
        }
    }
    return true;
}

int solve(int a,int b){
    int result = 0;
    for(int i=a;i<b;++i){
        int num = i;int sum = 0;
        while(num){
            sum += pow(num%10,2);
            num /= 10;
            if (!num){
                num = sum;
                sum = 0;
                if(num == 1) { result++;break;}
                else if (num < 10 && !isPrime(num)) break;
            }
        }
    }
    cout<<result<<endl;
    return result;
}
int main(){
    solve(100,1000);
    return 0;
}
