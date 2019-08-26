///两个有序数组相加和的TopK问题
#include <iostream>
#include <vector>
#include <set>

using namespace std;

void maxHeapify(vector<pair<int, int>> &heap, int index, int &size, vector<int> &vec1, vector<int> &vec2){
    if(index >= size - 1) return;

    int lchildIndex = 2*index + 1, rchildIndex = 2*index + 2;
    if(lchildIndex > size - 1){
        return;
    }

    if(lchildIndex == size - 1){
        int psum = vec1[heap[index].first] + vec2[heap[index].second];
        int lchildSum = vec1[heap[lchildIndex].first] + vec2[heap[lchildIndex].second];
        if(psum < lchildSum){
            swap(heap[index], heap[lchildIndex]);
        }
        return;
    }

    int psum = vec1[heap[index].first] + vec2[heap[index].second];
    int lchildSum = vec1[heap[lchildIndex].first] + vec2[heap[lchildIndex].second];
    int rchildSum = vec1[heap[rchildIndex].first] + vec2[heap[rchildIndex].second];
    if(psum < lchildSum || psum < rchildSum){
        int largerIndex = lchildSum > rchildSum? lchildIndex: rchildIndex;
        swap(heap[index], heap[largerIndex]);
        maxHeapify(heap, largerIndex, size, vec1, vec2);
    }
}

void addFixup(vector<pair<int, int>> &heap, int &size, vector<int> &vec1, vector<int> &vec2){
    int pIndex, pSum;
    int currentIndex = size - 1;
    while(currentIndex > 0){
        pIndex = (currentIndex - 1)/2;
        int currentSum = vec1[heap[currentIndex].first] + vec2[heap[currentIndex].second];
        int pSum = vec1[heap[pIndex].first] + vec2[heap[pIndex].second];
        if(pSum < currentSum){
            swap(heap[currentIndex], heap[pIndex]);
            currentIndex = pIndex;
        }
        else{
            break;
        }
    }
    maxHeapify(heap, currentIndex, size, vec1, vec2);
}

pair<int, int> pop(vector<pair<int, int>> &heap, int &size, vector<int> &vec1, vector<int> &vec2){
    auto ret = heap[0];
    swap(heap[0], heap[size - 1]);
    --size;
    maxHeapify(heap, 0, size, vec1, vec2);
    return ret;
}

void heapAdd(vector<pair<int, int>> &heap, pair<int, int> indexPair, int &size, vector<int> &vec1, vector<int> &vec2){
    if(heap.size() > size){
        heap[size] = indexPair;
    }
    else{
        heap.push_back(indexPair);
    }
    ++size;
    addFixup(heap, size, vec1, vec2);
}


vector<int> sumTopK(vector<int> &vec1, vector<int> &vec2, int k){
    vector<pair<int, int>> indexHeap;
    set<pair<int, int> > indexPairSet;
    int heapSize = 0;
    vector<int> ret;
    if(k == 0) return ret;
    indexHeap.push_back(make_pair(vec1.size() - 1, vec2.size() - 1));
    ++heapSize;
    indexPairSet.insert({vec1.size() - 1, vec2.size() - 1});
    for(int i = 0; i < k; ++i){
        auto topPair = pop(indexHeap, heapSize, vec1, vec2);
        int sum = vec1[topPair.first] + vec2[topPair.second];
        ret.push_back(sum);
        if(topPair.first > 0){
            pair<int, int> subPair1({topPair.first - 1, topPair.second});
            if(indexPairSet.find(subPair1) == indexPairSet.end()){
                indexPairSet.insert(subPair1);
                heapAdd(indexHeap, subPair1, heapSize, vec1, vec2);
            }
        }

        if(topPair.second > 0){
            pair<int, int> subPair1({topPair.first, topPair.second - 1});
            if(indexPairSet.find(subPair1) == indexPairSet.end()){
                indexPairSet.insert(subPair1);
                heapAdd(indexHeap, subPair1, heapSize, vec1, vec2);
            }
        }
    }

    return ret;
}

int main(){
    vector<int> input1({1, 2, 3, 4, 5}), input2({3, 5, 7, 9, 11});
    vector<int> ret = sumTopK(input1, input2, 4);
    for(auto i : ret){
        cout<<i<<", ";
    }
}