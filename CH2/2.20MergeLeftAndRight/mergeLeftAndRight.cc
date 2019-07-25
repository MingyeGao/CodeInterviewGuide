///按照左右半区的方式重新组合单链表

#include <iostream>
#include <vector>
using namespace std;

class Node{
public:
    int val;
    Node *next;
    Node(int x = 0):val(x), next(nullptr){};
};

Node *vector2list(vector<int> &input){
    Node dummyHead;
    Node *current = &dummyHead;
    for(int i = 0; i < input.size(); ++i){
        Node *newNode = new Node(input[i]);
        current->next = newNode;
        current = newNode;
    }
    return dummyHead.next;
}

Node *merge(Node *p1, Node *p2){
    Node dummyHead;
    Node *current = &dummyHead;
    Node *terminal = p2;
    while(p1 != terminal){
        Node *p1Next = p1->next;
        Node *p2Next = p2->next;
        current->next = p1;
        current = current->next;
        current->next = p2;
        current = current->next;
        p1 = p1Next;
        p2 = p2Next;
    }
    return dummyHead.next;
}

Node *func(Node *list){
    if(!list || !list->next || !list->next->next) return list;
    Node *p1 = list, *p2 = list;
    while(p2->next && p2->next->next){
        p1 = p1->next;
        p2 = p2->next->next;
    }

    if(!p2->next){
        merge(list, p1);
    }
    else{
        merge(list, p1->next);
    }

}

void display(Node *list){
    Node *current = list;
    while(current){
        cout<<current->val<<", ";
        current = current->next;
    }
}

int main(){
    vector<int> input({1, 2, 3, 4, 5});
    Node *list = vector2list(input);
    Node *ret = func(list);
    display(list);
}