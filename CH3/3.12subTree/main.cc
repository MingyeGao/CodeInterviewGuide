///判断t1树中是否有与t2树拓扑完全相同的子树
#include <assert.h>
#include <iostream>
#include <vector>
#include <queue>
#include <sstream>
#include "kmp.h"

using namespace std;

struct Node{
    int val;
    Node *lchild;
    Node *rchild;
    Node(int x = 0):val(x), lchild(nullptr), rchild(nullptr){}
};

bool isSubTree1(Node *t1, Node *t2){
    if(!t1 && !t2) return true;
    if(!t1 || !t2) return false;

    if(t1->val == t2->val){
        bool ret1 = isSubTree1(t1->lchild, t2->lchild);
        bool ret2 = isSubTree1(t1->rchild, t2->rchild);
        return ret1&&ret2;
    }
    else{
        return false;
    }
}

bool func(Node *t1, Node *t2){
    bool ret = isSubTree1(t1, t2);
    if(ret) return true;

    if(t1->lchild){
        bool lret = isSubTree1(t1->lchild, t2);
        if(lret) return true;
    }

    if(t1->rchild){
        bool rret = isSubTree1(t1->rchild, t2);
        if(rret) return true;
    }
    return false;
}

void testCase1(Node *&t1, Node *&t2){
    Node *node1 = new Node(1);
    Node *node2 = new Node(2);
    Node *node3 = new Node(3);
    Node *node4 = new Node(4);
    Node *node5 = new Node(5);
    Node *node6 = new Node(6);
    Node *node7 = new Node(7);
    Node *node8 = new Node(8);
    Node *node9 = new Node(9);
    node1->lchild = node2;
    node1->rchild = node3;
    node2->lchild = node4;
    node2->rchild = node5;
    node4->rchild = node8;
    node5->lchild = node9;
    node3->lchild = node6;
    node3->rchild = node7;
    t1 = node1;
    t2 = node2;
}

void preOrder(Node *t, ostringstream &s){
    if(!t) {
        s<<"#!";
        return;
    }

    s<<t->val<<"!";
    preOrder(t->lchild, s);
    preOrder(t->rchild, s);

}

string serialize(Node *t){
    ostringstream s;
    preOrder(t, s);
    return s.str();
}

bool func2(Node *t1, Node *t2){
    string s1 = serialize(t1);
    string s2 = serialize(t2);
    // cout<<s1<<endl;
    // cout<<s2<<endl;
    int ret = kmp(s1, s2);
    if(ret > 0) return true;
    else return false;
}

int main(){
    Node *t1, *t2;
    testCase1(t1, t2);
    bool ret = func(t1, t2);
    assert(ret);
    ret = func2(t1, t2);
    assert(ret);
}