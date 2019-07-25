#include <assert.h>
#include <iostream>

using namespace std;

class Node{
public:
    int val;
    Node *next;
    Node(int val = 0):val(val), next(nullptr){}
};

Node *generateList(int length){
    Node dummyHead;
    Node *current = &dummyHead;
    for(int i = 1; i <= length; ++i){
        Node *newNode = new Node(i);
        current->next = newNode;
        current = newNode;
    }
    return dummyHead.next;
}

void remove(Node *node){
    assert(node->next);
    node->val = node->next->val;
    node->next = node->next->next;
}

int main(){
    Node *list = generateList(5);
    remove(list->next->next);
    Node *p = list;
    while(p){
        cout<<p->val<<", ";
        p = p->next;
    }
}