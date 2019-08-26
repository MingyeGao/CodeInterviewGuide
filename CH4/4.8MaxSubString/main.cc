///最长公共子串问题
#include <iostream>
#include <vector>
#include <string>

using namespace std;

///时间复杂度O(M*N), 空间复杂度O(M*N)
string maxSubString(string &s1, string &s2){
    int maxLen = 0;
    vector<vector<int>> dp(s1.size() + 1, vector<int>(s2.size() + 1, 0));
    int endIndexIns1;
    for(int i = 1; i <= s1.size(); ++i){
        for(int j = 1; j <= s2.size(); ++j){
            if(s1[i - 1] == s2[j - 1]){
                dp[i][j] = dp[i - 1][j - 1] + 1;
                if(dp[i][j] > maxLen){
                    maxLen = dp[i][j];
                    endIndexIns1 = i-1;
                }
            }
            else{
                dp[i][j] = 0;
            }
        }
    }

    return s1.substr(endIndexIns1 - maxLen + 1, maxLen);
}

///时间复杂度O(M*N),空间复杂度O(1)
string maxSubString2(string &s1, string &s2){
    int len = 0;
    int maxLen = 0;
    int endIndexInS1 = 0;
    
    int i, j;
    i = 1;
    for(j = 1; j <= s2.size(); ++j){
        len = 0;
        int i1 = i, j1 = j;
        while(i1 <= s1.size() && j1 <= s2.size()){
            if(s1[i1] == s2[j1]){
                len += 1;
                if(len > maxLen){
                    maxLen = len;
                    endIndexInS1 = i1;
                }
            }
            else{
                len = 0;
            }
            ++i1;
            ++j1;
        }
    }

    j = 1;
    for(i = 1; i <= s1.size(); ++i){
        len = 0;
        int i1 = i, j1 = j;
        while(i1 <= s1.size() && j1 <= s2.size()){
            if(s1[i1] == s2[j1]){
                len += 1;
                if(len > maxLen){
                    maxLen = len;
                    endIndexInS1 = i1;
                }
            }
            else{
                len = 0;
            }
            ++i1;
            ++j1;
        }
    }

    return s1.substr(endIndexInS1 - maxLen + 1, maxLen);

}

int main(){
    string s1("1AB2345CD");
    string s2("12345EF");
    string ret = maxSubString2(s1, s2);
    cout<<ret<<endl;
}