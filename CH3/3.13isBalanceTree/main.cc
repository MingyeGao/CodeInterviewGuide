///判断二叉树是否为平衡二叉树
#include <assert.h>
#include <iostream>
using namespace std;

struct Node{
    int val;
    Node *lchild;
    Node *rchild;
    Node(int x = 0):val(x), lchild(nullptr), rchild(nullptr){}
};

int getHeight(Node *node){
    if(!node) return 0;

    int lh = getHeight(node->lchild);
    if(lh < 0) return -1;

    int rh = getHeight(node->rchild);
    if(rh < 0) return -1;

    int df = lh - rh;
    if(df < -1 || df > 1) return -1;
    else{
        return max(lh, rh) + 1;
    }
}

bool isBalanceTree(Node *node){
    if(getHeight(node) >= 0){
        return true;
    }
    else{
        return false;

    }
}

Node *testCase(){
    Node *node1 = new Node(1);
    Node *node2 = new Node(2);
    Node *node3 = new Node(3);
    Node *node4 = new Node(4);
    Node *node5 = new Node(5);
    Node *node6 = new Node(6);
    Node *node7 = new Node(7);
    node1->lchild = node2;
    node1->rchild = node3;
    node2->lchild = node4;
    node2->rchild = node5;
    node3->lchild = node6;
    node3->rchild = node7;
    return node1;
}

int main(){
    Node *t = testCase();
    int height = getHeight(t);
    cout<<height<<endl;
    bool ret = isBalanceTree(t);
    assert(ret);
}