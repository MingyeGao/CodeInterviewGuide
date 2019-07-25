#include <iostream>

using namespace std;

class Node{
public:
    int val;
    Node *next;
    Node(int x = 0):val(x), next(nullptr){};
};

Node* reverseLinkedList(Node *head){
    Node *pseudoHead = new Node();
    Node *currentNode = head;
    while(currentNode != nullptr){
        Node *tmp = currentNode->next;
        currentNode->next = pseudoHead->next;
        pseudoHead->next = currentNode;
        currentNode = tmp;
    }

    return pseudoHead->next;
}

Node *generateLinkedList(int length){
    Node *head = new Node();
    Node *current = head;
    for(int i = 1; i <= length; ++i){
        Node *newNode = new Node(i);
        current->next = newNode;
        current = newNode;
    }

    return head->next;
}

int main(){
    Node *linkedList = generateLinkedList(5);
    linkedList = reverseLinkedList(linkedList);
    Node *current = linkedList;
    while(current != nullptr){
        cout<<current->val<<", ";
        current = current->next;
    }

}