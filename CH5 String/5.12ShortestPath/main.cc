///数组中两个字符串的最小距离
#include <iostream>
#include <vector>
#include <string>
#include <climits>
#include <initializer_list>

using namespace std;

int shortest(vector<string> &input, string s1, string s2){
    if(s1 == "" || s2 == "") return -1;
    if(s1 == s2) return 0;

    int last1 = -1, last2 = -1;
    int minDistance = INT_MAX;
    for(int i = 0; i < input.size(); ++i){
        if(input[i] == s1){
            last1 = i;
            if(last2 != -1 && last1 - last2 < minDistance){
                minDistance = last1 - last2;
            }
            continue;
        }
        
        if(input[i] == s2){
            if(input[i] == s2){
                last2 = i;
                if(last1 != -1 && last2 - last1 < minDistance){
                    minDistance = last2 - last1;
                }
            }
        }
    }

    if(last1 == -1 || last2 == -1){
        return -1;
    }
    else{
        return minDistance;
    }
}

int main(){
    vector<string> input({"1", "3", "3", "3", "2", "3", "1"});
    int ret = shortest(input, "1", "2");
    cout<<ret<<endl;
}