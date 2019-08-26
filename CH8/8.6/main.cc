#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <initializer_list>
#include <map>
#include <unordered_map>

using namespace std;


///在输入中找到出现次数多于一半的数
int func1(vector<int> &input){
    int times = 0;
    int cand = 0;
    for(int i = 0; i < input.size(); ++i){
        if(times == 0){
            cand = input[i];
            times++;
        }
        else if(input[i] == cand){
            times++;
        }
        else{
            times--;
        }
    }

    times = 0;
    for(int i = 0; i < input.size(); ++i){
        if(input[i] == cand){
            ++times;
        }
    }
    if(times > input.size()/2){
        return cand;
    }
        
    cout<<"no such element"<<endl;
    return -1;
}

///在输入数组中找到出现次数大于N/k的元素
vector<int> func2(vector<int> &input, int k){
    unordered_map<int, int> mapIndexTime;
    int candNum = 0;
    for(int i = 0; i < input.size(); ++i){
        if(mapIndexTime.find(input[i]) == mapIndexTime.end()){
            if(candNum == k - 1){
                for(auto element : mapIndexTime){
                    element.second--;
                    if(element.second == 0){
                        mapIndexTime.erase(element.first);
                        candNum--;
                    }
                }
            }
            else{
                mapIndexTime[input[i]] = 1;
                candNum++;
            }
        }
        else{
            mapIndexTime[input[i]]++;
        }
    }

    unordered_map<int, int> timeMap;
    for(auto i : input){
        if(mapIndexTime.find(i) != mapIndexTime.end()){
            if(timeMap.find(i) == timeMap.end()){
                timeMap[i] = 1;
            }
            else{
                timeMap[i]++;
            }
        }
    }

    vector<int> ret;
    for(auto it : timeMap){
        if(it.second > input.size()/k){
            ret.push_back(it.first);
        }
    }

    return ret;
}

int main(){
    vector<int> input({1, 1, 1, 2, 2, 2});
    vector<int> ret = func2(input, 3);
    for(auto i : ret){
        cout<<i<<", ";
    }
}