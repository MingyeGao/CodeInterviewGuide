#include <iostream>

using namespace std;

class Node{
public:
    Node(int x = 0):val(x), next(nullptr){}
    int val;
    Node *next;
};

void removeLastKthNode(Node *node, int k){
    Node *quickPointer = node;
    int step = 0;
    while(quickPointer != nullptr && step < k){
        quickPointer = quickPointer->next;
        ++step;
    }

    if(step != k) return;

    Node *slowPointer = node;
    while(quickPointer->next != nullptr){
        quickPointer  = quickPointer->next;
        slowPointer = slowPointer->next;
    }

    slowPointer->next = slowPointer->next->next;
}

int main(){
    Node *node1 = new Node(1);
    Node *node2 = new Node(2);
    Node *node3 = new Node(3);
    node1->next = node2;
    node2->next = node3;
    removeLastKthNode(node1, 2);

    Node *currentNode = node1;
    while(currentNode != nullptr){
        cout<<currentNode->val<<", ";
        currentNode = currentNode->next;
    }
}