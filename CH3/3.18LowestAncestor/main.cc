///在二叉树中找到两个节点的最近公共祖先
///给定一棵二叉树的头结点以及树中的两个节点

#include <iostream>
#include <map>
#include <set>

using namespace std;

struct Node{
    int val;
    Node *lchild;
    Node *rchild;
    Node(int x = 0):val(x), lchild(nullptr), rchild(nullptr){}
};

Node *lowestAncestor(Node *root, Node *n1, Node *n2){
    if(!root || root == n1 || root == n2){
        return root;
    }

    Node *lret = lowestAncestor(root->lchild, n1, n2);
    Node *rret = lowestAncestor(root->rchild, n1, n2);

    if(lret && rret){
        return root;
    }

    return lret?lret:rret;
}

void fillMap(Node *node, map<Node*, Node*> &mapNodeFather){
    if(!node) return;
    if(node->lchild){
        mapNodeFather[node->lchild] = node;
        fillMap(node->lchild, mapNodeFather);
    }
    if(node->rchild){
        mapNodeFather[node->rchild] = node;
        fillMap(node->rchild, mapNodeFather);
    } 

}

Node *lowestAncestorByMap(Node *root, Node *n1, Node *n2){
    map<Node *, Node *> mapNodeFather;
    mapNodeFather[root] = nullptr;
    fillMap(root, mapNodeFather);
    set<Node*> n1Ancestors;
    Node *current = n1;
    n1Ancestors.insert(n1);
    while(mapNodeFather.find(current) != mapNodeFather.end()){
        n1Ancestors.insert(mapNodeFather[current]);
        current = mapNodeFather[current];
    }

    current = n2;
    while(n1Ancestors.find(current) == n1Ancestors.end()){
        current = mapNodeFather[current];
    }
    return current;

}

void testCase(Node *&root, Node *&n1, Node *&n2){
    Node *node1 = new Node(1);
    Node *node2 = new Node(2);
    Node *node3 = new Node(3);
    Node *node4 = new Node(4);
    Node *node5 = new Node(5);
    Node *node6 = new Node(6);
    Node *node7 = new Node(7);
    Node *node8 = new Node(8);
    node1->lchild = node2;
    node1->rchild = node3;
    node2->lchild = node4;
    node2->rchild = node5;
    node3->lchild = node6;
    node3->rchild = node7;
    node7->lchild = node8;
    root = node1;
    n1 = node6;
    n2 = node8;
}

int main(){
    Node *root, *node1, *node2;
    testCase(root, node1, node2);
    Node *ret = lowestAncestor(root, node1, node2);
    ret = lowestAncestorByMap(root, node1, node2);
    cout<<ret->val<<endl;
}
