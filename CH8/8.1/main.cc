///转圈打印矩阵
#include <iostream>
#include <vector>
#include <initializer_list>

using namespace std;

void printEdge(vector<vector<int>> &matrix, int t1, int t2, int b1, int b2){
    if(t1 == b1){
        for(int i = t2; i <= b2; ++i){
            cout<<matrix[t1][i]<<", ";
        }
        return;
    }

    if(t2 == b2){
        for(int i = t1; i <= b1; ++i){
            cout<<matrix[i][t2]<<", ";
        }
        return;
    }

    for(int i = t2; i < b2; ++i){
        cout<<matrix[t1][i]<<", ";
    }
    for(int i = t1; i < b1; ++i){
        cout<<matrix[i][b2]<<", ";
    }
    for(int i = b2; i > t2; --i){
        cout<<matrix[b1][i]<<", ";
    }
    for(int i = b1; i > t1; --i){
        cout<<matrix[i][t2]<<", ";
    }
}

void printMatrix(vector<vector<int>> &matrix){
    int rows = matrix.size();
    int columns = matrix[0].size();
    int t1 = 0, t2 = 0, b1 = rows - 1, b2 = columns - 1;
    while(t1 <= b1 && t2 <= b2){
        printEdge(matrix, t1++, t2++, b1--, b2--);    
    }
}

int main(){
    vector<vector<int>> input({
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12},
        {13, 14, 15, 16}
    });
    printMatrix(input);

}