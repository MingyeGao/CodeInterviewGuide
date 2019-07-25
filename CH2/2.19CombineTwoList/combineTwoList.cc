#include <iostream>
#include <vector>
using namespace std;

class Node{
public:
    int val;
    Node *next;
    Node(int x = 0):val(x), next(nullptr){}
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

Node *mergeTwoList(Node *list1, Node *list2){
    Node dummyHead;
    Node *current = &dummyHead;
    Node *p1 = list1, *p2 = list2;
    while(p1 || p2){
        if(!p1){
            current->next = p2;
            current = p2;
            //p2 = p2->next;
            break;
        }
        if(!p2){
            current->next = p1;
            current = p1;
            break;
        }
        if(p1->val < p2->val){
            current->next = p1;
            current = p1;
            p1 = p1->next;
        }
        else{
            current->next = p2;
            current = p2;
            p2 = p2->next;
        }
    }

    return dummyHead.next;
}

void display(Node *list){
    Node *current = list;
    while(current){
        cout<<current->val<<", ";
        current = current->next;
    }

}

int main(){
    vector<int> input1({1, 4, 7, 8, 9 ,10});
    vector<int> input2({2, 5, 8, 9, 15, 16, 17, 18});
    Node *list1 = vector2list(input1);
    Node *list2 = vector2list(input2);
    Node *ret = mergeTwoList(list1, list2);
    display(ret);
}