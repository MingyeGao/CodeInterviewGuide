///通过后序数组重建搜索二叉树
///数组中没有重复的元素

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

Node *rebuildBST(vector<int> &postOrder, int from, int to){
    if(from > to) return nullptr;
    int rootVal = postOrder[to];
    Node *newNode = new Node(rootVal);

    int i;
    for(i = from; i < to; ++i){
        if(postOrder[i] > rootVal) break;
    }

    Node* lchild = rebuildBST(postOrder, from, i - 1);
    Node *rchild = rebuildBST(postOrder, i, to - 1);
    newNode->lchild = lchild;
    newNode->rchild = rchild;
    return newNode;
}

void preOrder(Node *node){
    if(!node) return ;
    cout<<node->val<<", ";
    preOrder(node->lchild);
    preOrder(node->rchild);
}

int main(){
    vector<int> input({1, 3, 2, 7, 9, 6, 4});
    Node *ret = rebuildBST(input, 0, input.size()-1);
    preOrder(ret);
}