#include <iostream>

using namespace std;

void counter(){
    static unsigned int count = 0;
    cout<<count++<<" "<<"The size is"<<sizeof(count)<<"\n";
}

int main(){
    int i;
    for(i=0;i<10;++i){
        counter();
    }
    return 0;
}
