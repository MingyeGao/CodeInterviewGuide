///路径数组变为统计数组
#include <iostream>
#include <vector>
using namespace std;

void pathToDistance(vector<int> &input){
    int cap;
    for(int i = 0; i < input.size(); ++i){
        if(input[i] == i){
            cap = i;
            continue;
        }

        if(input[i] > -1){
            int prev = i;
            int current = input[i];  
            input[i] = -1;
                      
            while(input[current] != current){
                if(input[current] <= -1){
                    break;
                }
                else{
                    int next = input[current];
                    input[current] = prev;
                    prev = current;
                    current = next;
                }
            }

            int val = (input[current] == current)? 0: input[current];
            current = prev;
            while(input[current] != -1){
                prev = input[current];
                input[current] = --val;
                current = prev;
            }
            input[current] = --val;
        }
    }
    input[cap] = 0;
}

void distanceToNums(vector<int> &input){
    for(int i = 0; i < input.size(); ++i){
        if(input[i] > 0){
            continue;
        }

        int distance = input[i];
        input[i] = 0;
        int next = -distance;
        while(input[next] < 0){
            distance = input[next];
            input[next] = 1;
            next = -distance;
        }
        ++input[next];
    }
    //for(int i = 0; i < input.size(); ++i)
    input[0] = 1;
}

void pathToNums(vector<int> &input){
    if(input.size() == 0) return;
    pathToDistance(input);
    distanceToNums(input);
}

int main(){
    vector<int> input({9, 1, 4, 9, 0, 4, 8, 9, 0, 1});
    pathToNums(input);
    for(auto i : input){
        cout<<i<<", ";
    }
}