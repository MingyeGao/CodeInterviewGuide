///未排序数组中累加和小于或等于给定值的最长子数组长度
#include <iostream>
#include <vector>

using namespace std;

int func(vector<int> &input, int k){
    int maxLen = 0;
    vector<int> sum(input.size() + 1), helper(input.size() + 1);
    sum[0] = 0;
    helper[0] = 0;
    for(int i = 0; i < input.size(); ++i){
        sum[i + 1] = sum[i] + input[i];
        helper[i + 1] = max(helper[i], sum[i + 1]);
    }

    for(int i = 1; i <= input.size(); ++i){
        if(sum[i] == k){
            maxLen = max(maxLen, i);
            continue;
        }

        int remain = sum[i] - k;
        int left = 0, right = i - 1;
        while(left < right){
            int middle = (right - left)/2 + left;
            if(helper[middle] >= remain){
                right = middle;
            }
            else{
                left = middle + 1;
            }
        }

        if(helper[left] >= remain){
            maxLen = max(maxLen, i - left);
        }
    }

    return maxLen;
}

int main(){
    vector<int> input({3, -2, -4, 0, 6});
    int ret = func(input, -2);
    cout<<ret<<endl;
}