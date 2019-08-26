///从1到n中1出现的次数
#include <iostream>

using namespace std;

int getOneNum(int n){
    int sig = 10;
    int ret = 0;
    if(n % 10 > 0){
        ++ret;
    }

    while(n > sig){
        ret += n / sig;
        sig *= 10;
    }

    if(sig != 10){
        sig /= 10;
        ret += (n/sig) == 1? n - sig + 1: sig;
    }
    return ret;
    
}

int main(){
    int ret = getOneNum(100);
    cout<<ret<<endl;
}