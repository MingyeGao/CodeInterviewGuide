///判断一个数是否是回文数
#include <iostream>

using namespace std;

bool isPalindromeNum(int N){
    int help = 1;
    while(N / help >= 10){
        help *= 10;
    }

    while(N){
        int leftMost = N/help;
        int rightMost = N%10;
        if(leftMost != rightMost){
            return false;
        }
        N = (N%help)/10;
        help /= 100;
    }

    return true;
}

int main(){
    bool ret = isPalindromeNum(1);
    if(ret){
        cout<<"true"<<endl;
    }
    else{
        cout<<"false"<<endl;
    }
}