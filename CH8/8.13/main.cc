#include <iostream>
#include <vector>

using namespace std;

void mergeSort(vector<int> &input, int s1, int e1, int s2, int e2, int &sum){
    if(s1 != e1){
        int middle =(e1 - s1)/2 + s1;
        mergeSort(input, s1, middle, middle + 1, e1, sum);
    }
    if(s2 != e2){
        int middle = (e2 - s2)/2 + s2;
        mergeSort(input, s2, middle, middle + 1, e2, sum);
    }

    int i = s1, j = s2;
    while(i <= e1 && j <= e2){
        if(input[i] <= input[j]){
            sum += (input[i])*(e2 - j + 1);
            ++i;
        }
        else{
            ++j;
        }
    }

    vector<int> tmp(e1 - s1 + 1 + e2 - s2 + 1);
    int k = 0;
    i = s1, j = s2;
    while(k < tmp.size()){
        if(i > e1 || input[i] > input[j]){
            tmp[k++] = input[j++];
            continue;
        }
        else{
            tmp[k++] = input[i++];
            continue;
        }
        
    }
}

int func(vector<int> &input){
    vector<int> tmp(input.begin(), input.end());
    int sum = 0;
    int middle = (tmp.size() - 1)/2;
    mergeSort(tmp, 0, middle, middle + 1, tmp.size() - 1, sum);
    return sum;
}

int main(){
    vector<int> input({1, 3, 5, 2, 4, 6});
    int ret = func(input);
    cout<<ret<<endl;
}