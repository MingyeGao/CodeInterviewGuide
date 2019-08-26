///拼接所有字符串产生字典顺序最小的大写字符串
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <initializer_list>

using namespace std;

bool lessThan(const string &s1, const string &s2){
    if(s1.size() == 0 && s2.size() != 0) return true;
    if(s2.size() == 0) return false;
    string s3 = s1 + s2;
    string s4 = s2 + s1;
    for(int i = 0; i < s3.size(); ++i){
        if(s3[i] > s4[i]){
            return false;
        }
    }
    return true;
}

string func(vector<string> &input){
    sort(input.begin(), input.end(), lessThan);
    string ret;
    for(int i = 0; i < input.size(); ++i){
        ret += input[i];
    }
    return ret;
}

int main(){
    vector<string> input({"b", "ba"});
    string ret = func(input);
    cout<<ret<<endl;
}