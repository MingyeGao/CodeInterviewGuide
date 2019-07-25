///判断一个链表是否是回文链表
#include <assert.h>
#include <iostream>
#include <vector>

using namespace std;

class Node{
public:
    int val;
    Node *next;
    Node(int x = 0):val(x), next(nullptr){}
};


///
bool isPalindromeLinkedList(Node *node){
    if(node == nullptr) return true;
    if(node->next == nullptr) return true;
    int size = 0;
    Node pseudoNode;
    Node *reversePartCurrent = &pseudoNode;
    Node *head = new Node();

    Node *p1 = node, *p2 = node;
    while(p2->next != nullptr && p2->next->next != nullptr){
        p2 = p2->next->next;
        Node *tmp = p1->next;
        p1->next = reversePartCurrent->next;
        reversePartCurrent->next = p1;
        p1 = tmp;
        
    }

    Node *p3, *p4;
    if(p2->next == nullptr){//listSize is odd
        p4 = p1->next;
    }
    else{
        Node *tmp = p1->next;
        p1->next = reversePartCurrent->next;
        reversePartCurrent->next = p1;
        p1 = tmp;
        p4 = p1;
    }
    p3 = pseudoNode.next;
    bool ret = true;;
    while(p3 != nullptr){
        if(p3->val != p4->val){
            //return false;
            ret = false;
            break;
        }
        else{
            p3 = p3->next;
            p4 = p4->next;
        }
    }

    ///restore list
    Node *currentNode = p1;
    Node *reversePartNode = pseudoNode.next;
    while(reversePartNode != nullptr){
        Node *tmp = reversePartNode->next;
        reversePartNode->next = currentNode;
        currentNode = reversePartNode;
        reversePartNode = tmp;
    }

    return ret;
}

Node* vec2list(vector<int> &input){
    Node head;
    Node *current = &head;
    for(int i = 0; i < input.size(); ++i){
        Node *newNode = new Node(input[i]);
        current->next = newNode;
        current = newNode;
    }

    return head.next;
}

int main(){
    vector<int> input1({0,1,1,2,0});
    Node *list1 = vec2list(input1);
    bool ret = isPalindromeLinkedList(list1);
    assert(ret);
}
