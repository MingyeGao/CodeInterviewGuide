#include <iostream>
#include <deque>
#include <vector>
#include <initializer_list>

using namespace std;

vector<int> getMaxWindow(vector<int> &input, int windowSize){
    deque<int> qmax;
    vector<int> ret;
    for(int i = 0; i < windowSize - 1; ++i){
        while(!qmax.empty() && input[qmax.back()] < input[i]){
            qmax.pop_back();
        }

        qmax.push_back(i);
    }

    for(int i = windowSize-1; i < input.size(); ++i){
        if(qmax.front() == (i - windowSize)){
            qmax.pop_front();
        } 

        while(!qmax.empty() && input[qmax.back()] < input[i]){
            qmax.pop_back();
        }
        qmax.push_back(i);

        ret.push_back(input[qmax.front()]);
    }

    return ret;
    
}

int main(){
    vector<int> input({4, 3, 5, 4, 3, 3, 6, 7});
    vector<int> ret = getMaxWindow(input, 3);
    for(auto i : ret){
        cout<< i << ", ";
    }
    cout<<endl;
}

