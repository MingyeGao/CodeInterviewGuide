///最长公共子序列
#include <iostream>
#include <string>
#include <vector>
#include <initializer_list>
using namespace std;


string maxSubSequence(string &s1, string &s2){
    vector<vector<int> > dp(s1.size() + 1, vector<int>(s2.size() + 1));
    for(int i = 0; i <= s1.size(); ++i){
        dp[i][0] = 0;
    }
    for(int i = 0; i <= s2.size(); ++i){
        dp[0][i] = 0;
    }

    for(int i = 1; i <= s1.size(); i++){
        for(int j = 1; j <= s2.size(); ++j){
            if(s1[i - 1] == s2[j - 1]){
                dp[i][j] = dp[i - 1][j - 1] + 1;
            }
            else{
                dp[i][j] = dp[i][j - 1];
            }
        }
    }

    int m = s1.size(), n = s2.size();
    string ret(dp[m][n], 'a');
    int index = dp[m][n] - 1;
    while(dp[m][n] > 0){
        if(m >= 1 && n >= 1 && dp[m][n] > dp[m-1][n] && dp[m][n] > dp[m][n-1]){
            ret[index--] = s1[m-1];
            --m;
            --n;
        }
        else if(n >=1 && dp[m][n] == dp[m][n - 1]){
            --n;
        }
        else if(m >= 1 && dp[m][n] == dp[m - 1][n]){
            --m;
        }
    }

    return ret;
}

int main(){
    //string s1("abcd"), s2("bcd1");
    string s1("1A2C3D4B56"), s2("B1D23CA45B6A");
    string ret = maxSubSequence(s1, s2);
    cout<<ret<<endl;
}
