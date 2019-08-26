///数字字符串转换为字母组合的组数
#include <iostream>
#include <vector>
#include <initializer_list>
#include <string>

using namespace std;

int num2str(string &s){
    if(s.size() == 0) return 0;
    vector<int> dp(s.size() + 1);
    if(s[0] == '0') return 0;
    dp[0] = 1;
    dp[1] = 1;
    for(int i = 1; i < s.size(); ++i){
        if(s[i] == '0'){
            if(s[i - 1] != '1' && s[i - 1] != '2'){
                return 0;
            }
            else{
                dp[i + 1] = dp[i];
            }
        };

        int twoBitsVal = (s[i - 1] - '0')*10 + (s[i] - '0');
        if(twoBitsVal >= 11 && twoBitsVal <= 26){
            dp[i + 1] = dp[i] + dp[i - 1];
        }
        else{
            dp[i + 1] = dp[i];
        }
    }

    return dp[s.size()];
}

int main(){
    string s("10");
    int ret = num2str(s);
    cout<<ret<<endl;
}