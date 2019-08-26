//花匠问题
#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int solution(vector<int> &input, int n){
    int sum = 0;
    for(auto i : input){
        sum += i;
    }

    int llimit = 1, rlimit = sum;
    int mlimit;
    int ret;
    while(llimit < rlimit){
        ret = INT_MIN;
        mlimit = (rlimit - llimit)/2 + llimit;
        int requiredNum = 1;
        int acc = 0;
        for(int i = 0; i < input.size(); ++i){
            if(input[i] > mlimit){
                llimit++;
                break;
            }

            if(acc + input[i] > mlimit){
                requiredNum++;
                acc = input[i];
                ret = max(ret, acc);
            }
            else{
                acc += input[i];
                ret = max(ret, acc);
            }
        }

        if(requiredNum == n){
            return ret;
        }
        else if(requiredNum < n){
            rlimit = mlimit - 1;
        }
        else{
            llimit = mlimit + 1;
        }
    }
}

int main(){
    vector<int> input({3, 1, 4});
    int ret = solution(input, 3);
    cout<<ret<<endl;
}