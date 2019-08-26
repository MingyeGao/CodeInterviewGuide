///数组的partition调整
#include <iostream>
#include <vector>

using namespace std;

int func(vector<int> &input){
    if(input.size() <= 1) return input.size() - 1;

    int val = input[0];
    int i = 1, j = 1;
    while(j < input.size()){
        if(input[j] != val){
            val = input[j];
            swap(input[i], input[j]);
            ++i;
            ++j;
        }
        else{
            ++j;
        }
    }

    return i - 1;
}

void func2(vector<int> &input){
    int i = 0, j = input.size() - 1;
    int k = 0;
    while(k <= j){
        if(input[k] == 0){
            swap(input[i], input[k]);
            ++i;
        }
        else if(input[k] == 2){
            swap(input[k], input[j]);
            --j;
        }
        else{
            ++k;
        }
        
    }
}

int main(){
    vector<int> input({1, 2, 2, 2, 3, 3, 4, 5, 6, 6, 7, 7, 8, 8, 9});
    int ret = func(input);
    for(int i = 0; i <= ret; ++i){
        cout<<input[i]<<", ";
    }
    cout<<endl;

    vector<int> input2({1, 2, 0, 1, 2, 0, 0, 2, 1});
    func2(input2);
    for(int i : input2){
        cout<<i<<", ";
    }
}