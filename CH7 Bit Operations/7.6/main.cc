///在其他数都出现k次的数组中找到只出现一次的数
#include <assert.h>
#include <iostream>
#include <vector>
#include <initializer_list>

using namespace std;

int addInK(vector<int> &vec, int a, int k){
    int i = 0;
    while(a != 0){
        int lsb = a%k;
        vec[i] = (vec[i] + lsb)%k;
        a /= k;
        ++i;
    }
}

int func(vector<int> &input, int k){
    vector<int> sum(32, 0);
    for(int i = 0; i < input.size(); ++i){
        addInK(sum, input[i], k);
    }

    int ret = 0;
    for(int i = sum.size() - 1; i >= 0; --i){
        ret *= k;
        ret += sum[i];
    }
    return ret;
}

int main(){
    vector<int> input({1, 1, 1, 1, 2, 2, 2, 2, 3, 3, 3, 3, 4});
    int ret = func(input, 4);
    cout<<ret<<endl;
}