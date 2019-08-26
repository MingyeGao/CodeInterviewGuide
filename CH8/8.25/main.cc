///数组中未出现的最小正整数
#include <iostream>
#include <vector>

using namespace std;

int minNum(vector<int> input){
    int l = 0, r = input.size();
    while(l < r){
        if(input[l] == l + 1){
            l++;
        }
        else if(input[l] <= l || input[l] > r || input[input[l] - 1] == input[l]){
            input[l] = input[r--];
        }
        else{
            swap(input[l], input[input[l] - 1]);
        }
    }
    return l + 1;
}

int main(){
    vector<int> input({-1, 2, 3, 4});
    int ret = minNum(input);
    cout<<ret<<endl;
}