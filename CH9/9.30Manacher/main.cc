#include <iostream>
#include <vector>
#include <string>

using namespace std;

int Manacher(string s){
    string helperString("#");
    for(int i = 0; i < s.size(); ++i){
        helperString += s[i];
        helperString += "#";
    }

    int ret = -1;

    vector<int> radius(helperString.size(), 1);
    int rightMost = -1;
    int maxRadiusIndex = -1;
    for(int i = 0; i < helperString.size(); ++i){
        if(rightMost > i){
            radius[i] = min(radius[2 * maxRadiusIndex - i], rightMost - i);
        }
        while(i + radius[i] < helperString.size() && i - radius[i] > -1){
            if(helperString[i + radius[i]] == helperString[i - radius[i]]){
                ++radius[i];
            }
            else{
                break;
            }
        }

        if(i + radius[i] > rightMost){
            rightMost = i + radius[i];
            maxRadiusIndex = i;
        }
        ret = max(radius[i], ret);
    }
    return ret - 1;
}

string shortestEnd(string s){
    string helperString("#");
    for(int i = 0; i < s.size(); ++i){
        helperString += s[i];
        helperString += "#";
    }

    vector<int> radius(helperString.size(), 1);
    int rightMost = -1;
    int rightMostIndex = -1;
    for(int i = 0; i < helperString.size(); ++i){
        if(rightMostIndex > i){
            radius[i] = min(rightMost - i, radius[2*rightMost - 1]);
        }
        while(i + radius[i] < helperString.size() && i - radius[i] > -1){
            if(helperString[i + radius[i]] == helperString[i - radius[i]]){
                ++radius[i];
            }
            else{
                break;
            }
        }
        if(i + radius[i] > rightMost){
            rightMost = i + radius[i];
            rightMostIndex = i;
        }

        if(rightMost == helperString.size()){
            break;
        }
    }

    int start = 2 * rightMostIndex - (helperString.size() - 1);
    int addSize = start/2;
    string ret;
    for(int i = 0; i < addSize; ++i){
        ret = s[i] + ret;
    }
    return ret;
}

int main(){
    string input("abc1234321ab");
    int ret = Manacher(input);
    cout<<ret<<endl;

    string s("abc1234321ab");
    string ret2 = shortestEnd(s);
    cout<<ret2<<endl;
}