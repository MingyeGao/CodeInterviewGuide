///跳跃游戏
#include <iostream>
#include <vector>
#include <initializer_list>

using namespace std;

int jumpGame(vector<int> &input){
    int step = 0;
    int next = 0;
    int currentMaxPosition = 0;
    for(int i = 0; i < input.size(); ++i){
        if(currentMaxPosition < i){
            currentMaxPosition = next;
            ++step;
        }
        next = max(next, i + input[i]);
    }
    return step;
}

int main(){
    vector<int> input({3, 2, 3, 1, 1, 4});
    int ret = jumpGame(input);
    cout<<ret<<endl;
}