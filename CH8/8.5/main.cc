///需要排序的最短子数组长度

#include <iostream>
#include <vector>

using namespace std;

int func(vector<int> &input){
    if(input.size() <= 1) return 0;

    int noMinIndex = -1;
    int minVal = input[input.size() - 1];
    for(int i = input.size() - 1; i >= 0; --i){
        if(input[i] > minVal){
            noMinIndex = i;
        }
        else{
            minVal = min(minVal, input[i]);
        }
    }

    if(noMinIndex == -1) return 0;

    int noMaxIndex = -1;
    int maxVal = input[0];
    for(int i = 0; i < input.size(); ++i){
        if(input[i] < maxVal){
            noMaxIndex = i;
        }
        else{
            maxVal = max(maxVal, input[i]);
        }
    }

    return noMaxIndex - noMinIndex + 1;
}

int main(){
    vector<int> input({1, 5, 3, 4, 2, 6, 7});
    int ret = func(input);
    cout<<ret<<endl;
}