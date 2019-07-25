#include <iostream>
#include <vector>
#include <initializer_list>

using namespace std;

class Node{
public:
    int val;
    Node *next;
    Node *prev;
    Node(int x = 0):val(x), next(nullptr), prev(nullptr){};
};

Node *vector2list(vector<int> &input){
    Node dummyHead;
    Node *current = &dummyHead;
    for(int i = 0; i < input.size(); ++i){
        Node *newNode = new Node(input[i]);
        current->next = newNode;
        newNode->prev = current;
        current = newNode;
    }
    current->next = dummyHead.next;
    dummyHead.next->prev = current;
    return dummyHead.next;
}

Node *insert(Node *list, int num){
    Node *newNode = new Node(num);
    Node *p = list;
    if(num <= list->val){
        list->prev->next = newNode;
        newNode->prev = list->prev;
        list->prev = newNode;
        newNode->next = list;
        return newNode;
    }
    p = list->next;
    while(p != list){
        if(num <= p->val){
            p->prev->next = newNode;
            newNode->prev = p;
            newNode->next = p;
            p->prev = newNode;
            return list;
        }
        p = p->next;
    }

    list->prev->next = newNode;
    newNode->prev = list->prev;
    newNode->next = list;
    list->prev = newNode;
    return list;
}

void display(Node *list){
    Node *p = list;
    bool flag = true;
    while(flag){
        cout<<p->val<<", ";
        p = p->next;
        if(p == list) flag = false;
    }
    cout<<endl;
}

int main(){
    vector<int> input({1, 2, 3, 5, 5, 7});
    Node *list = vector2list(input);
    Node *ret = insert(list, 8);
    display(ret);
}

