///二叉树中的最长路径
#include <iostream>

using namespace std;

struct Node{
    int val;
    Node *lchild;
    Node *rchild;
    Node(int x = 0):val(x), lchild(nullptr), rchild(nullptr){}
};

int getMaxLength(Node *root, int &maxVal){
    if(!root) return 0;

    int llen = getMaxLength(root->lchild, maxVal);
    int rlen = getMaxLength(root->rchild, maxVal);

    maxVal = max(max(llen, rlen), llen+rlen+1);

    return max(llen, rlen)+1;
}

Node *testCase(){
//       1
//      / \
//     2   3
//    / \    \
//   4   5    6
//  /     \
// 7       8
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
    node3->rchild = node6;
    node2->lchild = node4;
    node2->rchild = node5;
    node4->lchild = node7;
    node5->rchild = node8;
    return node1;
}

int main(){
    Node *tree = testCase();
    int maxVal;
    int ret = getMaxLength(tree, maxVal);
    cout<<maxVal<<endl;
}