#include <iostream>

using namespace std;

class Node{
public:
    int val;
    Node *next;
    Node *rand;
    Node(int x = 0):val(x), next(nullptr), rand(nullptr){};
};

Node* copyRandomNode(Node *list){
    Node *current = list;
    while(current != nullptr){
        Node *tmp = current->next;
        Node *newNode = new Node(current->val);
        newNode->next = current->next;
        current->next = newNode;
        current = tmp;
    }

    current = list;
    while(current != nullptr){
        Node *newNode = current->next;
        if(current->rand == nullptr){
            newNode->rand = nullptr;
        }
        else{
            newNode->rand = current->rand->next;
        }
        
        current = current->next->next;
    }

    current = list;

    Node head;
    Node *retNode = &head;
    while(current != nullptr){
        retNode->next = current->next;
        retNode = retNode->next;
        current = current->next->next;
        
    }

    return head.next;
}

int main(){
    Node *node1 = new Node(1);
    Node *node2 = new Node(2);
    Node *node3 = new Node(3);

    node1->next = node2;
    node2->next = node3;
    node1->rand = node3;
    node3->rand = node1;

    Node *retNode = copyRandomNode(node1);

    Node *current = retNode;
    while(current != nullptr){
        cout<<current->val<<", ";
        if(current->rand == nullptr){
            cout<<"rand is nullptr"<<endl;
        }
        else{
            cout<<"rand val is "<<current->val<<endl;
        }
        current = current->next;
    }
}