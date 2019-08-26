///消息接受并打印的结构设计
#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

class MessageBox{
public:
    MessageBox():expected(1){}
    //unordered_map<int, int> leftmostMap;
    unordered_map<int, int> rightmostMap;
    int expected;
    void print(){
        int start = expected;
        while(1){
            for(int i = start; i <= rightmostMap[start]; ++i){
                cout<<i<<", ";
            }
            start = rightmostMap[start] + 1;
            if(rightmostMap.find(start) == rightmostMap.end()){
                break;
            }
        }
        cout<<endl;
        expected = start;
    }

    void add(int x){
        if(rightmostMap.find(x + 1) != rightmostMap.end()){
            rightmostMap[x] = rightmostMap[x + 1];
        }
        else{
            rightmostMap[x] = x;
        }

        if(x == expected){
            print();
        }
    }
};

int main(){
    MessageBox box;
    vector<int> input({2, 1, 4, 5, 7, 3, 9, 8, 6});
    for(int i : input){
        box.add(i);
    }
}