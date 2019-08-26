#include <iostream>
#include <vector>

using namespace std;

int select(vector<int> &input, int begin, int end, int k);

void insertSort(vector<int> &input, int begin, int end){
    if(begin >= end) return;
    for(int i = begin + 1; i <= end; ++i){
        for(int j = i; j >= begin + 1; ++j){
            if(input[j] < input[j - 1]){
                swap(input[j], input[j - 1]);
            }
            else{
                break;
            }
        }
    }
}

int getMedian(vector<int> &input, int begin, int end){
    int size = end - begin + 1;
    insertSort(input, begin, end);
    return input[begin + size/2];
}

int medianOfMedians(vector<int> &input, int begin, int end){
    int medianNum = (end - begin)/5 + 1;
    vector<int> medians(medianNum);
    
    for(int i = 0; i < medianNum; ++i){
        medians[i] = getMedian(input, begin + i * 5, (begin + i * 5 + 4) > end ? end : begin + i * 5 + 4);
    }

    return select(medians, 0, medianNum - 1, medianNum/2);
}

int partition(vector<int> &input, int begin, int end, int i){
    int left = begin;
    int right = end;
    while(left < right){
        while(left < right && input[left] <= i){
            ++left;
        }
        if(left < right){
            swap(input[left], input[right]);
            right--;
        }
    }
    return left;
}

///从input数组中的begin到end这一范围内，找到第k小的数
///返回第k小的数的值
int select(vector<int> &input, int begin, int end, int k){
    if(begin == end) return input[begin];

    int median = medianOfMedians(input, begin, end);

    int index = partition(input, begin, end, k);
    if(index == k){
        return median;
    }

    if(index > k){
        return select(input, begin, index - 1, k);
    }
    else{
        return select(input, index + 1, end, k);
    }
}

vector<int> minK(vector<int> &input, int k){
    int mink = select(input, 0, input.size() - 1, k);
    vector<int> ret;
    for(int i = 0; i < input.size(); ++i){
        if(input[i] < mink && ret.size() < k){
            ret.push_back(input[i]);
        }
    }

    if(ret.size() < k){
        for(int i = ret.size(); i <=k; ++i){
            ret.push_back(mink);
        }
    }

    return ret;
}

int main(){
    vector<int> input({1, 2, 3, 4, 5, 6, 7, 8});
    vector<int> ret = minK(input, 2);
    for(int i = 0; i < ret.size(); ++i){
        cout<<ret[i]<<", ";
    }
}