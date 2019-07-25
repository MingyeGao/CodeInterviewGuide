///打印二叉树的边界节点

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Node{
    int val;
    Node *lchild;
    Node *rchild;
    Node(int x = 0):val(x), lchild(nullptr), rchild(nullptr){}
};

Node *testCase1(){
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
    Node *node11 = new Node(11);
    Node *node12 = new Node(12);
    Node *node13 = new Node(13);
    Node *node14 = new Node(14);
    Node *node15 = new Node(15);
    Node *node16 = new Node(16);
    node1->lchild = node2;
    node1->rchild = node3;
    node2->rchild = node4;
    node4->lchild = node7;
    node4->rchild = node8;
    node8->rchild = node11;
    node11->lchild = node13;
    node11->rchild = node14;
    node3->lchild = node5;
    node3->rchild = node6;
    node5->lchild = node9;
    node5->rchild = node10;
    node9->lchild = node12;
    node12->lchild = node15;
    node12->rchild = node16;
    return node1;
}


void getEdgeNodes(Node *node, int height, vector<Node*> &leftmost, vector<Node*> &rightmost){
    if(node == nullptr) return;

    if(leftmost[height-1] == nullptr){
        leftmost[height - 1] = node;
    }

    rightmost[height - 1] = node;
    getEdgeNodes(node->lchild, height + 1, leftmost, rightmost);
    getEdgeNodes(node->rchild, height + 1, leftmost, rightmost);

}

int getHeight(Node *node){
    if(node == nullptr){
        return 0;
    }

    return max(getHeight(node->lchild), getHeight(node->rchild)) + 1;
}

void printLeefNotEdgeNodes(Node *node, int height, vector<Node*> &leftmost, vector<Node*> &rightmost){
    if(node == nullptr) return;
    if(!node->lchild && 
       !node->rchild && 
       node != leftmost[height - 1] &&
       node != rightmost[height - 1]){
        cout<<node->val<<", ";
        return;
    }
    else{
        printLeefNotEdgeNodes(node->lchild, height+1, leftmost, rightmost);
        printLeefNotEdgeNodes(node->rchild, height+1, leftmost, rightmost);
    }
}

void printEdge1(Node *node){
    int treeHeight = getHeight(node);
    vector<Node*> leftmost(treeHeight, nullptr), rightmost(treeHeight, nullptr);
    getEdgeNodes(node, 1, leftmost, rightmost);
    
    for(int i = 0; i < treeHeight; ++i){
        if(leftmost[i] == nullptr) break;
        cout<<leftmost[i]->val<<", ";
    }
    printLeefNotEdgeNodes(node, 1, leftmost, rightmost);
    for(int i = treeHeight - 1; i >=0; --i){
        if(rightmost[i] == nullptr) continue;
        if(rightmost[i] == leftmost[i]) break;
        cout<<rightmost[i]->val<<", ";
    }
    cout<<endl;

}

void printLeftEdge(Node *node, bool flag){
    if(node == nullptr) return;
    
    if(flag || (!node->lchild && !node->rchild)){
        cout<<node->val<<", ";
    }

    printLeftEdge(node->lchild, flag);
    printLeftEdge(node->rchild, flag && (node->lchild?false:true));
}

void printRightEdge(Node *node, bool flag){
    if(node == nullptr) return;

    printRightEdge(node->lchild, flag && (node->rchild?false:true));
    printRightEdge(node->rchild, flag);

    if(flag || (!node->lchild && !node->rchild)){
        cout<<node->val<<", ";
    }
}

void printEdge2(Node *node){
    if(!node) return;
    if(node->lchild && node->rchild){
        cout<<node->val<<", ";
        printLeftEdge(node->lchild, true);
        printRightEdge(node->rchild, true);
    }
    else{
        cout<<node->val<<", ";
        printEdge2(node->lchild?node->lchild:node->rchild);
    }
}

int main(){
    Node *tree = testCase1();
    printEdge1(tree);
    cout<<endl;
    printEdge2(tree);
    cout<<endl;
}