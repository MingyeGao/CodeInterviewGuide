///表达式得到期望结果的组成种数
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int func(string &s, bool desired){
    if(s.size()%2 == 0) return 0;

    vector<vector<int> > t(s.size(), vector<int>(s.size()));
    vector<vector<int> > f(s.size(), vector<int>(s.size()));

    t[0][0] = (s[0] == '1')?1:0;
    f[0][0] = (s[0] == '1')?0:1;

    for(int i = 2; i < s.size(); i += 2){
        if(!(s[i] >= '0' && s[i] <= '9')) return -1;
        t[i][i] = (s[i] == '1')?1:0;
        f[i][i] = (s[i] == '0')?1:0;
        for(int j = i - 2; j >= 0; j -= 2){
            if(!(s[j] >= '0' && s[j] <= '9')) return -1;
            for(int k = j + 1; k < i; k += 2){
                switch (s[k]){
                    case '&':
                        t[j][i] += t[j][k - 1]*t[k + 1][i]; 
                        f[j][i] += t[j][k - 1]*f[k + 1][i] + f[j][k - 1]*f[k + 1][i] + f[j][k - 1]*t[k + 1][i]; 
                        break;
                    case '|':
                        t[j][i] += t[j][k - 1]*t[k + 1][i] + f[j][k - 1]*t[k + 1][i] + t[j][k - 1]*f[k + 1][i];
                        f[j][i] += f[j][k - 1]*f[k + 1][i];
                        break;
                    case '^':
                        t[j][i] = t[j][k - 1]*f[k + 1][i] + f[j][k - 1]*t[k + 1][i];
                        f[j][i] = t[j][k - 1]*t[k + 1][i] + f[j][k - 1]*f[k + 1][i];
                        break;
                    default:
                        return -1;
                }
            }
        }
    }

    return desired?t[0][s.size() - 1]:f[0][s.size() - 1];
}

int main(){
    string s("1^0|0|1");
    int ret = func(s, false);
    cout<<ret<<endl;
}