///用非递归的方式遍历二叉树

#include <iostream>
#include <stack>
using namespace std;

struct Node{
    int val;
    Node *lchild;
    Node *rchild;
    Node(int x = 0):val(x), lchild(nullptr), rchild(nullptr){};
};

void preOrder(Node *node){
    stack<Node*> s;
    Node *current = node;
    while(current || !s.empty()){
        if(current == nullptr){
            current = s.top();
            s.pop();
        }
        else{
            cout<<current->val<<", ";
            if(current->rchild){
                s.push(current->rchild);
            }
            current = current->lchild;
        }
    }
    cout<<endl;
}

void inOrder(Node *node){
    stack<Node*> s;
    Node *current = node;
    while(current || !s.empty()){
        if(current){
            if(current->lchild){
                s.push(current);
                current = current->lchild;
            }
            else{
                cout<<current->val<<", ";
                current = current->rchild;
            }
        }
        else{
            current = s.top();
            s.pop();
            cout<<current->val<<", ";
            current = current->rchild;
        }
    }
    cout<<endl;
}

void postOrder(Node *node){
    stack<Node*> s;
    Node *current = node;
    Node *prev;
    if(!node) return;
    //s.push(node);
    while(current || !s.empty()){
        if(current){
            if(current->lchild){
                s.push(current);
                current = current->lchild;
            }
            else if(current->rchild){
                s.push(current);
                current = current->rchild;
            }
            else{
                cout<<current->val<<", ";
                prev = current;
                current = nullptr;
            }
        }
        else{
            current = s.top();
            s.pop();
            while(!s.empty() &&
              ( (prev == current->rchild) || (prev == current->lchild && !current->rchild))){
                cout<<current->val<<", ";
                prev = current;
                current = s.top();
                s.pop();
            }
            
            if(s.empty() && 
              (prev == current->rchild) || (prev == current->lchild && !current->rchild)){
                cout<<current->val<<", ";
                break;
            }
            else{
                s.push(current);
                current = current->rchild;
            }
        }

    }
}

void postOrder2(Node *root){
    if(!root) return;
    stack<Node*> s;
    Node *h = root;
    Node *c;
    s.push(root);
    while(!s.empty()){
        c = s.top();
        if(c->lchild && h != c->lchild && h != c->rchild){
            s.push(c->lchild);
        }
        else if(c->rchild && h != c->rchild){
            s.push(c->rchild);
        }
        else{
            cout<<c->val<<", ";
            s.pop();
            h = c;
        }
    }

}

int main(){
    Node *node1 = new Node(1);
    Node *node2 = new Node(2);
    Node *node3 = new Node(3);
    Node *node4 = new Node(4);
    Node *node5 = new Node(5);
    node1->lchild = node2;
    node1->rchild = node3;
    node2->lchild = node4;
    node3->rchild = node5;
    preOrder(node1);
    inOrder(node1);
    postOrder2(node1);
}
