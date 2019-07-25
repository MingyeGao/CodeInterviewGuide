///换钱的方法数
#include <iostream>
#include <vector>
#include <climits>
#include <initializer_list>
#include <algorithm>
using namespace std;

int getMethodsNum(vector<int> &input, int n){
    sort(input.begin(), input.end());
    vector<int> dp(n + 1, 0);
    dp[0] = 1;
    for(int i = 0; i < input.size();  ++i ){
        for(int j = 1; j <= n; ++j){
            if(input[i] > j) continue;
            dp[j] += dp[j - input[i]];
        }
    }

    return dp[n];
}

int main(){
    vector<int> input({5, 10, 25, 1});
    int ret = getMethodsNum(input, 15);
    cout<<ret<<endl;
}