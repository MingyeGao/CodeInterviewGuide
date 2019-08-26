///丢棋子问题
#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int solution1(int nHeight, int nChessNum){
    vector<vector<int> > dp(nHeight + 1, vector<int>(nChessNum + 1));
    for(int i = 0; i <= nChessNum; ++i){
        dp[0][i] = 0;
    }

    for(int i = 0; i <= nHeight; ++i){
        dp[i][1] = i;
    }

    for(int i = 1; i <= nHeight; ++i){
        for(int j = 2; j <= nChessNum; ++j){
            int minVal = INT_MAX;
            for(int k = 1; k != i + 1; ++k){
                minVal = min(minVal, max(dp[k - 1][j - 1], dp[i - k][j]) + 1);
            }
            dp[i][j] = minVal;
        }
    }

    return dp[nHeight][nChessNum];
}

int logN(int N){
    int ret = -1;
    while(N){
        ++ret;
        N >>= 1;
    }

    return ret;
}

int solution2(int nHeight, int nChessNum){
    if(nHeight < 1 || nChessNum < 1){
        return 0;
    }

    int bsTimes = logN(nHeight) + 1;
    if(nChessNum > bsTimes){
        return bsTimes;
    }

    vector<int> dp(nChessNum, 0);
    int ret = 0;
    while(true){
        ret++;
        int previous = 0;
        for(int i = 0; i < nChessNum; ++i){
            int tmp = dp[i];
            dp[i] = dp[i] + previous + 1;
            previous = tmp;
            if(dp[i] >= nHeight){
                return ret;
            }
        }
    }
}

int main(){
    int ret = solution1(105, 2);
    cout<<ret<<endl;
}