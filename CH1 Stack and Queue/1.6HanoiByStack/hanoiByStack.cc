///用栈实现汉诺塔问题
///额外限制：每次移动圆盘， 只能移向相邻的

#include <iostream>
#include <stack>

using namespace std;

void hanoiByStack(int n){
    stack<int> leftStack;
    stack<int> rightStack;
    stack<int> middleStack;

    enum transState{LM = 0, ML, MR, RM};

    transState lastState = RM;

    for(int i = n; i >= 1; --i){
        leftStack.push(i);
    }

    while(rightStack.size() != n){
        if(!leftStack.empty() && lastState != ML){
            if(middleStack.empty() || (leftStack.top() < middleStack.top())){
                int leftTop = leftStack.top();
                leftStack.pop();
                middleStack.push(leftTop);
                cout<<"move "<<leftTop<<" from left to middle"<<endl;
                lastState = LM;
                continue;
            }
        }

        if(!rightStack.empty() && lastState != MR){
            if(middleStack.empty() || (middleStack.top() > rightStack.top())){
                int rightTop = rightStack.top();
                rightStack.pop();
                middleStack.push(rightTop);
                cout<<"move "<<rightTop<<" from right to middle"<<endl;
                lastState = RM;
                continue;
            }
        }

        {
            int middleTop = middleStack.top();
            middleStack.pop();
            if(lastState == RM){
                leftStack.push(middleTop);
                cout<<"move "<<middleTop<<" from middle to left"<<endl;
                lastState = ML;
                continue;
            }
            else{
                rightStack.push(middleTop);
                cout<<"move "<<middleTop<<" from middle to right"<<endl;
                lastState = MR;
            }
        }
        
    }

    
}

int main(){
    hanoiByStack(3);
}