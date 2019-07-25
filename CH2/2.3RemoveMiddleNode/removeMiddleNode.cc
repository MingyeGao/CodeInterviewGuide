#include <iostream>
#include <cmath>
using namespace std;

class Node{
public:
    int val;
    Node *next;
    Node(int x = 0):val(x), next(nullptr){};
};

void removeMiddleNode(Node *head){
    if(head->next == nullptr || head->next->next == nullptr) return;
    if(head->next->next->next == nullptr){
        head->next = head->next->next;
    }
    Node *p1 = head->next;
    Node *p2 = head->next->next->next;
    while(p2->next != nullptr && p2->next->next != nullptr){
        p1 = p1->next;
        p2 = p2->next->next;
    }

    p1->next = p1->next->next;
}

void removeCertainNodeByRatio(Node *head, double ratio){
    int listNum = 0;
    Node *currentNode = head->next;
    while(currentNode != nullptr){
        ++listNum;
        currentNode = currentNode->next;
    }

    int index = floor(ratio*listNum);
    currentNode = head;
    for(int i = 0; i < index - 1; ++i){
        currentNode = currentNode->next;
    }

    currentNode->next = currentNode->next->next;
}

Node *generateList(int length){
    Node *head = new Node();
    Node *currentNode = head;
    for(int i = 1; i <= length; ++i){
        Node *newNode = new Node(i);
        currentNode->next = newNode;
        currentNode = newNode;
    }

    return head;
}

int main(){
    Node *head = generateList(6);
    //removeMiddleNode(head);
    removeCertainNodeByRatio(head, 0.5);
    Node *currentNode = head->next;
    while(currentNode != nullptr){
        cout<<currentNode->val<<", ";
        currentNode = currentNode->next;
    }
}