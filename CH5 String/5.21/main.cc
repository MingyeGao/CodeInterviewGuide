///最小包含子串的长度
#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <climits>

using namespace std;

int func(string &s1, string &s2){
    if(s2.size() == 0) return 0;
    if(s1.size() < s2.size()) return 0;
    int left = 0, right = left;
    int diff = s2.size();
    unordered_map<char, int> s2map;
    int ret = INT_MAX;

    for(int i = 0; i < s2.size(); ++i){
        if(s2map.find(s2[i]) == s2map.end()){
            s2map[s2[i]] = 1;
        }
        else{
            s2map[s2[i]]++;
        }
    }

    while(s2map.find(s1[left]) == s2map.end()){
        ++left;  
    }
    right = left;

    while(right < s2.size()){
        while(diff > 0 && right < s1.size()){
            if(s2map.find(s1[right]) != s2map.end()){
                if(s2map[s1[right]] > 0){
                    diff--;
                }
                s2map[s1[right]]--;
            }
            if(diff != 0) right++;
        }
        if(diff == 0 && right - left + 1 < ret){
            ret = right - left + 1;
        }
        while(right < s1.size() && left < right && diff == 0){
            if(s2map.find(s1[left]) != s2map.end()){
                ++s2map[s1[left]];
                if(s2map[s1[left]] > 0){
                    ++diff;
                }
            }
            ++left;
            if(diff == 0){
                if(ret > (right - left + 1)){
                    ret = right - left + 1;
                }
            }
        }
    }
    
    if(ret == INT_MAX) return 0;
    return ret;
}

int main(){
    string s1 = "aabbccde", s2 = "ac";
    int ret = func(s1, s2);
    cout<<ret<<endl;
}