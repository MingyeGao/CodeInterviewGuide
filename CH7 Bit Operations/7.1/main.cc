///不用额外变量交换两个整数的值
#include <iostream>

using namespace std;

int main(){
    int a = 10, b = 1;
    a = a ^ b;
    b = a ^ b;
    a = a ^ b;
    cout<<"a = "<<a<<", "<<"b = "<<b<<endl;
}