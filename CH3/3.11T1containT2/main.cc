///判断t1树是否包含t2树全部的拓扑结构
#include <assert.h>
#include <iostream>

using namespace std;

struct Node{
    int val;
    Node *lchild;
    Node *rchild;
    Node(int x = 0):val(x), lchild(nullptr), rchild(nullptr){};
};

bool contain(Node *t1, Node *t2){
    if(t1 == nullptr && t2 == nullptr) return true;

    //if(!t1 || !t2) return false;
    if(!t1 && t2) return false;

    if(t1 && !t2) return true;

    if(t1->val == t2->val){
        bool ret1 = contain(t1->lchild, t2->lchild);
        bool ret2 = contain(t1->rchild, t2->rchild);
        if(ret1 && ret2){
            return true;
        }
        else{
            return false;
        }
    }
    else{
        return false;
    }
}

bool func(Node *t1, Node *t2){
    bool ret = contain(t1, t2);
    if(ret) return true;

    if(t1->lchild){
        bool lret = func(t1->lchild, t2);
        if(lret) return true;
    }
    
    if(t1->lchild){
        bool rret = func(t1->rchild, t2);
        if(rret) return true;
    }

    return false;
    
}

void testCase(Node *&t1, Node *&t2){
    Node *node1 = new Node(1);
    Node *node2 = new Node(2);
    Node *node3 = new Node(3);
    Node *node4 = new Node(4);
    Node *node5 = new Node(5);
    Node *node6 = new Node(6);
    Node *node7 = new Node(7);
    Node *node8 = new Node(8);
    Node *node9 = new Node(9);
    Node *node10 = new Node(10);
    node1->lchild = node2;
    node1->rchild = node3;
    node2->lchild = node4;
    node2->rchild = node5;
    node4->lchild = node8;
    node4->rchild = node9;
    node5->lchild = node10;
    node3->lchild = node6;
    node3->rchild = node7;
    t1 = node1;
    t2 = node2;
}

int main(){
    Node *t1, *t2;
    testCase(t1, t2);
    bool ret = func(t1, t2);
    assert(ret);
}