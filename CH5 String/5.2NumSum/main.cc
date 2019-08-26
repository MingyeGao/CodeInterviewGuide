///字符串中数字子串求和
#include <iostream>
#include <vector>
#include <string>

using namespace std;

int func(string &s){
    int tmp = 0;
    bool numFlag = false;
    bool negativeFlag = false;
    int ret = 0;
    for(int i = 0; i < s.size(); ++i){
        if(s[i] >= '0' && s[i] <= '9'){
            tmp *= 10;
            tmp += s[i] - '0';
            numFlag = true;
        }
        else{
            if(numFlag){
                if(negativeFlag){
                    tmp *= -1;
                }
                ret += tmp;
            }
            else{
                if(s[i] == '-') negativeFlag = true;
                else negativeFlag = false;
            }
            numFlag = false;
            tmp = 0;
        }
    }

    if(numFlag){
        if(negativeFlag) tmp *= -1;
        ret += tmp;
    }
    return ret;
}

int main(){
    string s("A--1CD2E33");
    int ret = func(s);
    cout<<ret<<endl;
}