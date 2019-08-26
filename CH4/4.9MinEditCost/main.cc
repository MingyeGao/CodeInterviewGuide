///最小删除代价

#include <iostream>
#include <vector>
#include <string>
#include <climits>

using namespace std;


///时间复杂度O(M*N)，空间复杂度O(M*N)
int minEditCost(string &s1, string &s2, int ic, int dc, int rc){
    
    
    vector<vector<int>> dp(s1.size() + 1, vector<int>(s2.size() + 1, 0));
    
    for(int i = 1; i <= s1.size(); ++i){
        dp[i][0] = dp[i - 1][0] + dc;
    }
    for(int i = 1; i <= s2.size(); ++i){
        dp[0][i] = dp[0][i - 1] + ic;
    }

    for(int i = 1; i <= s1.size(); ++i){
        for(int j = 1; j <= s2.size(); ++j){
            int val1 = dp[i - 1][j] + dc;
            int val2 = dp[i][j - 1] + ic;
            int val3;
            if(s1[i] == s2[j]){
                val3 = dp[i - 1][j - 1];
            }
            else{
                val3 = dp[i - 1][j - 1] + rc;
            }
            dp[i][j] = min(min(val1, val2), val3);
        }
        
    }

    return dp[s1.size()][s2.size()];
}

int main(){
    string s1("abc"), s2("abc");
    int ret = minEditCost(s1, s2, 5, 3, 2);
    cout<<ret<<endl;
}