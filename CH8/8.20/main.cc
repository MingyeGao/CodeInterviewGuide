///打印N个数组整体最大的topK
#include <iostream>
#include <vector>

using namespace std;

class HeapNode{
public:
    int val;
    int arr;
    int index;
    HeapNode(){};
    HeapNode(int v, int a, int i):val(v), arr(a), index(i){};
};

void maxHeapify(vector<HeapNode> &heap, int index, int endIndex){
    if(2 * index + 1 >= endIndex){
        return;
    }
    if(2 * index + 1 == endIndex){
        if(heap[index].val < heap[2 * index + 1].val){
            swap(heap[index], heap[2 * index + 1]);
        }
        return;
    }

    int l = 2 * index + 1, r = 2 * index + 2;
    if(heap[index].val < heap[l].val || heap[index].val < heap[r].val){
        int largerIndex = heap[l].val > heap[r].val?l:r;
        swap(heap[index], heap[largerIndex]);
        maxHeapify(heap, largerIndex, endIndex);
    }
}

void makeMaxHeap(vector<HeapNode> &input){
    int num = input.size();
    int start = num/2 - 1;
    for(; start >= 0; --start){
        maxHeapify(input, start, num - 1);
    }
}

void printTopK(vector<vector<int> > &input, int k){
    int N = input.size();
    vector<HeapNode> heap(N);
    for(int i = 0; i < input.size(); ++i){
        heap[i] = HeapNode(input[i][input[i].size() - 1], i, input[i].size() - 1);
    }
    makeMaxHeap(heap);

    for(int i = 0; i < k; ++i){
        cout<<heap[0].val<<", ";
        if(heap[0].index == 0){
            swap(heap[0], heap[N - 1]);
            N--;
            maxHeapify(heap, 0, N - 1);
        }
        else{
            int arr = heap[0].arr;
            int idx = heap[0].index;
            heap[0] = HeapNode(input[arr][idx - 1], arr, idx - 1);
            maxHeapify(heap, 0, N - 1);
        }
    }

}

int main(){
    vector<vector<int>> input({
        {219, 405, 538, 845, 971},
        {148, 558},
        {52, 99, 348, 691}
    });
    printTopK(input, 5);
}
