///最长递增子序列
#include <iostream>
#include <vector>
#include <initializer_list>

using namespace std;

vector<int> LIS(vector<int> &input){
    
    if(input.size() == 0) return vector<int>();
    vector<int> ends;
    vector<int> dp(input.size());
    ends.push_back(input[0]);
    dp[0] = 1;
    int left, right, middle;
    for(int i = 1; i < input.size(); ++i){
        left = 0, right = ends.size() - 1;
        while(left <= right){
            middle = (right + left)/2;
            if(ends[middle] > input[i]){
                right = middle - 1;
            }
            else{
                left = middle + 1;
            }
        } 

        

        if(left >= ends.size()){
            ends.push_back(input[i]);
        }
        else{
            ends[left] = input[i];
        }
        dp[i] = left + 1;
    }
    cout<<ends.size()<<endl;
    int i;
    for(i = dp.size() - 1; i >= 0; --i){
        if(dp[i] == ends.size()){
            break;
        }
    }
    vector<int> ret(ends.size(), 0);
    int j = ret.size()-1;
    ret[j] = input[i--];
    while(j > 0){
        while(i > 0){
            if(dp[i--] == (j)){
                ret[--j] = input[i+1];
                break;
            }
        }
    }
    return ret;

}

int main(){
    vector<int> input({2, 1, 5, 3, 6, 4, 8, 9, 7});
    vector<int> ret = LIS(input);
    for(auto i : ret){
        cout<<i<<endl;
    }
}