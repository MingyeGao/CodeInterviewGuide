//KMP字符串匹配算法
#include <assert.h>
#include <iostream>
#include <vector>
#include <string>

using namespace std;

void getNextArr(string match, vector<int> &nextArr){
    assert(match.size() == nextArr.size());
    nextArr[0] = -1;
    nextArr[1] = 0;
    int pos = 2;
    int cn = 0;

    while(pos < match.size()){
        if(match[pos - 1] == match[cn]){
            nextArr[pos++] = ++cn;
        }
        else if(cn > 0){
            cn = nextArr[cn];
        }
        else{
            nextArr[pos++] = 0;
        }
    }
}

int KMP(string s, string match){
    vector<int> next(match.size());
    getNextArr(match, next);

    int matchIndex = 0, sIndex = 0;
    while(sIndex < s.size()){
        if(match[matchIndex] == s[sIndex]){
            ++matchIndex;
            ++sIndex;
            if(matchIndex >= match.size()){
                return sIndex - match.size();
            }
        }
        else{
            int cn = next[matchIndex];
            if(cn < 0){
                ++sIndex;
            }
            else{
                matchIndex = cn;
            }
        }
    }
    return -1;
}

int main(){
    string s("acbc");
    string match("bcc");
    int ret = KMP(s, match);
    cout<<ret<<endl;
}