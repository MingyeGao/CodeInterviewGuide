///替换字符串中连续出现的指定字符串
#include <iostream>
#include <string>
#include <list>

using namespace std;

string replaceString(string &str, string &from, string &to){
    list<int> replaceStart;
    string ret;
    int i = 0, j = 0;
    for(; i < str.size(); ++i){
        if(str[i] == from[j]){
            ++j;
            if(j == from.size()){
                replaceStart.push_back(i - j + 1);
                j = 0;
            }
        }
        else{
            j = 0;
        }
    }
    int index = 0;
    while(!replaceStart.empty()){
        int tmp = replaceStart.front();
        replaceStart.pop_front();
        ret += str.substr(index, tmp - index);
        ret += to;
        index = tmp + from.size();
    }
    
    ret += str.substr(index, str.size() - index);
    return ret;
}

int main(){
    string s("123abc"), from("abc"), to("4567");
    string ret = replaceString(s, from, to);
    cout<<ret<<endl;
}