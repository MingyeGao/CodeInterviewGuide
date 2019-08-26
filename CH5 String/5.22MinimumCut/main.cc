///回文最少分割数

#include <iostream>
#include <vector>
#include <string>
#include <climits>

using namespace std;

int func(string &s){
    vector<vector<int> > dp(s.size(), vector<int>(s.size(), 0));

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
            int tmp = INT_MAX;
            if(s[i] == s[i + gap]){
                tmp = dp[i + 1][i + gap - 1];
            }
            tmp = min(tmp, min(1 + dp[i + 1][i + gap], dp[i][i + gap - 1] + 1));
            dp[i][i + gap] = tmp;
        }
    }

    return dp[0][s.size() - 1];
}

int main(){
    string s = "ACDCDCDAD";
    int ret = func(s);
    cout<<ret<<endl;
}