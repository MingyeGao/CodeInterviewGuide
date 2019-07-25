#include <assert.h>
#include <iostream>
#include <vector>
#include <stack>
#include <map>
#include <initializer_list>

using namespace std;

class Node{
public:
    int val;
    Node *lchild;
    Node *rchild;
    Node(int x = 0):val(x),lchild(nullptr),rchild(nullptr){}
};


Node* maxTree(vector<int> &input){
    stack<int> left2right, right2left;
    map<int, Node*> mapValueNode;
    vector<int> maxValueFromLeftToRight(input.size(), 0), maxValueFromRightToLeft(input.size(), 0);
    Node *root;

    for(int i = 0; i < input.size(); ++i){
        Node *newNode = new Node(input[i]);
        mapValueNode[input[i]] = newNode;
    }
    
    
    for(int i = 0; i < input.size(); ++i){
        int j = input.size() - 1 - i;
        
        while(!left2right.empty() && left2right.top() < input[i]){
            left2right.pop();
        }

        while(!right2left.empty() &&  right2left.top() < input[j]){
            right2left.pop();
        }

        
        maxValueFromLeftToRight[i] = (left2right.empty())?input[i]:left2right.top();
        maxValueFromRightToLeft[j] = (right2left.empty())?input[j]:right2left.top();

        left2right.push(input[i]);
        right2left.push(input[j]);
    }

    for(int i = 0; i < input.size(); ++i){
        if(maxValueFromLeftToRight[i] == maxValueFromRightToLeft[i]){
            root = mapValueNode[input[i]];
            continue;
        }

        Node *curNode = mapValueNode[input[i]];
        Node *p;
        if(maxValueFromLeftToRight[i] == input[i]){
            p = mapValueNode[maxValueFromRightToLeft[i]];
        }
        else if(maxValueFromRightToLeft[i] == input[i]){
            p = mapValueNode[maxValueFromLeftToRight[i]];
        }
        else{
            p = maxValueFromLeftToRight[i] < maxValueFromRightToLeft[i]?
                mapValueNode[maxValueFromLeftToRight[i]]:
                mapValueNode[maxValueFromRightToLeft[i]];
        }
        
        assert(p->lchild == nullptr || p->rchild == nullptr);
        if(p->lchild == nullptr){
            p->lchild = curNode;
        }
        else{
            p->rchild = curNode;
        }
    }

    return root;

}

void PreOrder(Node *node){
    if(node == nullptr) return;
    cout<<node->val;
    PreOrder(node->lchild);
    PreOrder(node->rchild);
}

int main(){
    vector<int> input({3,4,5,1,2});
    Node *root = maxTree(input);
    PreOrder(root);
}
