#include <iostream>

using namespace std;

class Node{
public:
    int val;
    Node *next;
    Node(int x = 0):val(x), next(nullptr){}
};


///head 指向链表的真实头部
Node *reversePartLinkedList(Node *head, int from, int to){
    Node *sudoHead = new Node();
    sudoHead->next = head;
    Node *beforeFrom = sudoHead, *afterTo = nullptr;
    Node *current = sudoHead;
    int step = 0;
    while(current != nullptr){
        if(step == (from-1)){
            beforeFrom = current;
            step++;
            current = current->next;
            break; 
        }
        else{
            current = current->next;
            step++;
        }
    }

    while(current != nullptr){
        if(step == (to+1)){
            afterTo = current;
            break;
        }
        else{
            current = current->next;
            step++;
        }
    }

    if(step <= from){
        return nullptr;
    }

    beforeFrom->next = afterTo;

    return sudoHead->next;
}

Node* generateList(int length){
    Node head;
    Node *current = &head;
    for(int i = 0; i < length; ++i){
        Node *newNode = new Node(i);
        current->next = newNode;
        current = newNode;
    }

    return head.next;
}


int main(){
    Node *input = generateList(5);
    Node *ret = reversePartLinkedList(input, 2, 4);
    Node *current = ret;
    while(current != nullptr){
        cout<<current->val<<", ";
        current = current->next;
    }
    cout<<endl;
}