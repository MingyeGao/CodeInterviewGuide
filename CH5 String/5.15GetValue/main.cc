///公式字符串求值
#include <assert.h>
#include <iostream>
#include <stack>
#include <string>

using namespace std;

int bracket(string &s, int start, int &next){
    stack<int> num;
    stack<int> oper;
    assert(s[start] == '(');
    int ret = 0;
    int i = start + 1;
    for(; s[i] != ')';){
        if(!((s[i] >= '0' && s[i] <= '9') || s[i] == '(')){
            oper.push(s[i]);
            ++i;
        }
        else{
            
            int val = 0;
            if(s[i] == '('){
                int thisNext;
                val = bracket(s, i, thisNext);
                i = thisNext + 1;
            }
            else{
                while(s[i] >= '0' && s[i] <= '9'){
                    val *= 10;
                    val += s[i] - '0';
                    ++i;
                }
            }
            if(oper.empty()){
                num.push(val);
                continue;
            }
            int operTop = oper.top();
            if(operTop == '*' || operTop == '/'){
                int val1 = num.top();
                num.pop();
                if(operTop == '*'){
                    val = val1 * val;
                }
                else{
                    val = val1 / val;
                }
                oper.pop();
            }
            num.push(val);

        }
    }
    next = i;

    while(!num.empty()){
        if(oper.empty() || oper.top() == '+'){
            ret += num.top();
            num.pop();
            if(!oper.empty()){
                oper.pop();
            }
        }
        else{
            ret -= num.top();
            num.pop();
            oper.pop();
        }
    }
    return ret;
}

int func(string &s){
    string str = ('(' + s + ')');
    int next;
    int ret = bracket(str, 0, next);
    return ret; 
}

int main(){
    string str("48*((70-65)-43)+8*1");
    int ret = func(str);
    cout<<ret<<endl;
}