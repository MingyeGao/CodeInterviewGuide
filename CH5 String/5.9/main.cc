///在有序但含有空的数组中查找字符串
#include <iostream>
#include <vector>
#include <initializer_list>
#include <string>

using namespace std;

int getIndex(vector<string> &input, string s, int left, int right){
    if(s == "") return -1;
    int ret = -1;
    while(left < right){
        int middle = left + (right - left)/2;

        if(input[middle] == ""){
            int lret = getIndex(input, s, left, middle - 1);
            if(lret != -1) return lret;

            int rret = getIndex(input, s, middle + 1, right);
            return rret;
        }

        if(input[middle] == s){
            right = middle;
            continue;
        }
        else if(input[middle] > s){
            right = middle - 1;
            continue;
        }
        else{
            left = middle + 1;
            continue;
        }
    }

    if(input[left] == s) return left;
    else return -1;
}

int main(){
    vector<string> input({"", "a", "", "a", "", "b", "", "c"});
    int ret = getIndex(input, "d", 0, input.size() - 1);
    cout<<ret<<endl;
}
