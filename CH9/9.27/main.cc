///在两个排序数组中找到第
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int KthMin(vector<int> &input1, vector<int> &input2, int k){
    if(input1.size() > input2.size()){
        return KthMin(input2, input1, k);
    }

    if(k > (input1.size() + input2.size())) {
        return -1;
    }

    
    
    if(input2.size() >= k && input1[0] >= input2[k - 1]){
        return input2[k - 1];
    }

    if(input1[input1.size() - 1] <= input2[0]){
        return input1.size()<k? input2[k - input1.size() - 1]: input1[k - 1];
    }

    int left = 0, right = min(static_cast<int>(input1.size() - 1), k - 1);
    int index1, index2;
    while(1){
        index1 = (left - right)/2 + left - 1;
        index2 = k - (index1 + 1) - 1;
        if(max(input1[index1], input2[index2]) < min(input1[index1 + 1], input2[index2 + 1])){
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
    vector<int> input1({1, 2, 3, 4, 5});
    vector<int> input2({3, 4, 5});
    int ret = KthMin(input1, input2, 4);
    cout<<ret<<endl;
}