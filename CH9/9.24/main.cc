//一种没有扩容负担的堆结构
#include <assert.h>
#include <iostream>
#include <vector>

using namespace std;

class Node{
public:
    Node(int x):val(x), lchild(nullptr), rchild(nullptr),parent(nullptr){}
    int val;
    Node *lchild;
    Node *rchild;
    Node *parent;
};

void nodeSwap(Node *node1, Node *node2){
    assert(node1 && node2);
    swap(node1->val, node2->val);
}

class Heap{
public:
    Heap():size(0), head(nullptr), lastParent(nullptr){};
    int size;
    Node *head;
    Node *lastParent;
    Node *getHead(){
        return head;
    };
    void maxHeapify(Node *node){
        if(!node) return;

        if(!node->lchild && !node->rchild) return;

        if(!node->rchild){
            if(node->val < node->lchild->val){
                nodeSwap(node, node->lchild);
            }
            return;
        }

        if(node->val < node->lchild->val || node->val < node->rchild->val){
            Node *larger = (node->lchild->val > node->rchild->val)?node->lchild:node->rchild;
            nodeSwap(node, larger);
            maxHeapify(larger);
            return;
        }
    }

    Node *getNextLast(Node *node){
        Node *current = node;
        while(current->parent && current == current->parent->rchild){
            current = current->parent;
        }
       
        if(current->parent){
            current = current->parent->rchild;
        }
        while(current->lchild){
            current = current->lchild;
        }

        return current;
    }

    void addFixup(Node *node){
        Node *current = node;
        while(current->parent){
            if(current->parent->val < current->val){
                nodeSwap(current->parent, current);
                current = current->parent;
            }
            else{
                break;
            }
        }
        maxHeapify(current);
    }

    void add(int x){
        Node *newNode = new Node(x);
        if(head == nullptr){
            head = newNode;
            lastParent = newNode;
        }
        else if(!lastParent->lchild){
            lastParent->lchild = newNode;
        }
        else if(!lastParent->rchild){
            lastParent->rchild = newNode;
        }
        else if(lastParent->lchild && lastParent->rchild){
            lastParent = getNextLast(lastParent);
            lastParent->lchild = newNode;
        }

        ++size;
    }

    Node* popHead(){
        if(head == nullptr) return nullptr;
        Node *ret = head;
        Node *toSwap;
        if(lastParent->rchild){
            toSwap = lastParent->rchild;
        }
        else if(lastParent->lchild){
            toSwap = lastParent->lchild;
        }

        nodeSwap(head, toSwap);
        delete toSwap;
        maxHeapify(head);
        --size;
        return ret;
    }

    int getSize(){
        return size;
    }
};

int main(){
    Heap heap;
    Node *ret = heap.getHead();
    assert(!ret);
    for(int i = 9; i >= 0; --i){
        heap.add(i);
    }
    ret = heap.getHead();
    cout<<ret->val<<endl;
    ret = heap.popHead();
    cout<<ret->val<<endl;
    ret = heap.getHead();
    cout<<ret->val<<endl;
}