#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int maxSumRow(vector<int> &input){
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

int maxSumMatrix(vector<vector<int>> &matrix){
    int rows = matrix.size();
    if(rows == 0) return 0;
    int columns = matrix[0].size();
    if(columns == 0) return 0;
    int ret = INT_MIN;

    for(int i = 0; i < rows; ++i){
        vector<int> sum(columns, 0);
        for(int j = i; j < rows; ++j){
            for(int k = 0; k < columns; ++k){
                sum[k] += matrix[j][k];
            }
            int result = maxSumRow(sum);
            if(result > ret){
                ret = result;
            }
        }
    }

    return ret;
}

int main(){
    vector<vector<int>> matrix({
        {-90, 48, 78},
        {64, -40, 64},
        {-81, -7, 66}
    });
    int ret = maxSumMatrix(matrix);
    cout<<ret<<endl;
}