///判断两个字符串是否互为旋转词
#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector<int> getNext(string &match){
    vector<int> ret(match.size());
    ret[0] = -1;
    ret[1] = 0;
    int pos = 2;
    int cn = 0;
    while(pos < match.size()){
        if(match[pos - 1] == match[cn]){
            ret[pos++] = ++cn;
        }
        else if(cn > 0){
            cn = match[cn];
        }
        else{
            ret[pos++] = 0;
            cn = 0;
        }
    }

    return ret;
}

int kmp(string &s, string &match){
    vector<int> next = getNext(match);
    int i = 0, j = 0;
    while(i < s.size() && j < match.size()){
        if(s[i] == match[j]){
            ++i;
            ++j;
            if(j == match.size()){
                return i - j;
            }
        }
        else{
            j = next[j];
            if(j < 0){
                j = 0;
                i++;
            }
        }
    }
    return -1;
    
}

bool isRotation(string &s1, string &s2){
    if(s1.size() != s2.size()) return false;
    if(s1.size() == 0) return true;
    
    string s = s2 + s2;
    int ret = kmp(s, s1);
    return (ret > 0)?true:false;
}

int main(){
    string s1("123"), s2("231");
    bool ret = isRotation(s1, s2);
    if(ret){
        cout<<"true"<<endl;
    }
    else{
        cout<<"false"<<endl;
    }
}