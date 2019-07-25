///经典汉诺塔问题

#include <iostream>
#include <string>

using namespace std;

void hanoiCore(int n, string &from, string &to, string &via){
    if(n == 1){
        cout << "move 1 from " << from << " to "<< to << endl;
    }
    else{
        hanoiCore(n - 1, from, via, to);
        cout << "move " << n << " from " << from << " to " << to << endl;
        hanoiCore(n - 1, via, to, from);
    }
}

void hanoi(int n){
    string left("left");
    string right("right");
    string middle("middle");
    hanoiCore(n, left, right, middle);
}

int main(){
    int kHanoiLevel = 3;
    hanoi(kHanoiLevel);
}