///判断字符数组中是否所有的字符都只出现过一次
#include <iostream>
#include <vector>
#include <initializer_list>

using namespace std;



///构建大顶堆
void maxHeapify(vector<char> &input, int index, int size){
    if(2*index + 1 >= size){
        return;
    }
    else if((2*index + 1) == (size - 1)){
        if(input[index] < input[2*index + 1]){
            swap(input[index], input[2*index + 1]);
        }
    }
    else{
        int left = 2*index + 1;
        int right = 2*index + 2;
        if(input[index] < input[left] || input[index] < input[right]){
            if(input[left] > input[right]){
                swap(input[index], input[left]);
                maxHeapify(input, left, size);
            }
            else{
                swap(input[index], input[right]);
                maxHeapify(input, right, size);
            }
        }
    }
}

void makeHeap(vector<char> &input){
    if(input.size() == 0) return ;

    int i = input.size()/2 - 1;
    for(; i >= 0; --i){
        maxHeapify(input, i, input.size());
    }
}

void heapSort(vector<char> &input){
    makeHeap(input);
    for(int i = input.size() - 1; i > 0; --i){
        swap(input[0], input[i]);
        maxHeapify(input, 0, i);
    }
}

bool isUnique(vector<char> &input){
    heapSort(input);
    for(int i = 0; i < input.size() - 1; ++i){
        if(input[i] == input[i + 1]){
            return false;
        }
    }
    return true;
}

int main(){
    vector<char> input({'a', 'b', 'a'});
    heapSort(input);
    for(int i = 0; i < input.size(); ++i){
        cout<<input[i]<<", ";
    }
    cout<<endl;
    bool ret = isUnique(input);
    if(ret){
        cout<<"true"<<endl;
    }
    else{
        cout<<"false"<<endl;
    }
}