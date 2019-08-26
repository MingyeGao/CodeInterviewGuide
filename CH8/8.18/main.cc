#include <iostream>
#include <vector>
using namespace std;

int func(vector<int> &input){
    if(input.size() == 0) return 0;
    if(input.size() == 1) return input[0];
    if(input.size() == 2) return min(input[0], input[1]);

    if(input[0] < input[1]) return input[0];
    if(input[input.size() - 1] < input[input.size() - 2]) return input[input.size() - 1];

    int left = 1, right = input.size() - 1;
    while(left < right){
        int middle = (right - left)/2 + left;
        if(input[middle] > input[middle - 1]){
            right = middle - 1;
        }
        else if(input[middle] > input[middle + 1]){
            left = middle + 1;
        }
        else{
            return input[middle];
        }
    }

    return input[left];
}

int main(){
    vector<int> input({1, 2, 4, 3, 5});
    int ret = func(input);
    cout<<ret<<endl;
}