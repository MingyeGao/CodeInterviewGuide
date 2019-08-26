///数组中的最长连续序列
#include <assert.h>
#include <iostream>
#include <vector>
#include <initializer_list>
#include <map>

using namespace std;

int combine(map<int, int> &mapIndexLength, int former, int latter){
    assert(former == (latter - 1));

    int len1 = mapIndexLength[former];
    int len2 = mapIndexLength[latter];
    int left = former - len1 + 1;
    int right = latter + len1 - 1;
    mapIndexLength[left] = len1 + len2;
    mapIndexLength[right] = len1 + len2;
    return len1+len2;
}

int LCS(vector<int> &input){
    map<int, int> mapIndexLength;
    int maxLen = 0;
    for(int i = 0; i < input.size(); ++i){
        if(mapIndexLength.find(input[i]) != mapIndexLength.end()){
            continue;
        }
        else{
            mapIndexLength[input[i]] = 1;
            if(mapIndexLength.find(input[i] - 1) != mapIndexLength.end()){
                int newLen = combine(mapIndexLength, input[i] - 1, input[i]);
                if(newLen > maxLen) maxLen = newLen;
            }

            if( mapIndexLength.find(input[i] + 1) != mapIndexLength.end()){
                int newLen = combine(mapIndexLength, input[i], input[i] + 1);
                if(newLen > maxLen) maxLen = newLen;
            }
        }
    }

    return maxLen;
}

int main(){
    vector<int> input({100, 4, 200, 1, 3, 2});
    int ret = LCS(input);
    cout<<ret<<endl;
}
