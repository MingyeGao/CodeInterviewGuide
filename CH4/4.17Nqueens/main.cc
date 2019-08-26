///N皇后问题
#include <iostream>
#include <vector>
#include <initializer_list>
#include <cmath>

using namespace std;

int isValid(vector<int> &record, int i, int j){
    for(int k = 0; k < i; ++k){
        if(record[k] == j || abs(k - i) == abs(record[k] - j)){
            return false;
        }
    }
    return true;
}

int process1(vector<int> record, int i, int n){
    if(i == n) return 1;
    int res = 0;
    for(int j = 0; j < n; ++j){
        if(isValid(record, i, j)){
            record[i] = j;
            res += process1(record, i + 1, n);
        }
    }

    return res;
}

int func1(int n){
    vector<int> record(n);
    int ret = process1(record, 0, n);
    return ret;
}

int process2(int nLimit, int columnLimit, int leftDiaLimit, int rightDialLimit){
    if(columnLimit == nLimit) return 1;

    int pos = 0;
    int rightmost = 0;
    int ret = 0;
    pos = nLimit & ~(columnLimit | leftDiaLimit | rightDialLimit);
    while(pos){
        rightmost = pos & (~pos + 1);
        pos -= rightmost;
        ret += process2(nLimit, columnLimit | rightmost, (leftDiaLimit | rightmost)<<1, (rightDialLimit | rightmost)>>1);
    }

    return ret;
}

int func2(int n){
    int nLimit = (n == 32)?-1:(1<<n) - 1;
    int ret = process2(nLimit, 0, 0, 0);
    return ret;
}

int main(){
    int ret = func2(8);
    cout<<ret<<endl;
}