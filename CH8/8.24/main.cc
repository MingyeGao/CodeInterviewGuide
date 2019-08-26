#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int Core(vector<vector<int>> &input, int i, int j, int &sum){
    if((i == input.size() && j == input[0].size() - 1) || 
    (i == input.size() - 1 && j == input[0].size())){
        return sum - 1;
    }

    if(i >= input.size() || i < 0 || j >= input[0].size() || j < 0){
        return INT_MAX;
    }

    if(input[i][j] == 0){
        return INT_MAX;
    }

    

    input[i][j] = 0;
    sum++;
    int ret1 = Core(input, i + 1, j, sum);
    int ret2 = Core(input, i, j + 1, sum);
    int ret3 = Core(input, i - 1, j, sum);
    int ret4 = Core(input, i, j - 1, sum);
    int ret = min(ret1, ret2);
    ret = min(ret, ret3);
    ret = min(ret, ret4);
    sum--;
    input[i][j] = 1;
    return ret;
}

int getMinPath(vector<vector<int>> &input){
    int sum = 0;
    int ret = Core(input, 0, 0, sum);
    return ret;
}

int main(){
    vector<vector<int>> input({
        {1, 0, 1, 1, 1},
        {1, 0, 1, 0, 1},
        {1, 1, 1, 0, 1},
        {0, 0, 0, 0, 1}
    });

    // vector<vector<int>> input({
    //     {1, 1},
    //     {1, 1}
    // });

    int ret = getMinPath(input);
    cout<<ret<<endl;
}