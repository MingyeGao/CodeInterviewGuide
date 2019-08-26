///分糖果问题
#include <iostream>
#include <vector>

using namespace std;

int getNextValley(vector<int> &input, int start){
    for(int i = start; i < input.size() - 1; ++i){
        if(input[i] <= input[i + 1]){
            return i;
        }
    }
    return input.size() - 1;
}

int getDownwaySize(int start, int end){
    int len = end - start + 1;
    return (1 + len)*len/2;
}

///分糖果策略
///任意两个相邻的孩子之间，得分较多的必须多拿一些
int candy1(vector<int> &input){
    int index = getNextValley(input, 0);
    int ret = getDownwaySize(0, index++);
    int lbase = 1;
    int rbase = 0;
    int next;
    while(index < input.size()){
        if(input[index] > input[index - 1]){
            ret += ++lbase;
            ++index;
        }
        else if(input[index] < input[index - 1]){
            next = getNextValley(input, index - 1);
            rbase = next - index + 1;
            int downSize = getDownwaySize(index - 1, next++);
            ret += downSize + (rbase > lbase)? (-lbase): (-rbase);
            lbase = 1;
            index = next;
        }
        else{
            ret += 1;
            lbase = 1;
            ++index;
        }
    }
    return ret;
}

int getNextValley2(vector<int> &input, int start, int &rbase){
    rbase = 0;
    for(int i = start; i < input.size() - 1; ++i){
        if(input[i] < input[i + 1]){
            rbase + 1;
            return i;
        }
        else if(input[i] > input[i + 1]){
            ++rbase;
        }
    }
    ++rbase;
    return input.size() - 1;
}

int getDownwaySize2(vector<int> &input, int start, int end){
    int base = 1;
    int ret = 1;
    for(int i = end - 1; i >= start; --i){
        if(input[i] == input[i + 1]){
            ret += base;
        }
        else{
            ret += ++base;
        }
    }

    return ret;
}

int candy2(vector<int> &input){
    
    int same = 0;
    int lbase = 1, rbase = 0;
    int index = getNextValley2(input, 0, rbase);
    int ret = getDownwaySize2(input, 0, index++);
    while(index < input.size()){
        if(input[index] > input[index - 1]){
            ret += ++lbase;
            ++index;
            same = 0;
        }
        else if(input[index] < input[index - 1]){
            int nextValley = getNextValley2(input, index - 1, rbase);
            ret += getDownwaySize2(input, index - 1, nextValley);
            if(rbase > lbase){
                ret += same * (rbase - lbase);
            }
            else{
                ret += (lbase - rbase);
            }
            index = nextValley + 1;
            same = 0;
        }
        else{
            ret += lbase;
            ++same;
            ++index;
        }
    }

    return ret;
}

int main(){
    vector<int> input({0, 1, 2, 3, 3, 3, 2, 2, 2, 2, 2, 1, 1});
    int ret = candy1(input);
    cout<<ret<<endl;
    ret = candy2(input);
    cout<<ret<<endl;
}