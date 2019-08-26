///随时找到数据流的中位数
#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>

using namespace std;

class MedianStruct{
public:
    priority_queue<int, vector<int>, less<int> > maxHeap;
    priority_queue<int, vector<int>, greater<int> > minHeap;
    void add(int x){
        
        if(minHeap.size() == 0 || x > minHeap.top()){
            minHeap.push(x);
        }
        else{
            maxHeap.push(x);
        }

        if(minHeap.size() == (maxHeap.size() + 2)){
            int tmp = minHeap.top();
            maxHeap.push(tmp);
            minHeap.pop();
        }
        else if(maxHeap.size() == (minHeap.size() + 2)){
            int tmp = maxHeap.top();
            maxHeap.pop();
            minHeap.push(tmp);
        }
    }

    double getMedian(){
        if(maxHeap.size() == minHeap.size()){
            return ((double)maxHeap.top() + minHeap.top())/2;
        }
        else if(maxHeap.size() > minHeap.size()){
            return maxHeap.top();
        }
        else if(maxHeap.size() < minHeap.size()){
            return minHeap.top();
        }
    }
};

int main(){
    MedianStruct m;
    for(int i = 0; i < 10; ++i){
        m.add(i);
        cout<<m.getMedian()<<", ";
    }
}