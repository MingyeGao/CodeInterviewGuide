#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int maxSum(vector<int> &input){
    int ret = INT_MIN;
    int sum = 0;
    for(int i = 0; i < input.size(); ++i){
        sum += input[i];
        if(sum > ret){
            ret = sum;
        }

        if(sum < 0){
            sum = 0;
        }
    }

    return ret;
}

int main(){
    vector<int> input({1, -2, 3, 5, -2, 6, -1});
    int ret = maxSum(input);
    cout<<ret<<endl;
}