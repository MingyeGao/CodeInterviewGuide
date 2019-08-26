///从5随机到7的随机及其扩展
#include <iostream>
#include <cstdlib>
#include <functional>
#include <queue>

using namespace std;

int rand1to5(){
    return random()%5 + 1;
}

int rand1to7(){
    int i;
    do{
        i = 5*(rand1to5()-1) + (rand1to5() - 1);
    }while(i > 20);
    return i%7 + 1;
}


int rand01p(){
    double p = 0.83;
    int tmp = rand()%100;
    return tmp > p*100? 0: 1;
}

///通过rand01p转换获得
///均等地获得0，1
int rand0to1(){
    int tmp;
    do{
        tmp = rand01p();
    }while(tmp == rand01p());

    return tmp;
}

int rand0to3(){
    return 2*rand0to1() + rand0to1();
}

int rand0to15(){
    return 4*rand0to3() + rand0to3();
}

int rand1to6(){
    int tmp;
    do{
        tmp = rand0to15();
    }while(tmp > 11);
    return tmp%6 + 1;
}

int rand1tom(int m){
    return rand()%m + 1;
}


///进制转换，十进制转为n进制
vector<int> dec2n(int x, int n){
    vector<int> ret;
    while(x){
        ret.push_back(x % n);
        x /= n;
    }
    return ret;
}

///进制转换，n进制转换为10进制
int n2dec(vector<int> &num, int n){
    int ret;
    for(int i = 0; i < num.size(); ++i){
        ret *= n;
        ret += num[i];
    }
    return ret;
}

///
vector<int> core(vector<int> &m, int n){
    int index = m.size();
    vector<int> ret(m.size());
    bool lastEqual = true;
    while(index >= 0){
        ret[index] = rand1tom(n) + 1;
        if(lastEqual){
            if(ret[index] > m[index]){
                index = m.size();
                lastEqual = true;
                continue;
            }
            else{
                lastEqual = (ret[index] == m[index]);
            }
        }
        ++index;
    }
    return ret;
}

///通过rand1tom 获得rand1ton
int rand1ton(int m, int n){
    vector<int> nInMSys = dec2n(n - 1, m);
    vector<int> randNum = core(nInMSys, m);
    int ret = n2dec(randNum, m) + 1;
    return ret;
}


int main(){
    for(int i = 0; i < 20; ++i){
        cout<<rand1to7()<<", ";
    }
}