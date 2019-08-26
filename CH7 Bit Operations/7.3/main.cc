///只用位运算不用算术运算实现整数的加减乘除
#include <assert.h>
#include <iostream>
#include <climits>

using namespace std;

int add(int a, int b){
    int ret, carry;
    ret = a ^ b;
    carry = (a & b) << 1;
    while(carry){
        int newRet = ret ^ carry;
        carry = (ret & carry) << 1;
        ret = newRet;
    }

    return ret;
}

int sub(int a, int b){
    int c = ~b + 1;
    return add(a, c);
}

int mul(int a, int b){
    int ret = 0;
    while(b != 0){
        if(b & 1){
            ret = add(ret, a);
        }
        a <<= 1;
        b = (uint)b >> 1;
    }
    return ret;
}

///循环右移
// int CRS(int a, int bit){

// }

// int divide(int a, int b){
//     int signA = 1, signB = 1;
//     if(a < 0){
//         a =(~a + 1);
//         signA = -1;
//     }
//     if(b < 0){
//         b = (~b + 1);
//         signB = -1;
//     }

//     if(a < b) return 0;
//     int ret = 0;
//     int B = b;
//     while(B <= a){
//         B <<= 1;
//         if(B > a) break;
//     }

//     B >>= 1;
//     while(B >= b){
//         ret <<= 1;
//         if(a >= B){
//             ret += 1;
//         }
//         a -= B;
//         B >>= 1;
//     }

//     return (signA*signB)*ret;

// }

// int safeDivide(int a, int b){
//     assert(b != 0);
//     if(a != INT_MIN && b != INT_MIN){
//         return divide(a, b);
//     }
//     if(a != INT_MIN && b == INT_MIN){
//         return 0;
//     }
//     if(a == INT_MIN && b == INT_MIN){
//         return 1;
//     }

//     if(a == INT_MIN){
//         return divide(add(a, 1), b);
//     }
// }

int main(){
    int a = INT_MIN, b = 1;
    // cout<<add(a, b)<<", "<<a + b<<endl;
    // cout<<sub(b, a)<<", "<<b - a<<endl;
    // cout<<mul(a, b)<<", "<<a * b<<endl;
    cout<<safeDivide(a, b)<<endl;
}
