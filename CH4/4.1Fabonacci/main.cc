///共三个问题
///1.用O(logN)复杂度求解斐波那契数列
///2.跨台阶问题
///3.母牛生产问题
#include <assert.h>
#include <iostream>
#include <vector>
#include <initializer_list>
using namespace std;

vector<vector<int>> multiMatrix(vector<vector<int>> &m, vector<vector<int>> &n){
    vector<vector<int>> ret(m.size(), vector<int>(n[0].size(), 0));
    for(int i = 0; i < ret.size(); ++i){
        for(int j = 0; j < ret[0].size(); ++j){
            for(int k = 0; k < m[0].size(); ++k){
                ret[i][j] += m[i][k] * n[k][j];
            }
        }
    }

    return ret;
}

vector<vector<int>> matrixPower(vector<vector<int>> &m, int p){
    vector<vector<int>> ret(m.size(), vector<int>(m.size(), 0));
    for(int i = 0; i < ret.size(); ++i){
        ret[i][i] = 1;
    }

    vector<vector<int> > tmp = m;

    while(p){
        if((p & 1) == 1){
            ret = multiMatrix(ret, tmp);
        }
        tmp = multiMatrix(tmp, tmp);
        p >>= 1;
    }

    return ret;
}

int Fabonacci(int n){
    if(n == 1) return 1;
    if(n == 2) return 1;
    vector<vector<int>> rm({{1, 1}, {1, 0}});
    vector<vector<int>> init({{1, 1}});
    vector<vector<int>> ret;
    
    vector<vector<int>> m = matrixPower(rm, n - 2);
    return m[0][0] + m[0][1];

}

int main(){
    int ret1 = Fabonacci(6);
    cout<<ret1<<endl;
}
