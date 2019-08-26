///最大的leftmax与rightmax之差的绝对值
#include <iostream>
#include <vector>

using namespace std;

int maxDiff(vector<int> &input){
    if(input.size() == 0) return 0;
    int totalMax = input[0];
    int maxIndex = 0;
    for(int i = 1; i < input.size(); ++i){
        if(input[i] > totalMax){
            totalMax = input[i];
            maxIndex = i;   
        } 
    }

    int last;
    int ret;
    if(maxIndex == 0){
        return totalMax - input[input.size() - 1];
    }

    if(maxIndex == (input.size() - 1)){
        return totalMax - input[0];
    }

    return max(totalMax - input[0], totalMax - input[input.size() - 1]);
}

int main(){
    vector<int> input({2,  7, 3, 1, 1});
    int ret = maxDiff(input);
    cout<<ret<<endl;
}