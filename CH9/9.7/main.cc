///蓄水池算法
#include <iostream>
#include <vector>

using namespace std;

vector<int> getRandom(int N, int k){
    vector<int> ret(k, 0);
    for(int i = 0; i < N; ++i){
        if(i < k){
            ret[i] = i + 1;
        }
        else{
            int tmp = rand()%i;
            if(tmp < k) continue;

            int index = rand()%k;
            ret[index] = i + 1;
        }
    }
    return ret;
}

int main(){
    
}