///调整[0,x)区间上的数出现的概率
#include <iostream>
#include <cstdlib>

using namespace std;

double rand0to1(){
    return (double)(rand()%1000)/1000.0;
}

double randXPowerK(int k){
    double maxVal = -1;
    for(int i = 0; i < k; ++i){
        double tmp = rand0to1();
        maxVal = max(maxVal, tmp);
    }
    return maxVal;
}

int main(){
    for(int i = 0; i < 10; ++i){
        cout<<randXPowerK(5)<<endl;
    }
    
}