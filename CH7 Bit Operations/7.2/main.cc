///不用任何比较判断两个数中较大的数

#include <iostream>
#include <climits>

using namespace std;

///要求n是个位数 0或1
///反转n
int flip(int n){
    return n ^ 1;
}

///获取a的符号
///若a为0或正数，则返回1
///若a为负数，则返回-1
int getSign(int a){
    return flip((a >> 31) & 1); 
}

///返回a, b中较大的数
///若a - b 溢出，则错误
int getMax1(int a, int b){
    int c = a - b;
    int signC = getSign(c);
    return a*signC + b*flip(signC);
}

///返回a, b中较大的数
///考虑了溢出的情况
int getMax2(int a, int b){
    int c = a - b;
    int signA = getSign(a);
    int signB = getSign(b);
    int signC = getSign(c);
    int diff = signA ^ signB;
    int same = flip(diff);
    int factor = diff*signA + same*signC;
    return a*factor + b*flip(factor);
}

int main(){
    int a = INT_MAX/2, b = INT_MIN;
    int c = getMax2(a, b);
    cout<<"a is "<<a<<", ";
    cout<<"b is "<<b<<", ";
    cout<<"the larger one is "<<c<<endl;
}