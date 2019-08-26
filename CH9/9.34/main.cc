///邮局选址问题 
#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int shortestPost(vector<int> &input, int num){
    vector<vector<int> > w(input.size(), vector<int>(input.size(), 0));
    for(int i = 0; i < input.size(); ++i){
        for(int j = i + 1; j < input.size(); ++j){
            w[i][j] = w[i][j - 1] + input[j] - input[(i + j)/2];
        }
    }

    vector<vector<int> > dp(num, vector<int>(input.size(), 0));
    for(int j = 0; j < input.size(); ++j){
        dp[0][j] = w[0][j];
    }
    for(int i = 1; i < num; ++i){
        for(int j = i + 1; j < input.size(); ++j){
            dp[i][j] = INT_MAX;
            for(int k = 0; k < j; ++k){
                dp[i][j] = min(dp[i][j], dp[i - 1][k] + w[k + 1][j]);
            }
        }
    }
    return dp[num - 1][input.size() - 1];
}

int main(){
    vector<int> input({1, 2, 3, 4, 5, 1000});
    int num = 2;
    int ret = shortestPost(input, num);
    cout<<ret<<endl;
}