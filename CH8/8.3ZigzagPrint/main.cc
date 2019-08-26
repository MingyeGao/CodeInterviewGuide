///之字形打印矩阵
#include <iostream>
#include <vector>

using namespace std;

void zigzagPrint(vector<vector<int>> &matrix){
    int r1 = 0, c1 = 0, r2 = 0, c2 = 0;
    int rows = matrix.size(), columns = matrix[0].size();
    bool upDown = false;
    while(!(r1 == rows - 1 && r2 == rows - 1 && c1 == columns - 1 && c2 == columns - 1)){
        if(upDown){
            int r3 = r1, c3 = c1;
            while(r3 <= r2 && c3 >= c2){
                cout<<matrix[r3][c3]<<", ";
                ++r3;
                --c3;
            }
            
        }
        else{
            int r3 = r2, c3 = c2;
            while(r3 >= r1 && c3 <= c1){
                cout<<matrix[r3][c3]<<", ";
                --r3;
                ++c3;
            }
            
        }

        upDown = upDown?false:true;
        if(c1 < columns - 1){
            ++c1;
        }
        else{
            ++r1;
        }

        if(r2 < rows - 1){
            ++r2;
        }
        else{
            ++c2;
        }
    }

    cout<<matrix[rows - 1][columns - 1]<<", ";
}

int main(){
    vector<vector<int>> matrix({
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12}
    });

    zigzagPrint(matrix);
}