///找到二叉树中的最大搜索二叉子树
///返回这棵子树的头结点
#include <iostream>


using namespace std;

struct Node{
    int val;
    Node *lchild;
    Node *rchild;
    Node(int x = 0):val(x), lchild(nullptr), rchild(nullptr){}
};

Node* maxSearchTree(Node *root, int &maxNodeNum, int &maxVal, int &minVal){
    if(root == nullptr){
        maxNodeNum = 0;
        return nullptr;
    } 
    int lmaxNodeNum, rmaxNodeNum, lmaxVal, lminVal, rmaxVal, rminVal;
    Node *lret = maxSearchTree(root->lchild, lmaxNodeNum, lmaxVal, lminVal);
    Node *rret = maxSearchTree(root->rchild, rmaxNodeNum, rmaxVal, rminVal);
    if(lret == root->lchild && rret == root->rchild ){
        bool cond1 = !root->lchild || (lret == root->lchild && root->val >= lmaxVal);
        bool cond2 = !root->rchild || (rret == root->rchild && root->val <= rminVal);
        if(cond1 && cond2){
            maxNodeNum = lmaxNodeNum + rmaxNodeNum + 1;
            maxVal = root->rchild?rmaxVal:root->val;
            minVal = root->lchild?lminVal:root->val;
            return root;
        }
        
    }

    if(lmaxNodeNum > rmaxNodeNum){
        maxNodeNum = lmaxNodeNum;
        return lret;
    }
    else{
        maxNodeNum = rmaxNodeNum;
        return rret;
    }
    
}

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

void display(Node *node){
    if(!node) return;
    cout<<node->val<<", ";
    display(node->lchild);
    display(node->rchild);
}

int main(){
    Node *root = testCase();
    int maxNodeNum, minVal, maxVal;
    Node *ret = maxSearchTree(root, maxNodeNum, minVal, maxVal);
    cout<<maxNodeNum<<endl;
    display(ret);
}