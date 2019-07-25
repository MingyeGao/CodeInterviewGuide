///通过有序数列生成二叉平衡搜索树
#include <iostream>
#include <vector>
#include <initializer_list>
using namespace std;

struct Node{
    int val;
    Node *lchild;
    Node *rchild;
    Node(int x = 0):val(x), lchild(nullptr), rchild(nullptr){}
};

Node *vec2BST(vector<int> &input, int from, int to){
    if(from > to) return nullptr;

    int middle = (to - from)/2 + from;

    Node *root = new Node(input[middle]);

    Node *lchild = vec2BST(input, from, middle - 1);

    Node *rchild = vec2BST(input, middle + 1, to);

    root->lchild = lchild;

    root->rchild = rchild;

    return root;
}

void preOrder(Node *node){
    if(!node) return;
    cout<<node->val<<", ";
    preOrder(node->lchild);
    preOrder(node->rchild);
}

int main(){
    vector<int> input({1, 2, 3, 4, 5, 6});
    Node *tree = vec2BST(input, 0, 5);
    preOrder(tree);
}

