///排成一条线的纸牌博弈问题
#include <iostream>
#include <vector>
#include <initializer_list>
#include <algorithm>

using namespace std;

int game(vector<int> &input){
    vector<vector<int> > f(input.size(), vector<int>(input.size(), 0));//play first
    vector<vector<int> > s(input.size(), vector<int>(input.size(), 0));//play second

    for(int i = 0; i < input.size(); ++i){
        f[i][i] = input[i];
        s[i][i] = 0;
    }

    for(int gap = 1; gap <= input.size(); ++gap){
        for(int start = 0; start + gap < input.size(); ++start){
            int val1 = input[start] + s[start + 1][start + gap];
            int val2 = input[start + gap] + s[start][start + gap - 1];
            f[start][start + gap] = max(val1, val2);
            
            int val3 = f[start + 1][start + gap];
            int val4 = f[start][start + gap - 1];
            s[start][start + gap] = min(val3, val4);
        }
    }
    
    return max(f[0][input.size() - 1], s[0][input.size() - 1]);
}

int main(){
    vector<int> input({1, 100, 2});
    int ret = game(input);
    cout<<ret<<endl;
}