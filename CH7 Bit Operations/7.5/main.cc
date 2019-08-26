///整数的二进制表达中有多少个1
#include <assert.h>
#include <iostream>
#include <vector>
#include <initializer_list>

using namespace std;

///输入数组中有一个只出现过一次的数
///其余都出现过两次
///返回出现过两次的数
int func(vector<int> &input){
    int ret = 0;
    for(int i = 0; i < input.size(); ++i){
        ret ^= input[i];
    }
    return ret;
}

///输入数组中有两个只出现过一次的数
///其余都出现过两侧
///输出出现过一次的两个数
void func2(vector<int> &input){
    int ret = 0, ret1 = 0;
    for(int i = 0; i < input.size(); ++i){
        ret ^= input[i];
    }

    int rightMost = ret & (~ret + 1);

    for(int i = 0; i < input.size(); ++i){
        if(rightMost & input[i]){
            ret1 ^= input[i];
        }
    }

    cout<<ret1<<" "<<(ret1 ^ ret)<<endl;
}

int main(){
    vector<int> input({1, 2, 3, 4, 5, 3, 4, 5});
    func2(input);
    //cout<<ret<<endl;
}