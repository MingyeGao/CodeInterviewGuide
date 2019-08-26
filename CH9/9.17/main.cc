///从N个数中等概率打印M个数
#include <iostream>
#include <vector>
#include <cstdlib>

using namespace std;

vector<int> printMRandomly(vector<int> &candidates, int m){
    int size = candidates.size();
    vector<int> ret(m);
    for(int i = 0; i < m; ++i){
        int index = rand()%(m - i);
        ret[i] = candidates[index];
        swap(candidates[index], candidates[m - i - 1]);
    }
    return ret;
}

int main(){
    
}