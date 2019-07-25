#include <iostream>
#include <set>

using namespace std;

class Node{
public:
    int val;
    Node *next;
    Node(int x = 0):val(x), next(nullptr){};
};

void removeDuplicateNode1(Node *list1){
    
    if(list1 == nullptr || list1->next == nullptr) return;
    set<int> s;
    Node *prev = list1, *current = list1->next;
    s.insert(prev->val);

    while(current != nullptr){
        int val = current->val;
        if(s.find(val) != s.end()){
            Node *tmp = current->next;
            prev->next = current->next;
            current = tmp;
        }
        else{
            s.insert(current->val);
            prev = current;
            current = current->next;
        }
    }
}

void removeDuplicateNode2(Node *list1){
    Node *current = list1;
    while(current != nullptr){
        int val = current->val;
        Node *p = current->next;
        Node *prev = current;
        while(p != nullptr){
            if(p->val == val){
                Node *tmp = p->next;
                prev->next = p->next;
                p = tmp;
            }
            else{
                prev = p;
                p = p->next;
            }
        }
        current = current->next;
    }
}

int main(){
    ///测试方法1 使用set
    {
        Node *node1 = new Node(1);
        Node *node2 = new Node(1);
        Node *node3 = new Node(2);
        Node *node4 = new Node(3);
        Node *node5 = new Node(3);
        node1->next = node2;
        node2->next = node3;
        node3->next = node4;
        node4->next = node5;
        removeDuplicateNode2(node1);
        Node *p = node1;
        while(p != nullptr){
            cout<<p->val<<", ";
            p = p->next;
        }
    }
}