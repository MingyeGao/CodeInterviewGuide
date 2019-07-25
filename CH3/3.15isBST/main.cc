///判断一棵二叉树是否为搜索二叉树和完全二叉树
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct Node{
    int val;
    Node *lchild;
    Node *rchild;
    Node(int x = 0):val(x), lchild(nullptr), rchild(nullptr){}
};

void inOrder(Node *t, vector<int> &val){
    if(!t) return;
    inOrder(t->lchild, val);
    val.push_back(t->val);
    inOrder(t->rchild, val);
}

bool isBST(Node *root){
    vector<int> val;
    inOrder(root, val);
    for(int i = 1; i < val.size(); ++i){
        if(val[i] < val[i - 1]){
            return false;
        }
    }
    return true;
}

bool isCST(Node *root){
    if(!root) return true;
    queue<Node*> q;
    q.push(root);
    while(!q.empty()){
        Node *current = q.front();
        q.pop();
        if(!current->lchild && current->rchild){
            return false;
        }

        if(!current->lchild || !current->lchild){
            while(!q.empty()){
                Node *node = q.front();
                q.pop();
                if(!node->lchild || !node->rchild){
                    return false;
                }
            }
            return true;
        }

        q.push(current->lchild);
        q.push(current->rchild);
    }

    return true;
}

int main(){
    
}