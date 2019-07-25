///只使用递归函数，不使用其他额外的数据结构
///反转一个栈

#include <cstdio>
#include <stack>

using namespace std;

int getAndRemoveBottomElement(stack<int> &s);

void reverseStack(stack<int> &s){
    if(s.empty()) return;

    int bottom = getAndRemoveBottomElement(s);
    reverseStack(s);
    s.push(bottom);

}

int getAndRemoveBottomElement(stack<int> &s){
    int top = s.top();
    int ret;
    s.pop();
    if(s.empty()){
        return top;
    }
    else{
        ret = getAndRemoveBottomElement(s);
        s.push(top);
        return ret;
    }
}

int main(){
    stack<int> s;
    s.push(5);
    s.push(4);
    s.push(3);
    s.push(2);

    reverseStack(s);
    while(!s.empty()){
        printf("%d, ", s.top());
        s.pop();
    }

    printf("\n");
}