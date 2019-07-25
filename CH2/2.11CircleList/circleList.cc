#include <assert.h>
#include <iostream>

using namespace std;

class Node{
public:
    int val;
    Node *next;
    Node(int x = 0):val(x), next(nullptr){};
};

Node* getLoopStartNode(Node *list){
    if(list == nullptr) return nullptr;
    Node *p1 = list, *p2 = list;

    while(p2->next != nullptr && p2->next->next != nullptr){
        p2 = p2->next->next;
        p1 = p1->next;

        if(p1 == p2){
            break;
        }
    }

    if(p2->next == nullptr || p2->next->next == nullptr){
        return nullptr;
    }

    p2 = list;
    while(p1 != p2){
        p1 = p1->next;
        p2 = p2->next;
    }

    return p2;
}

//判断两个无环链表是否有公共部分
Node *twoNoCirCleLists(Node *list1, Node *list2){
    Node *p1 = list1, *p2 = list2;
    int size1 = 0, size2 = 0;
    while(p1 != nullptr){
        ++size1;
        p1 = p1->next;
    }
    while(p2 != nullptr){
        ++size2;
        p2 = p2->next;
    }

    Node *p3, *p4;
    int sizeDiff;
    if(size1 > size2){
        p3 = list1;
        p4 = list2;
        sizeDiff = size1 - size2;
    }
    else{
        p3 = list2;
        p4 = list1;
        sizeDiff = size2 - size1;
    }

    for(int i = 0; i < sizeDiff; ++i){
        p3 = p3->next;
    }
    Node *ret = nullptr;
    while(p3 != nullptr){
        if(p3 == p4){
            ret = p3;
            break;
        }
        p3 = p3->next;
        p4 = p4->next;
    }

    return ret;
}

Node *twoCircleList(Node *list1, Node *list2){
    Node *circleEntry1 = getLoopStartNode(list1);
    Node *circleEntry2 = getLoopStartNode(list2);

    if(circleEntry1 == nullptr || circleEntry2 == nullptr){
        return nullptr;
    }

    if(circleEntry1 == circleEntry2) return circleEntry1;

    Node *p1 = circleEntry1->next;
    while(p1 != circleEntry2 && p1 != circleEntry1){
        p1 = p1->next;
    }
    if(p1 == circleEntry1){
        return nullptr;
    }
    else{
        return p1;
    }
}

Node *generateList(int length){
    Node head;
    Node *current =&head;
    for(int i = 1; i <=length; ++i){
        Node *newNode = new Node(i);
        current->next = newNode;
        current = newNode;
    }

    return head.next;
}


int main(){
    ///测试有环链表的入口
    {
        Node *list = generateList(7);
        Node *tail = list;
        while(tail->next != nullptr){
            tail = tail->next;
        }

        tail->next = list->next->next->next;

        Node *circleEntry = getLoopStartNode(list);
        cout<<circleEntry->val<<endl;
    }
    ///测试两个无环链表的公共节点
    {
        Node *commonPart = generateList(5);
        Node *list1 = generateList(2);
        Node *list2 = generateList(4);
        Node *p = list1;
        while(p->next != nullptr){
            p = p->next;
        }
        p->next = commonPart;

        p = list2;
        while(p->next != nullptr){
            p = p->next;
        }
        p->next = commonPart;
        Node *ret = twoNoCirCleLists(list1, list2);
        assert(ret == commonPart);
    }
    ///测试两个有环链表的公共结点
    {
        Node *list1 = generateList(5);
        Node *list2 = generateList(7);
        Node *tail = list1;
        while(tail->next != nullptr){
            tail = tail->next;
        }
        tail->next = list1->next->next;

        tail = list2;
        while(tail->next != nullptr){
            tail = tail->next;
        }
        tail->next = list2->next->next->next->next;

        Node *ret = twoCircleList(list1, list2);
        assert(!ret);

        ret = twoCircleList(list2, list2->next);
        cout<<ret->val<<endl;
    }
}