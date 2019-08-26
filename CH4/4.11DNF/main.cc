//龙与地下城游戏
#include <iostream>
#include <vector>
#include <initializer_list>

using namespace std;

int game(vector<vector<int> > &input, int minHp){
    int hp;
    int rows = input.size();
    int columns = input[0].size();
    vector<int> dp(rows, 0);
    dp[rows - 1] = max(minHp, minHp - input[rows - 1][columns - 1]); 

    for(int i = rows - 2; i >= 0; --i){
        dp[i] = max(1, dp[i + 1] - input[i][columns - 1]);
    }

    for(int i = columns - 2; i >= 0; --i){
        for(int j = rows - 1; j >= 0; --j){
            if(j == rows - 1){
                dp[j] = max(1, dp[j] - input[j][i]);
            }
            else{
                dp[j] = min(max(1, dp[j] - input[j][i]), max(1, dp[j + 1] - input[j][i]));
            }
        }
    }

    return dp[0];
}

int main(){
    vector<vector<int> > input({
        {-2, -3, 3},
        {-5, -10, 1},
        {0, 30, -5}
    });

    int ret = game(input, 1);
    cout<<ret<<endl;
}