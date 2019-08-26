#include <iostream>
#include <vector>
#include <initializer_list>

using namespace std;

void rotateMatrix(vector<vector<int>> &matrix, int tR, int tC, int bR, int bC){
    int time = bC - tC;
    for(int i = 0; i < time; ++i){
        int tmp = matrix[tR][tC + i];
        matrix[tR][tC + i] = matrix[bR - i][tC];
        matrix[bR - i][tC] = matrix[bR][bC - i];
        matrix[bR][bC - i] = matrix[tR + i][bC];
        matrix[tR + i][bC] = tmp;
    }
}

void rotateMatrix(vector<vector<int>> &matrix){
    int tR = 0, tC = 0, bR = matrix.size() - 1, bC = matrix[0].size() - 1;
    while(tR <= bR && tC <= bC){
        rotateMatrix(matrix, tR++, tC++, bR--, bC--);
    }
}

int main(){
    vector<vector<int>> matrix({
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12},
        {13, 14, 15, 16}
    });

    rotateMatrix(matrix);
    for(int i = 0; i < matrix.size(); ++i){
        for(int j = 0; j < matrix[0].size(); ++j){
            cout<<matrix[i][j]<<", ";
        }
        cout<<endl;
    }
}