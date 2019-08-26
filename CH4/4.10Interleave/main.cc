//字符串的交错组成
#include <iostream>
#include <string>
#include <vector>

using namespace std;

bool func(string &s1, string &s2, string &aim){
    if(aim.size() != s1.size() + s2.size()) return false;
    vector<vector<int> > dp(s1.size() + 1, vector<int>(s2.size() + 1, 0));

    
    for(int i = 0; i <= s1.size(); ++i){
        for(int j = 0; j <= s2.size(); ++j){
            if(i == 0 && j == 0){
                dp[i][j] = 1;
                continue;
            }
            if(aim[i + j - 1] == s1[i - 1] && dp[i - 1][j] == 1){
                dp[i][j] = 1;
            }
            else if(aim[i + j - 1] == s2[j - 1] && dp[i][j - 1] == 1){
                dp[i][j] = 1;
            }
            else{
                dp[i][j] = 0;
            }
        }
    }

    if(dp[s1.size()][s2.size()] == 1){
        return true;
    }
    else{
        return false;
    }
}

int main(){
    string s1("AB"), s2("12"), aim("AB21");
    bool ret = func(s1, s2, aim);
    if(ret){
        cout<<"true"<<endl;
    }
    else{
        cout<<"false"<<endl;
    }
}