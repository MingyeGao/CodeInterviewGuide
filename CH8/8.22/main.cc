///不包含本位置的累乘数组
///不能使用除法
#include <iostream>
#include <vector>

using namespace std;

vector<int> func(vector<int> &input){
    vector<int> ret(input.size());
    vector<int> lr(input.size()), rl(input.size());

    lr[0] = 1;
    rl[input.size() - 1] = 1;
    for(int i = 1; i < input.size(); ++i){
        lr[i] = lr[i - 1] * input[i - 1];
        rl[input.size() - i - 1] = rl[input.size() - i] * input[input.size() - i];
    }

    for(int i = 0; i < input.size(); ++i){
        ret[i] = lr[i] * rl[i];
    }
    return ret;
}

int main(){
    vector<int> input({2, 3, 1, 4});
    vector<int> ret = func(input);
    for(int i : ret){
        cout<<i<<", ";
    }
}