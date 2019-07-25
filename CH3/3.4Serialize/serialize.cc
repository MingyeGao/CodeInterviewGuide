///二叉树的序列化和反序列化
#include <iostream>
#include <string>
#include <queue>
#include <sstream>

using namespace std;

struct Node{
    int val;
    Node *lchild;
    Node *rchild;
    Node(int x = 0):val(x), lchild(nullptr), rchild(nullptr){};
};

Node *testCase1(){
    Node *node1 = new Node(1);
    Node *node2 = new Node(2);
    Node *node3 = new Node(3);
    Node *node4 = new Node(4);
    Node *node5 = new Node(5);
    node1->lchild = node2;
    node1->rchild = node3;
    node2->lchild = node4;
    node3->rchild = node5;
    return node1;
}

string serialize(Node *node){
    if(!node) return string("");
    ostringstream ret;
    int levelNum = 1;
    int flag = true;
    queue<Node*> q;
    q.push(node);
    while(flag){
        flag = false;
        for(int i = 0; i < levelNum; ++i){
            Node *n = q.front();
            if(!n){
                ret << "#!";
                q.pop();
                q.push(nullptr);
                q.push(nullptr);
            }
            else{
                ret << n->val << "!";
                q.pop();
                if(n->lchild || n->rchild) flag = true;
                q.push(n->lchild);
                q.push(n->rchild); 
            }
        }
        levelNum *= 2;
    }
    
    return ret.str();
}

int str2int(string s){
    int ret = 0;
    for(int i = 0; i < s.size(); ++i){
        ret *= 10;
        ret += s[i] - '0';
    }
    return ret;
}

void spiltString(string s, char c, vector<string> &result){
    int from = 0;
    int to;
    to = s.find(c, from);
    while(from < s.size() && to != string::npos){
        string tmp = s.substr(from, to - 1 - from + 1);
        result.push_back(tmp);
        from = to + 1;
        to = s.find(c, to + 1);
    }
}

Node *deserailize(string s){
    if(s.size() == 0) return nullptr;
    queue<Node*> q;
    vector<string> nodeInString;
    spiltString(s, '!', nodeInString);
    int val = str2int(nodeInString[0]);
    Node *root = new Node(val);
    q.push(root);
    int p = 1;
    while(p < nodeInString.size()){
        Node *current = q.front();
        q.pop();
        if(!current){
            q.push(nullptr);
            q.push(nullptr);
            p += 2;
            continue;
        }
        Node *lchild, *rchild;
        if(nodeInString[p] == "#"){
            lchild = nullptr;
        }
        else{
            lchild = new Node(str2int(nodeInString[p]));
        }

        if(nodeInString[p+1] == "#"){
            rchild = nullptr;
        }
        else{
            rchild = new Node(str2int(nodeInString[p+1]));
        }
        current->lchild = lchild;
        current->rchild = rchild;
        q.push(lchild);
        q.push(rchild);
        p += 2;

    }

    return root;
}

void preOrder(Node *node){
    if(node == nullptr) return;
    cout<<node->val<<", ";
    preOrder(node->lchild);
    preOrder(node->rchild);
}

int main(){
    Node *tree = testCase1();
    string ret = serialize(tree);
    cout<<ret<<endl;

    Node *newTree = deserailize(ret);
    preOrder(newTree);
    cout<<endl;
}