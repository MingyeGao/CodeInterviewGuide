///直观地打印二叉树
#include <iostream>
#include <climits>
#include <sstream>

using namespace std;

struct Node{
    int val;
    Node *lchild;
    Node *rchild;
    Node(int x = 0):val(x), lchild(nullptr), rchild(nullptr){};
};

Node *testCase1(){
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
    node4->rchild = node7;
    node3->lchild = node5;
    node3->rchild = node6;
    return node1;
}
int kOneNumLen = 17;

void prettyPrint(Node *node, int level, char s){
    if(!node) return;
    if(node->rchild){
        prettyPrint(node->rchild, level + 1, 'v');
    }

    cout<<string(level*17, ' ');
    ostringstream oneNum;
    oneNum<<s<<node->val<<s;
    int diff = kOneNumLen - oneNum.str().size();
    cout<<string(diff/2, ' ')<<oneNum.str()<<string(diff - diff/2, ' ')<<'\n';

    if(node->lchild){
        prettyPrint(node->lchild, level + 1, '^');
    }
    
}

int main(){
    Node *tree = testCase1();
    prettyPrint(tree, 0, 'H');
}