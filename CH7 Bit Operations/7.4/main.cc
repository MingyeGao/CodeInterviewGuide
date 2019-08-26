///整数的二进制表达中有多少个1
#include <assert.h>
#include <iostream>
#include <climits>

using namespace std;

int func(int a){
    int ret = 0;
    while(a){
        ret++;
        a -= (a & (~a + 1));
    }
    return ret;
}

int main(){
    int a = 7;
    cout<<func(a)<<endl;
}