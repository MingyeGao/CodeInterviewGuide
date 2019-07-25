///仅用一个辅助栈，为一个栈排序，
///从栈顶到到栈底，从大到小

#include <cstdio>
#include <stack>

using namespace std;

void helpfunc(stack<int> &s, int i);

void sortStackByStack(stack<int> &s){
    stack<int> helper;
    while(!s.empty()){
        int top = s.top();
        s.pop();
        helpfunc(helper, top);
    }

    while(!helper.empty()){
        s.push(helper.top());
        helper.pop();
    }
    
}

void helpfunc(stack<int> &s, int i){
    if(s.empty() || i <= s.top()){
        s.push(i);
        return;
    }
    else{
        int top = s.top();
        s.pop();
        helpfunc(s, i);
        s.push(top);
    }
}

int main(){
    stack<int> s;
    s.push(3);
    s.push(1);
    s.push(2);
    s.push(5);
    s.push(4);
    sortStackByStack(s);
    while(!s.empty()){
        printf("%d, ", s.top());
        s.pop();
    }
}