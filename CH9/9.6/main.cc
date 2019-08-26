///折纸问题
#include <iostream>

using namespace std;

void printCurrentLevel(int i, int N, bool down){
    if(i > N) return;

    printCurrentLevel(i + 1, N, true);
    if(down){
        cout<<"down"<<", ";
    }
    else{
        cout<<"up"<<", ";
    }
    printCurrentLevel(i + 1, N, false);
}

void printFolds(int N){
    printCurrentLevel(1, N, true);
}

int main(){
    printFolds(2);
}