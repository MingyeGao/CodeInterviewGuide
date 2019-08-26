///最长的可整合数组长度
#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

int getLIL(vector<int> &input){
    int len = 0;
    int maxVal;
    int minVal;
    unordered_set<int> s;
    for(int i = 0; i < input.size(); ++i){
        maxVal = input[i];
        minVal = input[i];
        for(int j = i; j < input.size(); ++j){
            if(s.find(input[j]) != s.end()){
                break;
            }
            s.insert(input[j]);
            if(input[j] > maxVal){
                maxVal = input[j];
            }
            if(input[j] < minVal){
                minVal = input[j];
            }
            if((maxVal - minVal) == (j - i)){
                len = max(len, maxVal - minVal + 1);
            }
        }
        s.clear();
    }

    return len;
}

int main(){
    vector<int> input({5, 5, 3, 2, 6, 4, 3});
    int ret = getLIL(input);
    cout<<ret<<endl;
}