#include <iostream>

using namespace std;

class Node{
public:
    int val;
    Node *next;
    Node(int x = 0):val(x), next(nullptr){};
};

Node *reverseNode(Node *list){
    Node head;
    Node *currentNode = list;
    while(currentNode != nullptr){
        Node *tmp = currentNode->next;
        currentNode->next = head.next;
        head.next = currentNode;
        currentNode = tmp;
    }

    return head.next;
}

Node *addTwoList(Node *list1, Node *list2){
    list1 = reverseNode(list1);
    list2 = reverseNode(list2);
    Node *p1 = list1, *p2 = list2;
    Node retNode;

    int  carry = 0;
    while(p1 != nullptr || p2 != nullptr || carry != 0){
        if(p1 == nullptr && p2 == nullptr){
            Node *newNode = new Node(1);
            newNode->next = retNode.next;
            retNode.next = newNode;
            carry = 0;
            break;
        }

        int newValue;
        if(p1 == nullptr){
            newValue = p2->val + carry;
            p2 = p2->next;
        }
        else if(p2 == nullptr){
            newValue = p1->val + carry;
            p1 = p1->next;
        }
        else{
            newValue = p1->val + p2->val + carry;
            p1 = p1->next;
            p2 = p2->next;
        }

        int bit = newValue%10;
        carry = newValue/10;
        Node *newNode = new Node(bit);
        newNode->next = retNode.next;
        retNode.next = newNode;
        
    }

    reverseNode(list1);
    reverseNode(list2);

    return retNode.next;
}

Node *generateNode(int x){
    Node *head = new Node();
    while(x != 0){
        int val = x%10;
        Node *newNode = new Node(val);
        newNode->next = head->next;
        head->next = newNode;
        x /= 10;
    }

    return head->next;
}

int main(){
    Node *input1 = generateNode(500);
    Node *input2 = generateNode(500);
    Node *ret = addTwoList(input1, input2);

    Node *current = ret;
    while(current != nullptr){
        cout<<current->val<<", ";
        current = current->next;
    }
}
