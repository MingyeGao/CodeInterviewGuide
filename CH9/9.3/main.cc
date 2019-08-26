///有关阶乘的两个问题
///1.求N!末尾0的个数
///2.求N!换算为二进制后末尾0的个数
#include <iostream>

using namespace std;

int last5Nums(int N){
    if(N <= 0) return -1;
    int ret = 0;
    while(N != 0){
        ret += N/5;
        N /= 5;
    }

    return ret;
}

int last1PositionMethod1(int N){
    if(N <= 0) return -1;
    int ret = 0;
    while(N){
        ret += N/2;
        N /= 2;
    }
    return ret + 1;
}

int main(){
    int ret = last5Nums(1000000000);
    cout<<ret<<endl;
    ret = last1PositionMethod1(2);
    cout<<ret<<endl;
}