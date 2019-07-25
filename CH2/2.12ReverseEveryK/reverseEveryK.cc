#include <iostream>

using namespace std;

class Node{
public:
    int val;
    Node *next;
    Node(int x = 0):val(x), next(nullptr){};
};

Node *reverseEveryK(Node *list, int k){
    if(k < 2) return list;
    Node dummyHead;
    //dummyHead.next = list;
    Node *prev = &dummyHead;
    Node *front = list, *end, *back;
    Node *current = list;
    int count = 0;
    while(current != nullptr){
        ++count;
        Node *nextNode = current->next;
        if(count == k){
            end = current;
            back = current->next;
            Node *reverseP = front;
            Node *newPrev = reverseP;
            while(reverseP != back){
                Node *tmp = reverseP->next;
                reverseP->next = prev->next;
                prev->next = reverseP;
                reverseP = tmp;
            }

            prev = newPrev;
            front = reverseP;
            count = 0;

        }
        current = nextNode;
    }
    if(count != 0){
        prev->next = front;
    }
    return dummyHead.next;
}

Node *generateList(int length){
    Node dummyHead;
    Node *current = &dummyHead;
    for(int i = 1; i <=length; ++i){
        Node *newNode = new Node(i);
        current->next = newNode;
        current = newNode;
    }

    return dummyHead.next;
}

Node *display(Node *list){
    Node *current = list;
    while(current != nullptr){
        cout<<current->val<<", ";
        current = current->next;
    }
    cout<<endl;
}

int main(){
    Node *list = generateList(8);
    Node *ret = reverseEveryK(list, 3);
    display(ret);
}

