///边界都是1的正方形大小
#include <iostream>
#include <vector>

using namespace std;

int func(vector<vector<int>> &input){
    int N = input.size();
    if(N == 0) return 0;
    int ret = 0;
    vector<vector<int> > right(N, vector<int>(N, 0)), down(N, vector<int>(N, 0));
    for(int i = N - 1; i >= 0; --i){
        for(int j = N - 1; j >= 0; --j){
            if(j == N - 1){
                right[i][j] = (input[i][j] == 0)? 0: 1;
            }
            else{
                right[i][j] = (input[i][j] == 0)? 0: right[i][j + 1] + 1; 
            }

            if(i == N - 1){
                down[i][j] = (input[i][j] == 0)? 0: 1;
            }
            else{
                down[i][j] = (input[i][j] == 0)? 0: down[i + 1][j] + 1;
            }
        }
    }

    for(int i = 0; i < N; ++i){
        for(int j = 0; j < N; ++j){
            if(input[i][j] == 0){
                continue;
            }

            int rLen = right[i][j];
            int dLen = down[i][j];
            int Len = min(rLen, dLen);

            if(down[i][j + Len - 1] >= Len && right[i + Len - 1][j] >= Len){
                ret = max(ret, Len);
            }
        }
    }

    return ret;
}

int main(){
    vector<vector<int> > input({
        {0, 1, 1, 1, 1},
        {0, 1, 0, 0, 1},
        {0, 1, 0, 0, 1},
        {0, 1, 1, 1, 1},
        {0, 1, 0, 1, 1}
    });

    int ret = func(input);
    cout<<ret<<endl;
}