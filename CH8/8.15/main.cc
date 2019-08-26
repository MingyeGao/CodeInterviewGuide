///奇数下标都是奇数或偶数下标都是偶数
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

void adjust(vector<int> &input){
    int e = input.size() - 1;
    int even = 0, odd = 1;

    while(even < input.size() && odd < input.size()){
        if(input[e] % 2 == 0){
            swap(input[e], input[even]);
            even += 2;
        }
        else{
            swap(input[e], input[odd]);
            odd += 2;
        }
    }
}

int main(){
    vector<int> input({1, 8, 3, 2, 4, 6});
    adjust(input);
    for(auto i : input){
        cout<<i<<", ";
    }
}