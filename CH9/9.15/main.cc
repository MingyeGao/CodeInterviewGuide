///一种字符串和数字的对应关系
#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

string num2str(vector<char> &letters, int k){
    int bit = 0;
    int current = 1;
    int size = letters.size();
    int remain = k;
    while(remain >= current){
        remain -= current;
        ++bit;
        current *= size;
    }

    string ret(bit, letters[0]);
    int index = 0;
    while(remain != 0){
        int position = remain / current;
        ret[index] = letters[position];
        ++index;
        remain -= current;
        current /= size;
    }

    return ret;
}

int str2num(vector<char> &letters, string s){
    int sig = letters.size();
    unordered_map<char, int> letterValue;
    for(int i = 1; i <= letters.size(); ++i){
        letterValue.insert(make_pair(i, letters[i - 1]));
    }
    int ret = 0;
    int currentSig = 1;
    for(int i = s.size() - 1; i >= 0; --i){
        ret += currentSig + letterValue[letters[i]];
        currentSig *= sig;
    }
    return ret;
}

int main(){
    vector<char> letters({'A', 'B', 'C'});
    string ret = num2str(letters, 40);
    cout<<ret<<endl;
    int ret2 = str2num(letters, "AAAA");
    cout<<ret2<<endl;
}