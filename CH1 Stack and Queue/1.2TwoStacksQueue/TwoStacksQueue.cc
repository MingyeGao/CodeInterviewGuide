#include <stack>

using namespace std;

class TwoStacksQueue{
public:
    TwoStacksQueue(){};
    stack<int> stackPush;
    stack<int> stackPop;

    //return front element and pop 
    int pop(){
        if(!stackPop.empty()){
            int ret = stackPop.top();
            stackPop.pop();
            return ret;
        }
        else{
            if(stackPush.empty()){
                throw "stack empty";
            }
            else{
                while(!stackPush.empty()){
                    int tmp = stackPush.top();
                    stackPush.pop();
                    stackPop.push(tmp);
                }

                int ret = stackPop.top();
                stackPop.pop();
                return ret;
            }
        }
    }

    void push(int x){
        stackPush.push(x);
    }

    int front(){
        if(!stackPop.empty()){
            return stackPop.top();
        }
        else{
            if(stackPush.empty()){
                throw  "empty stack";
            }
            else{
                while(!stackPush.empty()){
                    int tmp = stackPush.top();
                    stackPush.pop();
                    stackPop.push(tmp);
                }
                return stackPop.top();
            }
        }
    }
};

int main(){
    TwoStacksQueue queue;
    queue.pop();
}