///判断两个字符串是否互为变形词
#include <iostream>
#include <string>
#include <vector>

using namespace std;

bool func(string &s1, string &s2){
    if(s1.size() != s2.size()) return false;

    vector<int> c(256, 0);
    for(int i = 0; i < s1.size(); ++i){
        c[s1[i]]++;
        c[s2[i]]--;
    }
    for(int i = 0; i < 256; ++i){
        if(c[i] != 0) return false;
    }
    return true;
}

int main(){
    string s1("123"), s2("321");
    bool ret = func(s1, s2);
    if(ret == true){
        cout<<"true"<<endl;
    }
    else{
        cout<<"false"<<endl;
    }
}