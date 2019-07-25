#include <assert.h>
#include <iostream>
#include <vector>

using namespace std;

struct Node{
    int val;
    Node *lchild;
    Node *rchild;
    Node(int x = 0):val(x), lchild(nullptr), rchild(nullptr){};
};

Node *leftRightmost(Node *node){
    if(!node->lchild) return nullptr;
    Node *current = node->lchild;
    while(current->rchild && current->rchild != node){
        current = current->rchild;
    }
    return current;

}

Node *testCase1(){
    Node *node1 = new Node(1);
    Node *node2 = new Node(2);
    Node *node3 = new Node(3);
    Node *node4 = new Node(4);
    Node *node5 = new Node(5);
    Node *node6 = new Node(6);
    Node *node7 = new Node(7);
    node4->lchild = node2;
    node4->rchild = node6;
    node2->lchild = node1;
    node2->rchild = node3;
    node6->lchild = node5;
    node6->rchild = node7;
    return node4;
}

void inOrder(Node *node){

    Node *current = node;
    while(current){
        while(current->lchild){
            Node *node1 = leftRightmost(current);
            if(!node1) break;
            node1->rchild = current;
            current = current->lchild;
        }

        cout<<current->val<<", ";
        current = current->rchild;
        if(current == nullptr) break;
        Node *currentLeftRightmost = leftRightmost(current);

        while(currentLeftRightmost && currentLeftRightmost->rchild == current){
            currentLeftRightmost->rchild = nullptr;
            cout<<current->val<<", ";
            current = current->rchild;
            currentLeftRightmost = leftRightmost(current);
        }
    }
    cout<<"\n";
    
}

void preOrder(Node *node){
    Node *current = node;
    while(current){
        while(current->lchild){
            cout<<current->val<<", ";
            Node *node1 = leftRightmost(current);
            if(!node1) break;
            node1->rchild = current;
            current = current->lchild;
        }

        cout<<current->val<<", ";
        current = current->rchild;
        if(current == nullptr) break;
        Node *currentLeftRightmost = leftRightmost(current);
        while(currentLeftRightmost && currentLeftRightmost->rchild == current){
            currentLeftRightmost->rchild = nullptr;
            current = current->rchild;
            currentLeftRightmost = leftRightmost(current);
        }
    }
    cout<<"\n";
}

void reverseNode(Node *start, Node *end){
    Node *current = start;
    Node *prev = end;
    while(current != end){
        Node *tmp = current->rchild;
        current->rchild = prev;
        prev = current;
        current = tmp;
    }
}


Node * reverseRightEdge(Node *head){
    Node *p = head;
    Node *prev = nullptr;
    while(p){
        Node *tmp = p->rchild;
        p->rchild = prev;
        prev = p;
        p = tmp;
    }
    return prev;
}

void postOrder(Node *node){
    Node *current = node;
    vector<int> num;
    while(current){
        Node *currentLeftRightmost;
        while(current->lchild){
            currentLeftRightmost = leftRightmost(current);
            currentLeftRightmost->rchild = current;
            current = current->lchild;
        }

        if(!current->rchild){
            Node *rightmostNode = reverseRightEdge(node);
            Node *p = rightmostNode;
            while(p != node){
                cout<<p->val<<", ";
                num.push_back(p->val);
                p = p->rchild;
            }
            cout<<p->val<<", ";
            num.push_back(p->val);
            reverseRightEdge(rightmostNode);
            break;
        }
        current = current->rchild;
        currentLeftRightmost = leftRightmost(current);
        if(current != currentLeftRightmost->rchild){
            continue;
        }
        ///逆序打印current的左子树右边界
        reverseNode(current->lchild, current);
        Node *p = currentLeftRightmost;
        while(p != current){
            cout<<p->val<<", ";
            num.push_back(p->val);
            p = p->rchild;
        }
        reverseNode(currentLeftRightmost, current);
        ///
        currentLeftRightmost->rchild = nullptr;
        current = current->rchild;
    }
}

int main(){
    Node *tree = testCase1();
    inOrder(tree);
    preOrder(tree);
    postOrder(tree);
}