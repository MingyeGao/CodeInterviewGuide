///出现次数topK
#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <map>
#include <queue>

using namespace std;

class Node{
public:
    Node(){};
    Node(string s, int t):val(s), times(t){};
    string val;
    int times;
};

struct NodeGreater{
    NodeGreater(){};
    bool operator()(Node &node1, Node &node2){
        return node1.times > node2.times;
    }
};

void prinkTopK(vector<string> &input, int k){
    map<string, int> timeMap;
    for(string s: input){
        if(timeMap.find(s) == timeMap.end()){
            timeMap[s] = 1;
        }
        else{
            timeMap[s]++;
        }
    }
    priority_queue<Node, vector<Node>, NodeGreater> pq;
    for(auto it = timeMap.begin(); it != timeMap.end(); it++){
        if(pq.size() < k){
            pq.push(Node(it->first, it->second));
        }
        else{
            if(it->second > pq.top().times){
                pq.pop();
                pq.push(Node(it->first, it->second));
            }
        }
    }

    vector<Node> ret;
    int size = pq.size();
    for(int i = 0; i < min(k, size); ++i){
        ret.push_back(pq.top());
        pq.pop();
    }


    for(int i = 0; i < ret.size(); ++i){
        cout<<"No."<<i + 1<<":";
        cout<<ret[i].val;
        cout<<", times: ";
        cout<<ret[i].times<<endl;
    }
    
}


class TopRecords{
public:
    TopRecords(int x):size(0), capacity(x){};
    int size;
    int capacity;
    map<string, Node*> stringNodeMap;
    map<Node*, int> nodeIndexMap;
    vector<Node*> heap;

    void maxHeapify(vector<Node*> &heap, int &heapSize, int index){
        if(index >= heapSize) return;

        int lchildIndex = 2 * index + 1, rchildIndex = 2 * index + 2;
        if(lchildIndex < heapSize - 1){
            return;
        }
        else if(lchildIndex == heapSize - 1){
            if(heap[index]->times > heap[lchildIndex]->times){
                nodeIndexMap[heap[index]] = lchildIndex;
                nodeIndexMap[heap[lchildIndex]] = index;
                swap(heap[index], heap[lchildIndex]);
            }
        }
        else if(lchildIndex < heapSize - 1){
            int largerIndex = heap[lchildIndex]->times>heap[rchildIndex]->times? lchildIndex: rchildIndex;
            if(heap[index]->times > heap[largerIndex]->times){
                nodeIndexMap[heap[index]] = largerIndex;
                nodeIndexMap[heap[largerIndex]] = index;
                swap(heap[index], heap[largerIndex]);
                maxHeapify(heap, heapSize, largerIndex);
            }
        }
    }

    void addFixup(vector<Node*> &heap, int heapSize, int index){
        int current = index;
        while(current > 0){
            int pIndex = (index - 1)/2;
            if(heap[current]->times < heap[pIndex]->times){
                nodeIndexMap[heap[current]] = pIndex;
                nodeIndexMap[heap[pIndex]] = current;
                swap(heap[current], heap[pIndex]);
                current = pIndex;
            }
            else{
                break;
            }
        }
        maxHeapify(heap, heapSize, current);
    }


    void add(string s){
        if(stringNodeMap.find(s) == stringNodeMap.end()){
            Node *newNode = new Node(s, 1);
            stringNodeMap.insert({s, newNode});
            nodeIndexMap.insert({newNode, -1});
        }
        else{
            stringNodeMap[s]->times++;
        }

        Node *node = stringNodeMap[s];
        if(nodeIndexMap[node] == -1){
            if(size < capacity){
                heap.push_back(node);
                ++size;
                nodeIndexMap[node] = size - 1;
                maxHeapify(heap, size, size - 1);
            }
            else{
                if(node->times > heap[0]->times){
                    nodeIndexMap[heap[0]] = -1;
                    nodeIndexMap[node] = 0;
                    heap[0] = node;
                    maxHeapify(heap, size, 0);
                }
            }
        }
        else{
            maxHeapify(heap, size, nodeIndexMap[node]);
        }
    }

    void printTopK(){
        for(int i = 0; i < size; ++i){
            cout<<"No."<<i + 1<<": "<<heap[i]->val<<", "<<"times: ";
            cout<<heap[i]->times<<endl;
        }
    }
};

int main(){
    // vector<string> input({"1", "2", "3", "4"});
    // prinkTopK(input, 2);
    TopRecords record(2);
    record.add("A");
    record.printTopK();
    record.add("B");
    record.add("B");
    record.printTopK();
    record.add("C");
    record.add("C");
    record.printTopK();
}