//数组排序之后相邻数的最大差值
#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int maxGap(vector<int> &input){
    int maxVal = INT_MIN;
    int minVal = INT_MAX;
    for(int i = 0; i < input.size(); ++i){
        maxVal = max(maxVal, input[i]);
        minVal = min(minVal, input[i]);
    }

    if(maxVal == minVal) return 0;

    vector<int> bucket(input.size() + 1);
    vector<int> mins(input.size() + 1), maxs(input.size() + 1);
    vector<bool> hasNum(input.size() + 1, false);
    int len = input.size();

    for(int i = 0; i < input.size(); ++i){
        int bid = (input[i] - minVal)*len/((maxVal - minVal));
        maxs[bid] = hasNum[bid]? max(maxs[bid], input[i]): input[i];
        mins[bid] = hasNum[bid]? min(mins[bid], input[i]): input[i];
        hasNum[bid] = true;
    }

    int ret = 0;

    int i = 0;
    while(hasNum[i] == false){
        ++i;
    }
    int lastMax = maxs[i];

    for(; i < input.size(); ++i){
        if(hasNum[i]){
            ret = max(ret, mins[i] - lastMax);
            lastMax = maxs[i];
        }
    }

    return ret;
}

int main(){
    vector<int> input({5, 5, 5, 5});
    int ret = maxGap(input);
    cout<<ret<<endl;
}