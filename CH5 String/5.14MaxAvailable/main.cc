///括号字符串的有效性和最长有效长度

#include <iostream>
#include <vector>

using namespace std;

int func(string &s){
    vector<int> dp(s.size(), 0);
    dp[0] = 0;
    int maxLen = 0;
    for(int i = 1; i < s.size(); ++i){
        if(s[i] == '(') continue;
        else{
            int tmp = 0;
            int index = i - 1;
            if(s[index] == '('){
                tmp += 2;
                index -= 1;
                while(index > 0 && dp[index] != 0){
                    tmp += dp[index];
                    index -= dp[index];
                }
            }
            else{
                int left  = index - dp[index];
                if(left >= 0 && s[left] == '('){
                    tmp = dp[index] + 2;
                }
                index = left - 1;
                if(index >= 0 && dp[index] != 0){
                    tmp += dp[index];
                }
            }
            if(tmp > maxLen) maxLen = tmp;
            dp[i] = tmp;
        }
    }

    return maxLen;
}

int main(){
    string s("()(()())");
    int ret = func(s);
    cout<<ret<<endl;
}