///最大值减去最小值小于或等于num的子数组数量


#include <iostream>
#include <vector>
#include <initializer_list>
#include <queue>

using namespace std;

int getNum(vector<int> &input, int num){
    if(input.size() == 0) return 0;
    deque<int> qmax, qmin;
    int i = 0, j = 0;
    int ret = 0;
    while(i < input.size()){
        while(j < input.size()){
            while(!qmax.empty() && input[qmax.back()] <= input[j]){
                qmax.pop_back();
            }
            qmax.push_back(j);

            while(!qmin.empty() && input[qmin.back()] >= input[j]){
                qmin.pop_back();
            }
            qmin.push_back(j);

            if((input[qmax.front()] - input[qmin.front()]) <= num){
                ++j;
            }
            else{
                break;
            }
        }
        ret += (j - i);
        if(qmax.front() == i){
            qmax.pop_front();
        }
        if(qmin.front() == i){
            qmin.pop_front();
        }
        ++i;
    }
    

    return ret;
}

int main(){
    vector<int> input({1, 2, 3, 4, 5});
    int ret = getNum(input, 1);
    cout<<ret<<endl;
}