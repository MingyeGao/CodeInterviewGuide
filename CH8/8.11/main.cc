///未排序数组中累加和为给定值的最长子数组系列问题
#include <iostream>
#include <hash_map>
#include <vector>

int func(std::vector<int> &input, int k){
    __gnu_cxx::hash_map<int, int> mapSumIndex;
    mapSumIndex.insert({0, -1});
    int sum = 0;
    int len = 0;
    for(int i = 0; i < input.size(); ++i){
        sum += input[i];
        int diff = k - sum;
        if(mapSumIndex.find(diff) == mapSumIndex.end()){
            mapSumIndex[sum] = i;
        }
        else{
            int startIndex = mapSumIndex[diff];
            int currentMaxLength = i - startIndex;
            if(currentMaxLength > len) len = currentMaxLength;
        }
    }
    if(len == 0) return -1;
    else return len;
}

int main(){
    std::vector<int> input({1, 2, 3, 3});
    int ret = func(input, 9);
    std::cout<<ret<<"\n";
    return 0;
}