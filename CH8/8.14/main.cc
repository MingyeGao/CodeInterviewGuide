///自然数数组的排序
#include <iostream>
#include <vector>

using namespace std;

void sort(vector<int> &input){
    for(int i = 0; i < input.size(); ++i){
        if(input[i] != i + 1){
            int j = i;
            while(input[j] != j + 1){
                int tmp = input[j] - 1;
                input[j] = j + 1;
                j = tmp;
            }
        }
    }
}

int main(){
    vector<int> input({1, 5, 2, 4, 3});
    sort(input);

    for(auto i : input){
        cout<<i<<", ";
    }
}