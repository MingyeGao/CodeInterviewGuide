///去掉字符串中连续出现k个0的子串
#include <iostream>
#include <vector>
#include <string>
#include <list>
using namespace std;

string func(string &s, int n){
    list<int> startPosition;
    int start = 0;
    int count = 0;
    for(int i = 0; i < s.size(); ++i){
        if(s[i] == '0'){
            if(start == -1){
                start = i;
            }
            ++count;
        }
        else{
            if(count == n){
                startPosition.push_back(i - n);
            }
            count = 0;
            start = -1;
        }
    }
    if(count == n){
        startPosition.push_back(s.size() - n);
    }

    string ret;
    int index = 0;
    while(!startPosition.empty()){
        ret += s.substr(index, startPosition.front() - index);
        index = startPosition.front() + n;
        startPosition.pop_front();
    }
    if(index != s.size()){
        ret += s.substr(index, s.size() - index);
    }

    return ret;
}

int main(){
    string s("A0000B000");
    string ret = func(s, 3);
    cout<<ret<<endl;
}