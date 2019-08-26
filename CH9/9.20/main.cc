///在有序旋转数组里找到一个数
#include <iostream>
#include <vector>

using namespace std;

bool exist(vector<int> &input, int k){
    int left = 0, right = input.size() - 1;
    while(left < right){
        int middle = (right - left)/2 + left;
        if(input[middle] == k) return true;

        if(input[left] == input[middle] && input[middle] == input[right]){
            while(input[left] == input[middle] && left < middle){
                ++left;
            }

            if(left == middle){
                middle = left + 1;
                continue;
            }
        }

        if(input[middle] > input[left]){
            if(k >= input[left] && k < input[middle]){
                right = middle - 1;
            }
            else{
                left = middle + 1;
            }
        }
        else{
            if(k > input[middle] && k <= input[right]){
                left = middle + 1;
            }
            else{
                right = middle - 1;
            }
        }
    }

    if(input[left] == k) return true;
    return false;
}

int main(){
    vector<int> input({ 4, 5, 6, 7, 1, 2, 3});
    bool ret = exist(input, 8);
    if(ret){
        cout<<"true"<<endl;
    }
    else{
        cout<<"false"<<endl;
    }
}