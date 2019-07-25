///调整搜索二叉树中两个错误的节点

#include <iostream>
#include <vector>
#include <climits>
using namespace std;

struct Node{
    int val;
    Node *lchild;
    Node *rchild;
    Node(int x = 0):val(x), lchild(nullptr), rchild(nullptr){}
};

void inOrder(Node *root, vector<Node*> nodes){
    if(!root) return;
    inOrder(root->lchild, nodes);
    nodes.push_back(root);
    inOrder(root->rchild, nodes);
}

void adjust(Node *root, Node *e1, Node *e2){

}

void getErrorNodes(Node *root, vector<Node*> &errorNodes){
    vector<Node*> nodes;
    inOrder(root, nodes);
    int i = 1;
    for(; i < nodes.size(); ++i){
        if(nodes[i] > nodes[i - 1]){
            errorNodes[0] = nodes[i - 1];
            break;
        }
    }
    for(; i < nodes.size(); ++i){
        if(nodes[i] > nodes[i - 1]){
            errorNodes[1] = nodes[i];
            break;
        }
    }
}

int main(){
    
}