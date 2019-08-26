///0左边必有1的二进制字符串数量
#include <iostream>
#include <string>

using namespace std;

int func(int n){
    if(n == 0) return 0;
    if(n == 1) return 1;
    if(n == 2) return 2;
    int total = 8;
    int a = 1, b = 2;
    int c;
    for(int i = 3; i <= n; ++i){
        c = b + a;
        b = c;
        a = b;
    }

    return c;
}

int main(){
    int ret = func(4);
    cout<<ret<<endl;
}