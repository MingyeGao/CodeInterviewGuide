///二叉树的按层打印与ZigZag打印

#include <iostream>
#include <queue>
#include <deque>

using namespace std;

struct Node{
    int val;
    Node *lchild;
    Node *rchild;
    Node(int x = 0):val(x), lchild(nullptr), rchild(nullptr){}
};

void levelPrint(Node *root){
    if(!root) return;
    Node *last = root;
    Node *nextLast = nullptr;
    queue<Node*> q;
    q.push(root);
    int level = 1;
    cout<<"level "<<level<<": ";
    while(!q.empty()){
        Node *current = q.front();
        q.pop();
        cout<<current->val<<", ";
        if(current->lchild){
            nextLast = current->lchild;
            q.push(current->lchild);
        }

        if(current->rchild){
            nextLast = current->rchild;
            q.push(current->rchild);
        }

        if(current == last && !q.empty()){
            level += 1;
            cout<<"\n"<<"level "<<level<<": ";
            last = nextLast;
        }
    }
    cout<<"\n";
}

void zigzagPrint(Node *root){
    if(!root) return;
    deque<Node *> dq;
    bool l2r = true;
    dq.push_back(root);
    int level = 1;
    bool isLevelFirst = true;
    Node *last = root;
    Node *nlast = nullptr;
    cout<<"level 1 from left to right: ";
    while(!dq.empty()){
        if(l2r){
            Node *current = dq.front();
            dq.pop_front();
            cout<<current->val<<", ";
            if(current->lchild){
                dq.push_back(current->lchild);
                if(isLevelFirst){
                    nlast = current->lchild;
                    isLevelFirst = false;
                }
            }

            if(current->rchild){
                dq.push_back(current->rchild);
                if(isLevelFirst){
                    nlast = current->rchild;
                    isLevelFirst = false;
                }
            }

            if(current == last && !dq.empty()){
                level++;
                cout<<"\nlevel "<<level<<" from right to left: ";
                isLevelFirst = true;
                last = nlast;
                l2r = false;
            }
        }
        else{
            Node *current = dq.back();
            dq.pop_back();
            cout<<current->val<<", ";

            if(current->rchild){
                dq.push_front(current->rchild);
                if(isLevelFirst){
                    nlast = current->rchild;
                    isLevelFirst = false;
                }
            }
            if(current->lchild){
                dq.push_front(current->lchild);
                if(isLevelFirst){
                    nlast = current->lchild;
                    isLevelFirst = false;
                }
            }
            if(current == last && !dq.empty()){
                ++level;
                cout<<"\nlevel "<<level<<" from right to left: ";
                last = nlast;
                isLevelFirst = true;
                l2r = true;
            }

        }
    }
    cout<<"\n";
}

Node *testCase(){
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
    node3->lchild = node5;
    node3->rchild = node6;
    node5->lchild = node7;
    node5->rchild = node8;
    return node1;
}

int main(){
    Node *tree = testCase();
    levelPrint(tree);
    zigzagPrint(tree);
}