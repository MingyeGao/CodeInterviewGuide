///不重复打印排序数组中相加和为给定值的所有二元组和三元组
#include <iostream>
#include <vector>
#include <initializer_list>

using namespace std;

void twoSum(vector<int> &input, int k){
    int i = 0;
    while(i < input.size()){
        int x = input[i];
        int left = i + 1, right = input.size() - 1;
        int remain = k - x;
        if(remain < x){
            break;
        } 
        while(left <= right){
            int middle = (right - left)/2 + left;
            if(input[middle] == remain){
                cout<<x<<", "<<remain<<endl;
                break;
            }

            if(input[middle] > remain){
                right = middle - 1;
            }
            else{
                left = middle + 1;
            }
        }
        
        ++i;
        while(i < input.size() && input[i] == input[i - 1]){
            ++i;
        }
    }
}

void threeSum(vector<int> &input, int k){
    int i = 0, j;
    while(i < input.size()){
        for(j = i + 1; j < input.size();){
            int remain = k - input[i] - input[j];
            if(remain < input[j]){
                break;
            }
            int left = j + 1, right = input.size() - 1;
            int middle;
            while(left <= right){
                middle = (right - left)/2 + left;
                if(input[middle] == remain){
                    cout<<input[i]<<", "<<input[j]<<", "<<remain<<endl;
                    break;
                }

                if(input[middle] > remain){
                    right = middle - 1;
                }
                else{
                    left = middle + 1;
                }
            }

            ++j;
            while(j < input.size() && input[j] == input[j - 1]){
                ++j;
            }
        }
        do{
            ++i;
        }while(i < input.size() - 1 && input[i] == input[i - 1] && input[i + 1] == input[i]);
    }
}

int main(){
    vector<int> input({-8, -4, -3, 0, 1, 2, 4, 5, 8, 9});
    twoSum(input, 10);
    threeSum(input, 10);
}