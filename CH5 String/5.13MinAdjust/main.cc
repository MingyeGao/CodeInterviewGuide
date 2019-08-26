///添加最少字符使得字符串成为回文字符串
#include <iostream>
#include <vector>
#include <string>

using namespace std;

string getPalindrome(string s){
    if(s.size() == 0 || s.size() == 1) return s;

    vector<vector<int>> dp(s.size(), vector<int>(s.size()));

    for(int i = 0; i < s.size(); ++i){
        dp[i][i] = 0;
    }

    for(int i = 0; i < s.size() - 1; ++i){
        if(s[i] == s[i + 1]){
            dp[i][i + 1] = 0;
        }
        else{
            dp[i][i + 1] = 1;
        }
    }

    for(int gap = 2; gap < s.size(); ++gap){
        for(int i = 0; i + gap < s.size(); ++i){
            if(s[i] == s[i + gap]){
                dp[i][i + gap] = dp[i + 1][i + gap -1];
            }
            else{
                dp[i][i + gap] = min(dp[i + 1][i + gap], dp[i][i + gap - 1]) + 1;
            }
        }
    }

    string leftPart, rightPart, ret;
    int l = 0, r = s.size() - 1;
    int len = dp[0][s.size() - 1] + s.size();
    while(len > (r - l + 1)){
        if(s[l] == s[r]){
            leftPart += s[l];
            rightPart = s[r] + rightPart;
            ++l;
            --r;
            len -= 2;
        }
        else{
            if(dp[l + 1][r] > dp[l][r - 1]){
                leftPart += s[r];
                rightPart = s[r] + rightPart;
                len -= 2;
                r--;
            }
            else{
                leftPart += s[l];
                rightPart = s[l] + rightPart;
                len -= 2;
                ++l;
            }
        }
    }
    ret += leftPart;
    ret += s.substr(l, r - l + 1);
    ret += rightPart;

    return ret;
}

int main(){
    string s("121");
    string ret = getPalindrome(s);
    cout<<ret<<endl;

}