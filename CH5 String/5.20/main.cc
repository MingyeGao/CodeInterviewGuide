///找到被制定的新类型字符
#include <iostream>
#include <string>

using namespace std;

string func(string &s, int k){
    int upperNum = 0;
    string ret;
    for(int i = k - 1; i >= 0; --i){
        if(s[i] >= 'A' && s[i] <= 'Z'){
            ++upperNum;
        }
        else{
            break;
        }
    }

    if(upperNum % 2 == 0){
        if(s[k] >= 'A' && s[k] <= 'Z'){
            ret = s.substr(k, 2);
        }
        else{
            ret = s.substr(k, 1);
        }
    }
    else{
        ret = s.substr(k - 1, 2);
    }
    return ret;
}

int main(){
    string s = "aaABCDEcBCg";
    string ret = func(s, 10);
    cout<<ret<<endl;
}