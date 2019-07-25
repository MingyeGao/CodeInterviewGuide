///在二叉树中找到一个节点的后继节点

#include <iostream>
#include <vector>

using namespace std;

struct Node{
    int val;
    Node *lchild;
    Node *rchild;
    Node *p;
    Node(int x = 0):val(x), lchild(nullptr), rchild(nullptr), p(nullptr){}
};

Node *getSuccessor(Node *node){
    if(!node) return nullptr;

    Node *p = nullptr;
    if(node->rchild){
        p = node->rchild;
        while(p->lchild){
            p = p->lchild;
        }
    }
    else{
        Node *current = node;
        
        while(current->p && current == current->p->rchild){
            current = current->p;
        }

        if(current->p){
            p = current->p;
        }
    }

    return p;
}

Node *testCase(){
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
    node6->lchild = node3;
    node3->p = node6;
    node6->rchild = node9;
    node9->p = node6;
    node3->lchild = node1;
    node1->p = node3;
    node3->rchild = node4;
    node4->p = node3;
    node1->rchild = node2;
    node2->p = node1;
    node4->rchild = node5;
    node5->p = node4;
    node9->lchild = node8;
    node8->p = node9;
    node9->rchild = node10;
    node10->p = node9;
    node8->lchild = node7;
    node7->p = node8;
    return node9;
}

int main(){
    Node *node = testCase();
    Node *ret = getSuccessor(node);
    cout<<ret->val<<endl;
}