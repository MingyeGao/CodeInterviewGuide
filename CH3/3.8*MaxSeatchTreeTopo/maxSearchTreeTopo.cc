///找到二叉树中符合搜索二叉树条件的最大拓扑结构
#include <assert.h>
#include <iostream>
#include <map>
#include <algorithm>
using namespace std;

struct Node{
    int val;
    Node *lchild;
    Node *rchild;
    Node(int x = 0):val(x), lchild(nullptr), rchild(nullptr){}
};

Node *testCase(){
    Node *node1 = new Node(6);
    Node *node2 = new Node(1);
    Node *node3 = new Node(12);
    Node *node4 = new Node(0);
    Node *node5 = new Node(3);
    Node *node6 = new Node(10);
    Node *node7 = new Node(13);
    Node *node8 = new Node(4);
    Node *node9 = new Node(14);
    Node *node10 = new Node(20);
    Node *node11 = new Node(16);
    Node *node12 = new Node(2);
    Node *node13 = new Node(5);
    Node *node14 = new Node(11);
    Node *node15 = new Node(15);
    node1->lchild = node2;
    node1->rchild = node3;
    node2->lchild = node4;
    node2->rchild = node5;
    node3->lchild = node6;
    node3->rchild = node7;
    node7->lchild = node10;
    node7->rchild = node11;
    node6->lchild = node8;
    node6->rchild = node9;
    node8->lchild = node12;
    node8->rchild = node13;
    node9->lchild = node14;
    node9->rchild = node15;
    return node1;
}

int modifyMap(Node* node, int val, map<Node*, pair<int, int>> &mapNodePair, bool inLeftTree){
    if(!node || mapNodePair.find(node) == mapNodePair.end()) 
        return 0;
    
    pair<int, int> contribute = mapNodePair[node];
    if((inLeftTree && (node->val > val)) || ((!inLeftTree) && node->val < val)){
        
        mapNodePair.erase(node);
        return contribute.first + contribute.second + 1;
    }
    else{
        int removeNodeCount = modifyMap(inLeftTree?node->rchild:node->lchild,
                                        val, mapNodePair, inLeftTree);
        if(inLeftTree){
            contribute.second -= removeNodeCount;
        }
        else{
            contribute.first -= removeNodeCount;
        }
        mapNodePair[node] = contribute;
        return removeNodeCount;
    }

}

int postOrder(Node *node, map<Node*, pair<int, int>> &mapNodePair){
    if(!node) return 0;

    int lmax = postOrder(node->lchild, mapNodePair);
    int rmax = postOrder(node->rchild, mapNodePair);

    pair<int, int> contribute;
    modifyMap(node->lchild, node->val, mapNodePair, true);
    modifyMap(node->rchild, node->val, mapNodePair, false);

    if(mapNodePair.find(node->lchild) == mapNodePair.end()){
        contribute.first = 0;
    }
    else{
        pair<int, int> lchildContribute = mapNodePair[node->lchild];
        contribute.first = lchildContribute.first + lchildContribute.second + 1;
    }

    if(mapNodePair.find(node->rchild) == mapNodePair.end()){
        contribute.second = 0;
    }
    else{
        pair<int, int> rchildContribute = mapNodePair[node->rchild];
        contribute.second = rchildContribute.first + rchildContribute.second + 1;
    }
    mapNodePair[node] = contribute;
    return max(max(lmax, rmax), contribute.first + contribute.second + 1);
}

int func(Node *node){
    map<Node*, pair<int, int>> mapNodePair;
    return postOrder(node, mapNodePair);
}

void display(Node *node){
    if(!node) return;
    cout<<node->val<<", ";
    display(node->lchild);
    display(node->rchild);
}

int main(){
    Node *tree = testCase();
    int ret = func(tree);
    //display(tree);
    //cout<<endl;
    cout<<ret<<"\n";
}