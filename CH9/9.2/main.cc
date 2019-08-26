///一行代码求两个数的最大公约数
#include <iostream>

using namespace std;

int gcd(int m, int n){
    return n == 0? m: gcd(n, m%n);
}

int main(){
    
}