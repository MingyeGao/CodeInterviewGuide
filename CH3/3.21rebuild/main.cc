///先序，中序和后序数组两两组合重构二叉树
#include <assert.h>
#include <iostream>
#include <vector>
#include <initializer_list>
using namespace std;

struct Node{
    int val;
    Node *lchild;
    Node *rchild;
    Node(int x = 0):val(x), lchild(nullptr),rchild(nullptr){}
};

Node *PreIn(vector<int> &pre, vector<int> &in, 
            int preStart, int preEnd, int inStart, int inEnd){
    
    if(preStart > preEnd) return nullptr;
    Node *root = new Node(pre[preStart]);
    int index = inStart;
    for(; index < inEnd; ++index){
        if(in[index] == pre[preStart]){
            break;
        }
    }
    int llen = index - inStart;
    int rlen = inEnd - index;

    Node *l = PreIn(pre, in, preStart + 1, preStart + llen, inStart, index-1);
    Node *r = PreIn(pre, in, preStart+llen+1, preEnd, index+1, inEnd);
    root->lchild = l;
    root->rchild = r;
    return root;
}

Node *PostIn(vector<int> &post, vector<int> &in,
             int postStart, int postEnd, int inStart, int inEnd){

    if(postStart > postEnd) return nullptr;
    Node *root = new Node(post[postEnd]);
    int index = inStart;
    for(; index < inEnd; ++index){
        if(in[index] == post[postEnd]){
            break;
        }
    }

    int llen = index - inStart;
    int rlen = inEnd - index;
    Node *l = PostIn(post, in, postStart, postStart+llen-1, inStart, index-1);
    Node *r = PostIn(post, in, postStart + llen, postEnd - 1, index + 1, inEnd);

    root->lchild = l;
    root->rchild = r;
    return root;
}

Node *PrePost(vector<int> &pre, vector<int> &post, 
              int preStart, int preEnd, int postStart, int postEnd){

    if(preStart > preEnd) return nullptr;
    Node *root = new Node(pre[preStart]);
    Node *l, *r;
    if(preStart + 1 > preEnd){
        return root;
    }
    else{
        int lrootVal = pre[preStart+1];
        int index = postStart;
        for(; index < postEnd; index++){
            if(post[index] == lrootVal){
                break;
            }
        }
        int llen = index - postStart + 1;
        int rrootVal = pre[preStart + llen];
        l = PrePost(pre, post, preStart + 1, preStart + llen, postStart, postStart+llen-1);
        r = PrePost(pre, post, preStart+llen+1, preEnd, postStart+llen, postEnd-1);
        assert(l && r);
        root->lchild = l;
        root->rchild = r;
        return root;
    }
}

void preOrder(Node *node){
    if(!node) return;
    cout<<node->val<<", ";
    preOrder(node->lchild);
    preOrder(node->rchild);
}

int main(){
///      1
///   /    \
///  2       3
/// / \    /   \
///4   5  6     7
    vector<int> pre({1, 2, 4, 5, 3, 6, 7});
    vector<int> in({4, 2, 5, 1, 6, 3, 7});
    vector<int> post({4, 5, 2, 6, 7, 3, 1});
    Node *ret1 = PreIn(pre, in, 0, 6, 0, 6);
    preOrder(ret1);
    cout<<endl;
    Node *ret2 = PostIn(post, in, 0, 6, 0, 6);
    preOrder(ret2);
    cout<<endl;
    Node *ret3 = PrePost(pre, post, 0, 6, 0, 6);
    preOrder(ret3);
    cout<<endl;
}