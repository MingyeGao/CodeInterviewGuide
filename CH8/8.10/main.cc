///未排序正数数组中累加和为给定值的最长子数组长度
#include <iostream>
#include <vector>

using namespace std;

int getMaxLength(vector<int> &input, int k){
    if(input.size() == 0) return 0;
    if(k <= 0) return 0;
    int left = 0, right = 0;
    int maxLen = 0;
    int sum = input[0];
    while(right < input.size()){
        if(sum == k){
            maxLen = max(maxLen, right - left + 1);
            sum -= input[left++];
        }
        else if(sum < k){
            ++right;
            if(right >= input.size()){
                break;
            }
            sum += input[right];
        }
        else{
            sum -= input[left++];
        }
    }
    return maxLen;
}

int main(){
    vector<int> input({1, 2, 1, 1, 1});
    int ret = getMaxLength(input, 3);
    cout<<ret<<endl;
}