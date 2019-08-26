///正数数组的最小不可组成和
#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>

using namespace std;

int unformedSum(vector<int> &input){
    int sum = 0;
    int minVal = INT_MAX;
    for(int i = 0; i < input.size(); ++i){
        sum += input[i];
        minVal = min(minVal, input[i]);
    }

    vector<bool> dp(sum + 1, false);
    dp[0] = true;
    for(int i = 0; i < input.size(); ++i){
        for(int j = sum; j >= input[i]; --j){
            if(dp[j - input[i]]){
                dp[j] = true;
            } 
        }
    }

    for(int i = minVal; i <= sum; ++i){
        if(!dp[i]) return i;
    }
}

int unformedSumWith1(vector<int> &input){
    int range = 0;
    sort(input.begin(), input.end());
    for(int i = 0; i < input.size(); ++i){
        if(input[i] > range + 1){
            break;
        }
        else{
            range += input[i];
        }
    }
    return range + 1;
}

int main(){
    vector<int> input({3, 2, 5});
    int ret = unformedSum(input);
    cout<<ret<<endl;
    vector<int> input2({3, 4, 1, 2});
    ret = unformedSumWith1(input2);
    cout<<ret<<endl;
}