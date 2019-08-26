#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int maxMulti(vector<double> &input){
    double maxVal = 1, minVal = 1;
    double ret = INT_MIN;
    for(auto i : input){
        if(i == 0){
            maxVal = 1;
            minVal = 1;
            continue;
        }

        if(i > 0){
            maxVal *= i;
        }
        else{
            double tmp = maxVal;
            maxVal = minVal * i;
            minVal = maxVal * i;
        }

        if(maxVal > ret){
            ret = maxVal;
        }
    }

    return ret;
}

int main(){
    vector<double> input({-2.5, 4, 0, 3, 0.5, 8, -1});
    double ret = maxMulti(input);
    cout<<ret<<endl;
}