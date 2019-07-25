#include <assert.h>
#include <iostream>
#include <vector>
#include <string>

using namespace std;

void getNext(string match, vector<int> &next){
    assert(match.size() == next.size());
    next[0] = -1;
    next[1] = 0;
    int pos = 2;
    int cn = 0;

    while(pos < match.size()){
        if(match[pos - 1] == match[cn]){
            match[pos++] = ++cn;
        }
        else if(cn > 0){
            cn = match[cn];
        }
        else{
            match[pos++] = 0;
        }
    }
}

int kmp(string &s, string &match){
    int sIndex = 0, mIndex = 0;
    vector<int> next(match.size());
    getNext(match, next);
    while(sIndex < s.size()){
        if(s[sIndex] == match[mIndex]){
            ++sIndex;
            ++mIndex;
            if(mIndex > match.size()){
                return (sIndex - match.size());
            }
        }
        else if (next[mIndex] > 0){
            mIndex = next[mIndex] + 1;
        }
        else{
            mIndex = 0;
            ++sIndex;
        }
    }

    return -1;
}