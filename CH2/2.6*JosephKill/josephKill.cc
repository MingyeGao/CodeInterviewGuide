#include <iostream>

using namespace std;

class Node{
public:
    int val;
    Node* next;
    Node(int x = 0):val(x), next(nullptr){}
};

Node *generateList(int length){
    Node pseudoHead;
    Node *current = &pseudoHead;
    for(int i = 0; i < length;++i){
        Node *newNode = new Node(i);
        current->next = newNode;
        current = newNode;
    }

    current->next =  pseudoHead.next;
    return pseudoHead.next;
}

int getLiveIndex(int currentPeopleNum, int circleNum);

Node *josephKill(Node *head, int m){
    if(head == nullptr || head->next == head)
        return head;

    int listSize = 1;
    Node *current = head->next;
    while(current != head){
        current = current->next;
        ++listSize;
    }

    int aliveIndex = getLiveIndex(listSize, m);
    current = head;
    while(--aliveIndex != 0){
        current = current->next;
    }

    current->next = current;
    return current;
}


int getLiveIndex(int currentPeopleNum, int circleNum){
    if(currentPeopleNum == 1){
        return 1;
    }
    else{
        int ret = ((getLiveIndex(currentPeopleNum-1, circleNum) + circleNum - 1)%currentPeopleNum)+1;
        //int ret = getLiveIndex(currentPeopleNum - 1, m);
        //ret = ret
        return ret;
    }


}

int main(){
    Node *list = generateList(41);
    Node *ret = josephKill(list, 3);
    cout<<ret->val<<endl;
}