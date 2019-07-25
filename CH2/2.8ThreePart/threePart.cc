///将一个链表，按照一个输入值划分为三部分
///每一部分的值分别大于输入值，等于输入值，小于输入值

#include <iostream>
#include <vector>
#include <initializer_list>

using namespace std;

class Node{
public:
    int val;
    Node *next;
    Node(int x = 0):val(x), next(nullptr){}
};

Node *threePart(Node *list, int val){
    Node bigHead, *bigTail = &bigHead;
    Node middleHead, *middleTail = &middleHead;
    Node littleHead, *littleTail = &littleHead;

    Node *current = list;
    while(current != nullptr){
        Node *tmp = current->next;
        current->next = nullptr;
        if(current->val > val){
            bigTail->next = current;
            bigTail = current;
        }
        else if(current->val == val){
            middleTail->next = current;
            middleTail = current;
        }
        else{
            littleTail->next = current;
            littleTail = current;
        }
        current = tmp;
    }

    Node *currentTail = bigTail;
    if(&middleHead != middleTail){
        currentTail->next = middleHead.next;
        currentTail = middleTail;
    }

    if(&littleHead != littleTail){
        currentTail->next = littleHead.next;
    }

    return bigHead.next;
}

Node *generateList(vector<int> &input){
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
    vector<int> input({7, 9, 1, 8, 5, 2, 5});
    Node *list = generateList(input);
    Node *ret = threePart(list, 5);

    Node *current = ret;
    while(current != nullptr){
        cout<<current->val<<", ";
        current = current->next;
    }

}