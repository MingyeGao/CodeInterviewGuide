#include <cstdio>
#include <stack>

using namespace std;

class MinStack{
public:
    MinStack(){};
    stack<int> dataStack;
    stack<int> minStack;
    bool getMin(int &result){
        if(!minStack.empty()){
            result = minStack.top();
            return true;
        }
        else{
            return false;
        }
    }

    void push(int x){
        dataStack.push(x);
        if(minStack.empty()){
            minStack.push(x);
        }
        else{
            if(x <= minStack.top()){
                minStack.push(x);
            }
        }
    }

    void pop(){
        if(dataStack.top() == minStack.top()){
            minStack.pop();
        }
        dataStack.pop();
    }
};

int main(){
    return 0;
}