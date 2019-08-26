///在两个排序数组中找到上中位数
#include <assert.h>
#include <iostream>
#include <vector>

using namespace std;

int getMedian(vector<int>& input1, vector<int> &input2){
    assert(input1.size() == input2.size());
    int size = input1.size();
    int left = 0, right = input1.size() - 1;
    int index2, index1;
    if(input1[0] >= input2[input2.size() - 1]){
        return input2[input2.size() - 1];
    }
    else if(input1[input1.size() - 1] <= input2[0]){
        return input1[input1.size() - 1];
    }

    while(1){
        index1 = (right - left)/2 + left;
        index2 = size - (index1 + 1) - 1;
        if(max(input1[index1], input2[index2]) <= min(input1[index1 + 1], input2[index2 + 1])){
            return max(input1[index1], input2[index2]);
        }

        if(input1[index1] > input2[index2 + 1]){
            right = index1;
        }
        else if(input2[index2] > input1[index1 + 1]){
            left = index1;
        }
    }
}

int main(){
    vector<int> input1({0, 1, 2}), input2({3, 4, 5});
    int ret = getMedian(input1, input2);
    cout<<ret<<endl;
}