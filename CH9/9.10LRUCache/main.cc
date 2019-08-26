///设计可以变更的缓存结构

#include <iostream>
#include <vector>
#include <map>
#include <string>

using namespace std;

class Node{
public:
    Node(int x = 0):val(x), prev(nullptr), next(nullptr){}
    int val;
    Node *prev;
    Node *next;
};

class LRUcache{
public:
    LRUcache(int c):size(0), capacity(c){
        dummyHead = new Node;
        dummyTail = new Node;
        dummyHead->next = dummyTail;
        dummyTail->prev = dummyHead;
    }
    map<string, Node*> kvMap;
    int size;
    int capacity;
    Node *dummyHead;
    Node *dummyTail;
    ~LRUcache(){
        Node *current = dummyHead;
        while(current){
            Node *next = current->next;
            delete current;
            current = next;
        }
        cout<<"LRUcache deleted"<<endl;
    }

    void moveToHead(Node *node){
        if(node->prev == dummyHead) return;

        node->prev->next = node->next;
        node->next->prev = node->prev;
            
        node->next = dummyHead->next;
        dummyHead->next->prev = node;
        dummyHead->next = node;
        node->prev = dummyHead;
    }

    void set(string key, int val){
        if(kvMap.find(key) != kvMap.end()){
            Node *node = kvMap[key];
            moveToHead(node);
        }
        else{
            Node *newNode = new Node(val);
            newNode->prev = dummyTail->prev;
            dummyTail->prev->next = newNode;
            newNode->next = dummyTail;
            dummyTail->prev = newNode;
            if(size < capacity){
                ++size;
            }
            else{
                Node *head = dummyHead->next;
                head->next->prev = dummyHead;
                dummyHead->next = head->next;
                delete head;
            }
        }
    }

    int get(string key){
        if(kvMap.find(key) == kvMap.end()){
            cout<<"no such key"<<endl;
            return -1;
        }
        Node *node = kvMap[key];
        moveToHead(node);
        return node->val;
    }

};

int main(){
    LRUcache r(3);
    r.set("A", 1);
    r.set("B", 2);
    r.set("C", 3);
    r.get("A");
}