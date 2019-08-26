///将整数字符串转成整数值
#include <iostream>
#include <string>
#include <climits>

using namespace std;

int str2num(string &s){
    int ret = 0;
    bool isNegative = false;
    for(int i = 0; i < s.size(); ++i){
        if(!((s[i] >= '0' && s[i] <= '9') || s[i] == '-')){
            return 0;
        }

        if(s[i] == '-'){
            if(isNegative) return 0;
            else isNegative = true;
            continue;
        }

        if(ret > INT_MAX/10) return 0;
        if(!isNegative && ret == INT_MAX/10 && (s[i] - '0') > (INT_MAX%10)) return 0;
        if(isNegative && ret == INT_MAX/10 && (s[i] - '0') > (INT_MAX%10) + 1) return 0;
        ret *= 10;
        ret += (s[i] - '0');
    }

    if(isNegative) ret *= -1;

    return ret;
}

int main(){
    string s("2147483648");
    int ret = str2num(s);
    cout<<ret<<endl;
}