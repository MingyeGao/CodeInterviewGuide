///矩阵最小路径和
#include <iostream>
#include <vector>
#include <initializer_list>
using namespace std;

int minPath(vector<vector<int>> &path){
    vector<int> dp(path.size(), 0);

    for(int i = 0; i < path[0].size(); ++i){
        for(int j = 0; j < path.size(); ++j){
            if(j == 0){
                dp[j] += path[j][i];
            }
            else{
                dp[j] = min(dp[j] + path[j][i], dp[j-1] + path[j][i]);
            }
        }
        
    }
    return dp[path.size() - 1];
}

int main(){
    vector<vector<int>> path({{1,3,5,9}, {8,1,3,4}, {5,0,6,1},{8,8,4,0}});
    int ret = minPath(path);
    cout<<ret<<endl;
}