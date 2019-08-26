///找到字符串的最长无重复字符子串
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int func(string &s){
    vector<int> position(256, -1);
    int start = 0;
    int maxLen = 0;
    for(int i = 0; i < s.size(); ++i){
        if(position[s[i]] >= start){
            start = position[s[i]] + 1;
            position[s[i]] = i;
        }
        else{
            position[s[i]] = i;
        }
        if(i - start + 1 > maxLen){
            maxLen = i - start + 1;
        }
    }

    return maxLen;
}

int main(){
    string s = "aabcb";
    int ret = func(s);
    cout<<ret<<endl;
}