#include <iostream>
#include <vector>

using namespace std;

bool func(vector<vector<int>> &input, int k){
    int rows = input.size();
    int columns = input[0].size();

    int i = 0, j = columns - 1;
    while(i < rows && j >= 0){
        if(input[i][j] == k){
            return true;
        }

        if(input[i][j] > k){
            --j;
        }
        else{
            ++i;
        }
    }

    return false;
}

int main(){
    vector<vector<int>> input({
        {0, 1, 2, 5},
        {2, 3, 4, 7},
        {4, 4, 4, 8},
        {5, 7, 7, 9}
    });
    bool ret = func(input, 10);
    if(ret){
        cout<<"true"<<endl;
    }
    else{
        cout<<"false"<<endl;
    }
}