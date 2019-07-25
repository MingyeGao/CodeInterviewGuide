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

Node *removeNum(Node *list, int num){
    Node dummyHead;
    dummyHead.next = list;
    Node *prev = &dummyHead;
    Node *current = list;
    while(current != nullptr){
        if(current->val == num){
            prev->next = current->next;
        }
        else{
            prev = current;
        }
        current = current->next;
    }

    return dummyHead.next;
}

Node *vector2list(vector<int> &input){
    Node dummyHead;
    Node *p = &dummyHead;
    for(int i = 0; i < input.size(); ++i){
        Node *newNode = new Node(input[i]);
        p->next = newNode;
        p = newNode;
    }
    return dummyHead.next;
}

void display(Node *list){
    Node *p = list;
    while(p != nullptr){
        cout<<p->val<<", ";
        p = p->next;
    }
    cout<<endl;
}

int main(){
    vector<int> input({1,2,3,3,3});
    Node *list = vector2list(input);
    Node *ret = removeNum(list, 1);
    display(ret);
}