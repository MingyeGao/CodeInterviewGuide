///字符串的统计字符串
#include <iostream>
#include <string>

using namespace std;

string num2str(int i){
    string ret;
    while(i){
        int lsb = i%10;
        ret = (char)(lsb + '0') + ret;
        i /= 10;
    }

    return ret;
}

string func(string &s){
    string ret;
    if(s.size() == 0) return ret;
    char prev = s[0];
    int num = 1;
    for(int i = 1; i < s.size(); ++i){
        if(s[i] == prev){
            num++;
        }
        else{
            ret += prev;
            ret += '_';
            ret += num2str(num);
            ret += '_';
            prev = s[i];
            num = 1;
        }
    }

    if(num != 0){
        ret += prev;
        ret += '_';
        ret += num2str(num);
    }

    return ret;
}

char func2(string &s, int n){
    char prev;
    string ret;
    int i = 0;
    int num = 0;
    while(i < s.size()){
        int tmp = 0;
        prev = s[i];
        i += 2;
        while(i < s.size() && s[i] >= '0' && s[i] <= '9'){
            tmp *= 10;
            tmp += (s[i] - '0');
            ++i;
        }
        num += tmp;
        ++i;
        
        if(num >= n) return prev;
    }
}

int main(){
    string s("aaabbadddffc");
    string ret = func(s);
    string s2("a_1_b_100");
    char ret2 = func2(s2, 50);
    cout<<ret2<<endl;
}

