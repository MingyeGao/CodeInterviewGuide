#include <assert.h>
#include <iostream>
#include <vector>
#include <initializer_list>

using namespace std;

class Node{
public:
    int val;
    Node *next;
    Node(int x = 0):val(x), next(nullptr){};
};

Node *chooseSort(Node *list){
    Node *head = new Node();
    Node *sortedHead = new Node();
    head->next = list;
    Node *sortedTail = sortedHead;
    while(head->next != nullptr){
        Node *p = head->next;
        Node *prev = head;
        Node *minP = p;
        Node *minPrev = head;
        int minVal = p->val;
        while(p != nullptr){
            if(p->val < minVal){
                minVal = p->val;
                minP = p;
                minPrev = prev;
            }
            prev = p;
            p = p->next;
        }

        sortedTail->next = minP;
        assert(minPrev->next == minP);
        minPrev->next= minP->next;
        minP->next = nullptr;
        sortedTail = minP;
    }

    return sortedHead->next;
}

Node *vector2list(vector<int> &input){
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
    vector<int> input({1,4,7,3,6,9});
    Node *list = vector2list(input);

    Node *ret = chooseSort(list);
    Node *current = ret;
    while(current != nullptr){
        cout<<current->val<<", "<<endl;
        current = current->next;
    }
}