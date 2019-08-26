///字符串匹配问题
#include <iostream>
#include <vector>
#include <string>

using namespace std;

bool isValid(string &s, string &e){
    for(int i = 0; i < s.size(); ++i){
        if(s[i] == '*' || s[i] == '.'){
            return false;
        }
    }

    if(e[0] == '*') return false;
    for(int i = 1; i < e.size(); ++i){
        if(e[i] == '*' && e[i - 1] == '*'){
            return false;
        }
    }

    return true;
}

bool isMatch(string &s, string &e){
    if(!isValid(s, e)) return false;

    vector<vector<bool> > dp(s.size() + 1, vector<bool>(e.size() + 1, false));

    dp[s.size()][e.size()] = true;
    for(int i = 0; i < s.size(); ++i){
        dp[i][e.size()] = false;
    }
    if(s[s.size() - 1] == e[e.size() - 1]) {
        dp[s.size() - 1][e.size() - 1] = true;
    }

    for(int i = e.size() - 2; i >= 0; --i){
        for(int j = s.size() - 1; j >= 0; --j){
            if(e[i] == '*'){
                dp[j][i] = false;
                continue;
            }

            if((i + 1) < e.size() && e[i + 1] == '*'){
                if(e[i] == '.'){
                    dp[j][i] = false;
                    int k = j + 1;
                    while(k <= s.size()){
                        if(dp[k][i + 2] == true){
                            dp[j][i] = true;
                            break;
                        }
                        ++k;
                    }
                }
                else if(e[i] == s[j]){
                    dp[j][i] = dp[j + 1][i] || dp[j][i + 2];
                }
                else{
                    dp[j][i] = dp[j][i + 2];
                }
            }
            else{
                if(e[i] == '.' || e[i] == s[j]){
                    dp[j][i] = dp[j + 1][i + 1];
                }
                else{
                    dp[j][i] = false;
                }
            }
        }
    }

    return dp[0][0];
}

int main(){
    string s1 = "", s2 = "..*";
    bool ret = isMatch(s1, s2);
    if(ret){
        cout<<"true"<<endl;
    }
    else{
        cout<<"false"<<endl;
    }
}