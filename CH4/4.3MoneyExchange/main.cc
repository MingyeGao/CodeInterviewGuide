///换钱的最少货币数
#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include <initializer_list>
using namespace std;

///给定数组，每一个元素代表一种面值，
///每种面值的钱币个数不限
int exchange1(vector<int> &input, int n){
    if(n == 0) return 0;
    sort(input.begin(), input.end());
    vector<int> dp(n+1, INT_MAX);
    dp[0] = 0;
    for(int i = 0; i <= n; ++i){
        for(int j = 0; j < input.size(); ++j){
            if(input[j] > i) break;
            int remain = i - input[j];
            if(remain != 0 && dp[remain] == INT_MAX){
                continue;
            }

            int tmp = 1 + dp[remain];
            if(tmp < dp[i]) dp[i] = tmp;
        }
    }

    if(dp[n] == INT_MAX) return 0;
    return dp[n];
}


///给定数组，每个元素仅代表一张钱的面值
int exchange2(vector<int> &input, int n){
    if(n == 0) return 0;
    sort(input.begin(), input.end());
    vector<vector<int>> dp(n + 1, vector<int>(input.size() + 1, INT_MAX));
    for(int i = 0; i <= input.size(); ++i){
        dp[0][i] = 0;
    }

    for(int i = 1; i <= n; ++i){
        for(int j = 1; j <= input.size(); ++j){
            if(input[j-1] > i) break;
            int remain = i - input[j-1];
            if(dp[remain][j-1] == INT_MAX) continue;
            dp[i][j] = min(dp[i][j-1], (dp[remain][j-1] + 1));
        }
        
    }

    if(dp[n][input.size()] == INT_MAX) return 0;
    return dp[n][input.size()];
}

int main(){
    vector<int> input({5, 2, 3});
    int ret = exchange1(input, 1);
    cout<<ret<<endl;
    vector<int> input2({5, 2, 5, 3});
    int ret2 = exchange2(input2, 15);
    cout<<ret2<<endl;
    
}