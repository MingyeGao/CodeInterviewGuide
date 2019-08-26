///在有序旋转数组中找到最小值
#include <iostream>
#include <vector>

using namespace std;

int getMin(vector<int> &input){
    int left = 0, right = input.size() - 1;
    while(left < right){
        int middle = (right - left)/2 + left;

        if(left == right - 1){
            return min(input[left], input[right]);
        }

        // if(input[left] > input[middle]){
        //     right = middle;
        // }
        // else if(input[middle] > input[right]){
        //     left = middle;
        // }
        // else{
        //     right = middle;
        // }

        if(input[middle] > input[right]){
            left = middle;
        }
        else{
            right = middle;
        }
    }

    return input[left];
}

int main(){
    vector<int> input({4, 5, 6, 7, 1, 2, 3});
    int ret = getMin(input);
    cout<<ret<<endl;
}